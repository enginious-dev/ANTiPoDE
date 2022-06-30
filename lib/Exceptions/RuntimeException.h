/**
 *
 * RuntimeException
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef RUNTIMEEXCEPTION_H
#define	RUNTIMEEXCEPTION_H

#include "AntipodeException.h"

namespace Antipode {

    class RuntimeException : public AntipodeException {
    public:
        RuntimeException(int code, char* message);
    };
}

#endif	/* RUNTIMEEXCEPTION_H */

