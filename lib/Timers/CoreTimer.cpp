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

Antipode::CoreTimer::CoreTimer(const uint8 ifsVecIndex, const uint8 iecVecIndex, const uint8 ipcVecIndex, const uint32 ifsMask, const uint32 iecMask, const uint32 ipPosition, const uint32 ispPosition) : InterruptSource(ifsVecIndex, iecVecIndex, ipcVecIndex, ifsMask, iecMask, ipPosition, ispPosition){
    // Very trivial...
}

void Antipode::CoreTimer::setSystemClockFrequency(uint32 systemClockFrequency) {
    // store divided by 2 for performance
    this->systemClockFrequency = (systemClockFrequency >> 1);
}

Antipode::uint32 Antipode::CoreTimer::getSystemClockFrequency() {
    // Very trivial...
    return systemClockFrequency << 1;
}

Antipode::uint32 Antipode::CoreTimer::toTicks(volatile uint32 value, TimeUnit timeUnit) {
    // Very trivial...
    switch (timeUnit) {
        case MICROSECONDS:
            return systemClockFrequency / US_DIVISOR * value;
        case MILLISECONDS:
            return systemClockFrequency / MS_DIVISOR * value;
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

void Antipode::CoreTimer::wait(volatile uint32 ticks) {

    uint32 current;
    // Get the count reg
    asm volatile("mfc0   %0, $9" : "=r"(current));
    // Set up target (may overflow!)
    ticks += current;
    // Wait until a possible overflow occurs... Imagine that cpu has 8-bit 
    // registers for simplicity ... if you have to wait 10 cycles and the 
    // register contains a value to which by adding 10 there is no overflow 
    // there are no problems ... but if the sum overflows you must first wait 
    // for this to occur... 
    while (ticks < current) {
        // Get the count reg
        asm volatile("mfc0   %0, $9" : "=r"(current));
    }
    while (ticks > current) {
        // Get the count reg
        asm volatile("mfc0   %0, $9" : "=r"(current));
    }
}

void Antipode::CoreTimer::wait(volatile uint32 value, TimeUnit timeUnit) {
    // Very trivial...
    wait(toTicks(value, timeUnit));
}
