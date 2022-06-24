/**
 *
 * ConfigController
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#include "ConfigController.h"

Antipode::ConfigController::ConfigController(volatile ConfigurationBitsRegister & reg, uint32 iolockMask, uint32 syskeyUnlockSequence[], uint8 syskeyUnlockSequenceSize, uint32 syskeyLockSequence[], uint8 syskeyLockSequenceSize, AbstractInterruptController * interruptController) : reg(reg), iolockMask(iolockMask), syskeyUnlockSequence(syskeyUnlockSequence), syskeyUnlockSequenceSize(syskeyUnlockSequenceSize), syskeyLockSequence(syskeyLockSequence), syskeyLockSequenceSize(syskeyLockSequenceSize), interruptController(interruptController) {
    // Very trivial...
}

void Antipode::ConfigController::unlockOscCon() volatile {
    // Disable global interrupt
    interruptController->disableGlobalInterrupt();
    // Set all required value in SYSKEY reg
    for (int i = 0; i < syskeyUnlockSequenceSize; i++) {
        reg.syskey.base = syskeyUnlockSequence[i];
    }
}

void Antipode::ConfigController::lockOscCon(bool enableGlobalInterrupt, bool multivectorMode) volatile {

    // Set all required value in SYSKEY reg
    for (int i = 0; i < syskeyLockSequenceSize; i++) {
        reg.syskey.base = syskeyLockSequence[i];
    }
    // Enable global interrupt (if requested)
    if (enableGlobalInterrupt) {
        interruptController->enableGlobalInterrupt(multivectorMode);
    }
}

void Antipode::ConfigController::clearIoLock() volatile {
    // Clear the iolock bit
    reg.cfgcon.base ^= iolockMask;
}

void Antipode::ConfigController::setIoLock() volatile {
    // Set the iolock bit
    reg.cfgcon.base |= iolockMask;
}