/**
 *
 * MemoryManager
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#include "MemoryManager.h"
#include <cstring>
#include <stdlib.h>

const size_t COMPILER_OFFSET = 8;

/**
 * 
 * The class Segment that represents a block of memory
 */
class Antipode::MemoryManager::Segment {
public:
    void * data();
    Segment * vNext();
    // The block status (1 busy - 0 free)
    uint32 status : 0x01;
    // The block size
    uint32 size : 0x1F;
    // A pointer to the next segment
    Segment * next;
};

/**
 * 
 * Returns the user memory block
 * @return the user memory block for this segment
 */
void * Antipode::MemoryManager::Segment::data() {
    // Adding 1 to the address of 'next', which is of type void * (4 bytes),
    // the address is moved 4 bytes in memory, then the method returns this 
    // address as void *
    return (reinterpret_cast<void *> (&next + 1));
}

/**
 * 
 * Calculates the address at which the next block should hypothetically be
 * starting from 'data()' (which returns the data block) adding an offset of 
 * 'size' bytes
 * @return 
 */
Antipode::MemoryManager::Segment * Antipode::MemoryManager::Segment::vNext() {
    return (reinterpret_cast<Segment *> (reinterpret_cast<uint32> (data()) + size));
}

/**
 * Static fields initialization
 */
Antipode::MemoryManager::Segment * Antipode::MemoryManager::heapHead(NULL);
size_t Antipode::MemoryManager::heapSize(0);
size_t Antipode::MemoryManager::heapBusy(0);

void Antipode::MemoryManager::init(size_t size) {

    // If 'size' is not large enough to allow allocation of at least one integer
    // throws an excption
    if (size < COMPILER_OFFSET + sizeof (Segment) + sizeof (int)) {
        throw MemoryManagerException(MEMORY_ERROR_MINIMUM_HEAP_SIZE_VIOLATED_CODE, MEMORY_ERROR_MINIMUM_HEAP_SIZE_VIOLATED_MESSAGE);
    }
    // Subtract the compiler overhead from the 'size' parameter
    size -= COMPILER_OFFSET;
    // Allocating the heap
    heapHead = static_cast<Segment *> (std::malloc(size));
    // If null allocation was failed so throws an excption
    if (!heapHead) {
        throw MemoryManagerException(MEMORY_ERROR_NOT_ENOUGH_SPACE_TO_INITIALIZE_HEAP_CODE, MEMORY_ERROR_NOT_ENOUGH_SPACE_TO_INITIALIZE_HEAP_MESSAGE);
    }
    // Set the size of the real heap
    heapSize = size;
    // Clean the heap
    memset(heapHead, 0x00, size);
    // Set as free
    heapHead->status = 0;
    // Set the segmente size
    heapHead->size = heapSize - sizeof (Segment);
    // Update the busy space
    heapBusy += sizeof (Segment);
    // Set the pointer to the next block to NULL (cutting the linked-list)
    heapHead->next = NULL;
}

size_t Antipode::MemoryManager::getHeapFree() {
    // Very trivial...
    return heapSize - heapBusy;
}

size_t Antipode::MemoryManager::getHeapSize() {
    // Very trivial...
    return heapSize;
}

void * Antipode::MemoryManager::malloc(size_t size) {
    Segment * nav = NULL;
    Segment * seg = NULL;
    size_t max = 0;
    bool found = false;

    // If heap is not initialized throws exception
    if (!isInitialized()) {
        throw MemoryManagerException(MEMORY_ERROR_HEAP_NOT_INITIALIZED_CODE, MEMORY_ERROR_HEAP_NOT_INITIALIZED_MESSAGE);
    }

    // If invalid size is passed as parameter throws exception
    if (size <= 0) {
        throw MemoryManagerException(MEMORY_ERROR_INVALID_SIZE_PARAMETER_CODE, MEMORY_ERROR_INVALID_SIZE_PARAMETER_MESSAGE);
    }

    // If the requested size does not reach 4 bytes (32-bit addressing)
    if (size % 4) {
        // Align the block to the nearest multiple of 4 bytes
        size += (4 - (size % 4));
    }

    // Start iterating all segment in list
    nav = heapHead;

    while (nav) {
        // If a free block is found
        if (nav->status == 0) {
            // If size matches
            if (nav->size == size) {
                // Set status as busy
                nav->status = 1;
                // Increment busy space
                heapBusy += size;
                // Return the block
                return nav->data();
                // If, on the other hand, the block has a size greater than that 
                // requested, search the maximum of the free blocks, this avoid
                // iterate the list twice
            } else if (nav->size > size && nav->size > max) {
                // If a valid block found set the flag to true
                found = true;
                // Update temporary max value
                max = nav->size;
                // Save the valid block
                seg = nav;
            }
        }
        // Continue iteration
        nav = nav->next;
    }

    // At the end of the iteration, if the requested block exists, the 'found' 
    // flag will be true and the temporary pointer 'seg' will contain the 
    // address of the maximum, so
    if (found) {
        // Just for a matter of coherence work again with nav
        nav = seg;
        // Set the 'size' to the required one
        nav->size = size;
        // Set status as busy
        nav->status = 1;
        // Increment busy space
        heapBusy += size;
        // Set the next block by assigning the calculated address to seg
        seg = nav->vNext();
        // Set status as free
        seg->status = 0;
        // Set the pointer to the 'next' block as the 'next' of 'nav' (this 
        // address has not been changed)
        seg->next = nav->next;
        // Set the size of the new block
        seg->size = max - size - sizeof (Segment);
        // Increment busy space
        heapBusy += sizeof (Segment);
        // Set the 'next' of 'nav' (the allocated block) to the following 
        // linking again the list
        nav->next = seg;
        // Return the block
        return nav->data();
    }
    // If, on the other hand, the requested block does not exist, return NULL 
    // as standard c
    return NULL;
}

