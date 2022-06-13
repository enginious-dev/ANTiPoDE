/**
 *
 * CoreTimer
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#include "CoreTimer.h"

#define US_DIVISOR  0x000F4240 // 1E+6
#define MS_DIVISOR  0x000003E8 // 1E+3

Antipode::uint32 Antipode::CoreTimer::CoreTimer::systemClockFrequency(0);
Antipode::uint32 Antipode::CoreTimer::CoreTimer::microSecondsScale(0);
Antipode::uint32 Antipode::CoreTimer::CoreTimer::milliSecondsScale(0);

Antipode::CoreTimer::CoreTimer(const uint8 ifsVecIndex, const uint8 iecVecIndex, const uint8 ipcVecIndex, const uint32 ifsMask, const uint32 iecMask, const uint32 ipPosition, const uint32 ispPosition) : InterruptSource(ifsVecIndex, iecVecIndex, ipcVecIndex, ifsMask, iecMask, ipPosition, ispPosition) {
    // Very trivial...
}

void Antipode::CoreTimer::setSystemClockFrequency(uint32 systemClockFrequency) {
    // store divided by 2 for performance
    this->systemClockFrequency = (systemClockFrequency >> 1);
    this->microSecondsScale = this->systemClockFrequency / US_DIVISOR;
    this->milliSecondsScale = this->systemClockFrequency / MS_DIVISOR;
}

Antipode::uint32 Antipode::CoreTimer::getSystemClockFrequency() {
    // Very trivial...
    return systemClockFrequency << 1;
}

Antipode::uint32 Antipode::CoreTimer::toTicks(volatile uint32 value, TimeUnit timeUnit) {
    // Very trivial...
    switch (timeUnit) {
        case MICROSECONDS:
            return microSecondsScale * value;
        case MILLISECONDS:
            return milliSecondsScale * value;
        case SECONDS:
            return systemClockFrequency * value;
        default:
            throw TimerException(TIMER_ERROR_INVALID_TIMEUNIT_CODE, TIMER_ERROR_INVALID_TIMEUNIT_MESSAGE);
    }
}

void Antipode::CoreTimer::open(volatile uint32 ticks) {
    // Clear the count reg
    asm volatile("mtc0   $0, $9");
    // Set up the period in the compare reg
    asm volatile("mtc0   %0, $11" : "+r"(ticks));
}

void Antipode::CoreTimer::open(volatile uint32 value, TimeUnit timeUnit) {
    // Very trivial...
    open(toTicks(value, timeUnit));
}

void Antipode::CoreTimer::load(volatile uint32 ticks) {
    unsigned int old_ticks;
    // Get the old compare time
    asm volatile("mfc0   %0,$11" : "=r"(old_ticks));
    ticks += old_ticks;
    // Set up the period in the compare reg
    asm volatile("mtc0   %0,$11" : "+r"(ticks));
}

void Antipode::CoreTimer::load(volatile uint32 value, TimeUnit timeUnit) {
    // Very trivial...
    load(toTicks(value, timeUnit));
}
