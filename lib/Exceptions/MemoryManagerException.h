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

namespace Antipode {

    class MemoryManagerException : public AntipodeException {
    public:
        MemoryManagerException(int code, char* message);
    };
}
#endif	/* MEMORYMANAGEREXCEPTION_H */

