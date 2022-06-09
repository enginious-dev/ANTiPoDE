/**
 *
 * CoreTimer
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef CORETIMER_H
#define	CORETIMER_H

#include <Types.h>
#include <InterruptSource.h>
#include <TimerException.h>

namespace Antipode {

    class CoreTimer : public InterruptSource {
    public:
        /**
         * Builds a core timer
         * @param ifsVecIndex interrupt flags vector index
         * @param iecVecIndex interrupt enable vector index
         * @param ipcVecIndex interrupt priority vector index
         * @param ifsMask interrupt flag mask
         * @param iecMask interrupt enable mask
         * @param ipPosition interrupt priority position
         * @param ispPosition interrupt sub-priority position
         */
        CoreTimer(const uint8 ifsVecIndex, const uint8 iecVecIndex, const uint8 ipcVecIndex, const uint32 ifsMask, const uint32 iecMask, const uint32 ipPosition, const uint32 ispPosition);

        /**
         * Sets the system clock frequency for calculation, this metod should
         * be called during device initialization.
         * @param systemClockFrequency the current system clock frequency
         */
        void setSystemClockFrequency(uint32 systemClockFrequency);

        /**
         * Get the system clock frequency
         * @param systemClockFrequency the system clock frequency
         */
        uint32 getSystemClockFrequency();

        /**
         * Converts specified value in clock cycles
         * @param value the value
         * @param timeUnit the time unit 
         * @return the value in clock cycles
         * @throws TimerException if an invalid TimeUnit is passed as parameter
         */
        uint32 toTicks(volatile uint32 value, TimeUnit timeUnit);

        /**
         * Clear the count register in CP0 and preloads 'ticks' in compare CP0
         * register
         * @param ticks the period
         */
        void open(volatile uint32 ticks);

        /**
         * Clear the count register in CP0 and preloads 'ticks' in compare CP0
         * register calculating from 'value' and 'timeUnit'
         * @param value the value
         * @param timeUnit the time unit 
         * @throws TimerException if an invalid TimeUnit is passed as parameter
         */
        void open(volatile uint32 value, TimeUnit timeUnit);

        /**
         * Preloads 'ticks' in compare CP0 register
         * @param ticks the period
         */
        void load(volatile uint32 ticks);

        /**
         * Preloads 'ticks' in compare CP0 register calculating from 'value' and
         * 'timeUnit'
         * @param value the value
         * @param timeUnit the time unit 
         * @throws TimerException if an invalid TimeUnit is passed as parameter
         */
        void load(volatile uint32 value, TimeUnit timeUnit);

        /**
         * Wait until 'ticks' have passed
         * @param ticks the period
         */
        void wait(volatile uint32 ticks);

        /**
         * Wait until 'ticks' have passed calculating from 'value' and 
         * 'timeUnit'
         * @param value the value
         * @param timeUnit the time unit 
         * @throws TimerException if an invalid TimeUnit is passed as parameter
         */
        void wait(volatile uint32 value, TimeUnit timeUnit);
    private:
        static uint32 systemClockFrequency;
    };
}

#endif	/* CORETIMER_H */