void Antipode::MemoryManager::free(void * ptr) {

    Segment * nav = NULL;
    Segment * pre = NULL;
    bool found = false;

    // If heap is not initialized throws exception
    if (!isInitialized()) {
        throw MemoryManagerException(MEMORY_ERROR_HEAP_NOT_INITIALIZED_CODE, MEMORY_ERROR_HEAP_NOT_INITIALIZED_MESSAGE);
    }

    // If invalid pointer is passed as parameter throws exception
    if (!ptr <= 0) {
        throw MemoryManagerException(MEMORY_ERROR_INVALID_POINTER_PARAMETER_CODE, MEMORY_ERROR_INVALID_POINTER_PARAMETER_MESSAGE);
    }

    // Start iterating all segment in list
    nav = heapHead;

    while (nav) {
        // If the address passed is a memory address that is in the heap 
        if (nav->data() == ptr) {
            // Set status as free
            nav->status = 0;
            // Increment free space
            heapBusy -= nav->size;
            // Clean the space
            memset(nav->data(), 0x00, nav->size);
            // Set the found flag
            found = true;
            // Stop the iteration
            break;
        }
        // Saving the current block as previous (needed for defragmentation)
        pre = nav;
        // Move on to the next block
        nav = nav->next;
    }

    // If the block was found defragment the memory by looking both previous and 
    // next blocks
    if (found) {
        // So if the previous block is not NULL (this means that there is 
        // something on the left) and also it is not occupied
        if (pre && pre->status == 0) {
            // Move the temporary pointer to the previous block
            nav = pre;
            // Recalculate the block size
            nav->size += sizeof (Segment) + nav->next->size;
            // Increment free space
            heapBusy -= sizeof (Segment);
            // Assign to the 'next' of 'nav' the 'next' of the deleted block
            nav->next = nav->next->next;
            // Clean the space
            memset(nav->data(), 0x00, nav->size);
        }
        // Now checks on the right: if this block is non-NULL and free join them
        if (nav->next && nav->next->status == 0) {
            // Set the size of the 'nav' by calculating the new one
            nav->size += sizeof (Segment) + nav->next->size;
            // Increment free space
            heapBusy -= sizeof (Segment);
            // Assign to the 'next' of 'nav' the 'next' 'next' of the this block
            nav->next = nav->next->next;
            // Clean the space
            memset(nav->data(), 0x00, nav->size);
        }
    }
}

bool Antipode::MemoryManager::isInitialized() {
    // Very trivial...
    return heapHead && heapSize;
}

bool Antipode::MemoryManager::checkSpace(size_t size) {
    Segment * nav = NULL;

    // If heap is not initialized throws exception
    if (!isInitialized()) {
        throw MemoryManagerException(MEMORY_ERROR_HEAP_NOT_INITIALIZED_CODE, MEMORY_ERROR_HEAP_NOT_INITIALIZED_MESSAGE);
    }

    // If invalid size is passed as parameter throws exception
    if (size <= 0) {
        throw MemoryManagerException(MEMORY_ERROR_INVALID_SIZE_PARAMETER_CODE, MEMORY_ERROR_INVALID_SIZE_PARAMETER_MESSAGE);
    }

    // If the requested size does not reach 4 bytes (32-bit addressing)
    if (size % 4) {
        // Align the block to the nearest multiple of 4 bytes
        size += (4 - (size % 4));
    }

    // Start iterating all segment in list
    nav = heapHead;

    while (nav) {

        // If a free block greater than or equal to the requested size exists
        if (nav->size >= size && !nav->status) {
            // Return true
            return true;
        }
        // Go to the next block
        nav = nav->next;
    }
    // Otherwise return false
    return false;
}

void * operator new(size_t size) {
    // Very trivial...
    return Antipode::MemoryManager::malloc(size);
}

void * operator new[](size_t size) {
    // Very trivial...
    return Antipode::MemoryManager::malloc(size);
}

void operator delete(void* addr) {
    // Very trivial...
    Antipode::MemoryManager::free(addr);
}

void operator delete[](void* addr) {
    Antipode::MemoryManager::free(addr);
}