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


#define TIMER_ERROR 0x03000000
#define TIMER_ERROR_INVALID_TIMEUNIT_CODE (TIMER_ERROR | 1)
#define TIMER_ERROR_INVALID_TIMEUNIT_MESSAGE ((char *) "invalid time unit")

namespace Antipode {

    class TimerException : public AntipodeException {
    public:
        TimerException(int code, char* message);
    };
}

#endif	/* TIMEREXCEPTION_H */