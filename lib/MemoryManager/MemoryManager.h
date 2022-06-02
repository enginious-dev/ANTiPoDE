/**
 *
 * MemoryManager
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef MEMORYMANAGER_H
#define	MEMORYMANAGER_H

#include <Types.h>
#include <MemoryManagerException.h>

namespace Antipode {

    class MemoryManager {
    public:
        MemoryManager() = delete;
        MemoryManager(MemoryManager const&) = delete;
        void operator=(MemoryManager const&) = delete;

        template <class T> static bool safeAlloc(T ** ptr, const uint32 & num = 1);

        /**
         * Initializes the heap based on size (must be at least 4 bytes)
         * @param size the requested heap size 
         * @throws MemoryManagerException if minimum heap size is violated or std::malloc fails
         */
        static void init(size_t heapSize);
        /**
         * Get the current available space
         * @return the current available space
         */
        static size_t getHeapFree();
        /**
         * Get the total space
         * @return the total space
         */
        static size_t getHeapSize();

        /**
         * Tries to allocate a block of the required size (must be greater than zero), if
         * the block not exists returns NULL as standard c
         * @param size the required size 
         * @return a pointer to the allocated block if found else NULL as standard c
         * @throws MemoryManagerException if heap is not initialized or an invalid size is passed
         */
        static void * malloc(size_t size);
        /**
         * Release the block pointed from ptr
         * @param ptr a pointer to the block
         * @throws MemoryManagerException if heap is not initialized or an invalid pointer is passed
         */
        static void free(void * address);
    private:
        /**
         * Check if the heap is initialized
         * @return true if yes otherwise false
         */
        static bool isInitialized();
        /**
         * Check if there is a block of the required size (must be greater than zero), 
         * if the block not exists returns false otherwise true
         * @param size the required size 
         * @return true if the block exists otherwise false
         * @throws MemoryManagerException if heap is not initialized or an invalid size is passed
         */
        static bool checkSpace(size_t size);

        class Segment;

        static Segment * heapHead;
        static size_t heapSize;
        static size_t heapBusy;
    };

    template <class T> bool MemoryManager::safeAlloc(T ** ptr, const uint32 & num) {
        if (checkSpace(num * sizeof (T))) {
            *ptr = (num == 1 ? new T() : new T[num]);
            return true;
        }
        return false;
    }
}

#endif	/* MEMORYMANAGER_H */

