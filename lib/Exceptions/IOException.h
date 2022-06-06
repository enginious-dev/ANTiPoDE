/**
 *
 * IOException
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef IOEXCEPTION_H
#define	IOEXCEPTION_H

#include "AntipodeException.h"

#define IO_ERROR 0x02000000
#define IO_INVALID_BIT_PARAMETER_CODE (IO_ERROR | 1)
#define IO_INVALID_BIT_PARAMETER_MESSAGE ((char *) "invalid bit parameter")

namespace Antipode {

    class IOException : public AntipodeException {
    public:
        IOException(int code, char* message);
    };
}

#endif	/* IOEXCEPTION_H */

