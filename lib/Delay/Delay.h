/**
 *
 * Delay
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef DELAY_H
#define	DELAY_H
#include <SystemConfig.h>

#ifndef SYS_CLOCK
#error "SYS_CLOCK must be defined"
#endif	/* SYS_CLOCK */

#define milliSeconds(value) (SYS_CLOCK / 0x000003E8 * value)
#define microSeconds(value) (SYS_CLOCK / 0x000F4240 * value)

namespace Antipode {

    extern "C" {
        /**
         * For a deterministic behavior, call this method after having defined 
         * the SYS_CLOCK macro in your SystemConfig.h and through the 
         * milliSeconds and microSeconds macros depending on whether delay you 
         * want. Be careful not to cause overflow!
         * @param cycles the cycles obtained with the use of macros
         */
        extern void delay(int cycles);
    }
}
#endif	/* DELAY_H */

