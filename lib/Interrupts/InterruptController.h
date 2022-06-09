/**
 *
 * InterruptController
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef INTERRUPTCONTROLLER_H
#define	INTERRUPTCONTROLLER_H

#include <Registers.h>
#include <InterruptSource.h>

namespace Antipode {

    template <uint32 IFSVEC_MAX, uint32 IECVEC_MAX, uint32 IPCVEC_MAX> class InterruptController {
    public:

        /**
         * Builds an interrupt controller an interrupt register
         * @param reg the interrupt register
         * @param mvecMask the multivector bit mask
         */
        InterruptController(volatile InterruptRegister<IFSVEC_MAX, IECVEC_MAX, IPCVEC_MAX> & reg, uint32 mvecMask) : reg(reg), mvecMask(mvecMask) {
        }

        /**
         * Enables the global interrupt
         * @param multiVectorModeEnabled multi Vector Mode Enabling flag.
         */
        void enableGlobalInterrupt(bool multiVectorModeEnabled = true) {
            reg.intcon.set = mvecMask;
            asm volatile("ei");
        }

        /**
         * Disables the global interrupt
         */
        void disableGlobalInterrupt() {
            asm volatile("di");
        }

        /**
         * Enables the interrupt with given priority and subPriority for the
         * specified source
         * @param source the interrupt source
         * @param priority the interrupt priority
         * @param subPriority the interrupt sub-priority
         */
        void enableInterrupt(InterruptSource & source, const InterruptPriority priority, const InterruptSubPriority subPriority = Isp0) {
            // Clear the interrupt flag
            reg.ifs[source.ifsVecIndex].clear = source.ifsMask;
            // Setpriority and sub-priority
            reg.ipc[source.ipcVecIndex].set = ((priority << source.ipPosition) | (subPriority << source.ispPosition));
            // Enable interrupt
            reg.iec[source.iecVecIndex].set = source.iecMask;
        }

        /**
         * Disables the interrupt for the specified source
         * @param source the interrupt source
         */
        void disableInterrupt(InterruptSource & source) volatile {
            // Disable interrupt
            reg.iec[source.iecVecIndex].clear = source.iecMask;
        }

        /**
         * Checks if an interrupt has occurred for the specified source
         * @param source the interrupt source
         * @return true if and interrupt event occured, otherwise false
         */
        bool hasInterruptOccurred(InterruptSource & source) volatile {
            // Very trivial...
            return RegisterUtils::areHi(reg.ifs[source.ifsVecIndex], source.ifsMask);
        }

        /**
         * Clear the interrupt flag specified source
         * @param source the interrupt source
         */
        void clearFlag(InterruptSource & source) volatile {
            // Very trivial...
            reg.ifs[source.ifsVecIndex].clear = source.ifsMask;
        }
    private:
        // The interrupt register
        volatile InterruptRegister<IFSVEC_MAX, IECVEC_MAX, IPCVEC_MAX> & reg;
        // the multivector bit mask
        uint32 mvecMask;
    };
}
#endif	/* INTERRUPTCONTROLLER_H */

