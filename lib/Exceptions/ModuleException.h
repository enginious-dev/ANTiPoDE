/**
 *
 * ModuleException
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef MODULEEXCEPTION_H
#define	MODULEEXCEPTION_H

#include "AntipodeException.h"

namespace Antipode {

    class ModuleException : public AntipodeException {
    public:
        ModuleException(int code, char* message);
    };
}

#endif	/* MODULEEXCEPTION_H */

