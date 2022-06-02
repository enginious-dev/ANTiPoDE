/**
 *
 * MemoryManagerException
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef MEMORYMANAGEREXCEPTION_H
#define	MEMORYMANAGEREXCEPTION_H

#include "AntipodeException.h"


#define MEMORY_ERROR 0x01000000
#define MEMORY_ERROR_MINIMUM_HEAP_SIZE_VIOLATED_CODE (MEMORY_ERROR | 1)
#define MEMORY_ERROR_MINIMUM_HEAP_SIZE_VIOLATED_MESSAGE ((char *) "minimum heap size violated")

#define MEMORY_ERROR_NOT_ENOUGH_SPACE_TO_INITIALIZE_HEAP_CODE (MEMORY_ERROR | 2)
#define MEMORY_ERROR_NOT_ENOUGH_SPACE_TO_INITIALIZE_HEAP_MESSAGE ((char *) "not enough space to initialize heap")

#define MEMORY_ERROR_HEAP_NOT_INITIALIZED_CODE (MEMORY_ERROR | 3)
#define MEMORY_ERROR_HEAP_NOT_INITIALIZED_MESSAGE ((char *) "heap not initialized")

#define MEMORY_ERROR_INVALID_SIZE_PARAMETER_CODE (MEMORY_ERROR | 4)
#define MEMORY_ERROR_INVALID_SIZE_PARAMETER_MESSAGE ((char *) "invalid size parameter")

#define MEMORY_ERROR_INVALID_POINTER_PARAMETER_CODE (MEMORY_ERROR | 5)
#define MEMORY_ERROR_INVALID_POINTER_PARAMETER_MESSAGE ((char *) "invalid pointer parameter")

namespace Antipode {

    class MemoryManagerException : public AntipodeException {
    public:
        MemoryManagerException(int code, char* message);
    };
}
#endif	/* MEMORYMANAGEREXCEPTION_H */

