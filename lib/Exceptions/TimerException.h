/**
 *
 * TimerException
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef TIMEREXCEPTION_H
#define	TIMEREXCEPTION_H

#include "AntipodeException.h"

namespace Antipode {

    class TimerException : public AntipodeException {
    public:
        TimerException(int code, char* message);
    };
}

#endif	/* TIMEREXCEPTION_H */