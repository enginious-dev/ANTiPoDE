/**
 *
 * ConfigController
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef CONFIGCONTROLLER_H
#define	CONFIGCONTROLLER_H

#include <Registers.h>
#include <AbstractInterruptController.h>

namespace Antipode {

    class ConfigController {
    public:


        /**
         * Builds a config controller 
         * @param reg the configuration bit register
         * @param iolockMask the IOLOCK bit mask
         * @param syskeyUnlockSequence the sequence that will be written in 
         *                             SYSKEY to unlock OSCCON
         * @param syskeyUnlockSequenceSize the number of values present in the
         *                                 'syskeyUnlockSequence' parameter
         * @param syskeyLockSequence the sequence that will be written in 
         *                           SYSKEY to lock OSCCON
         * @param syskeyLockSequenceSize the number of values present in the
         *                               'syskeyLockSequenceSize' parameter
         * @param interruptController the interrupt controller
         */
        ConfigController(volatile ConfigurationBitsRegister & reg, uint32 iolockMask, uint32 * syskeyUnlockSequence, uint8 syskeyUnlockSequenceSize, uint32 * syskeyLockSequence, uint8 syskeyLockSequenceSize, AbstractInterruptController * interruptController);

        /**
         * Unlocks OSCCON register
         */
        void unlockOscCon() volatile;

        /**
         * 
         * Locks OSCCON register
         * @param enableGlobalInterrupt if true enable global interrupt after 
         *                              the locking OSCCON
         * @param multivectorMode used only if 'enableGlobalInterrupt' is true 
         *                        enables (if true) the multivector mode
         */
        void lockOscCon(bool enableGlobalInterrupt = true, bool multivectorMode = true) volatile;

        /**
         * Clear the IOLOCK bit in CFGCON
         */
        void clearIoLock() volatile;

        /**
         * Set the IOLOCK bit in CFGCON
         */
        void setIoLock() volatile;
        
        /**
         * Initializes clocks
         */
        void init(uint32 systemClock, uint32 peripheralBusClock);
        
        /**
         * Returns the system clock
         * @return the system clock
         * @throws RuntimeException if called before init (framework not initialized)
         */
        uint32 getSystemClock() volatile;
        
        /**
         * Returns the peripheral bus clock
         * @return the peripheral bus clock
         * @throws RuntimeException if called before init (framework not initialized)
         */
        uint32 getPeripherlBusClock() volatile;

    private:
        volatile AbstractInterruptController * interruptController;
        volatile ConfigurationBitsRegister & reg;
        uint32 iolockMask;
        uint32 * syskeyUnlockSequence;
        uint8 syskeyUnlockSequenceSize;
        uint32 * syskeyLockSequence;
        uint8 syskeyLockSequenceSize;
        uint32 systemClock;
        uint32 peripheralBusClock;
        bool inizialized;
                

    };
}
#endif	/* CONFIGCONTROLLER_H */

