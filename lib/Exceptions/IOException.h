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

namespace Antipode {

    class IOException : public AntipodeException {
    public:
        IOException(int code, char* message);
    };
}

#endif	/* IOEXCEPTION_H */

