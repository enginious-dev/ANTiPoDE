/**
 *
 * AbstractInterruptController
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef ABSTRACTINTERRUPTCONTROLLER_H
#define	ABSTRACTINTERRUPTCONTROLLER_H

#include <Registers.h>
#include <InterruptSource.h>

namespace Antipode {

    class AbstractInterruptController {
    public:
        /**
         * Enables the global interrupt
         * @param multiVectorModeEnabled multi Vector Mode Enabling flag.
         */
        virtual void enableGlobalInterrupt(bool multiVectorModeEnabled = true) volatile = 0;

        /**
         * Disables the global interrupt
         */
        virtual void disableGlobalInterrupt() volatile = 0;

        /**
         * Enables the interrupt with given priority and subPriority for the
         * specified source
         * @param source the interrupt source
         * @param priority the interrupt priority
         * @param subPriority the interrupt sub-priority
         */
        virtual void enableInterrupt(InterruptSource & source, const InterruptPriority priority, const InterruptSubPriority subPriority = Isp0) volatile = 0;

        /**
         * Disables the interrupt for the specified source
         * @param source the interrupt source
         */
        virtual void disableInterrupt(InterruptSource & source) volatile = 0;

        /**
         * Checks if an interrupt has occurred for the specified source
         * @param source the interrupt source
         * @return true if and interrupt event occured, otherwise false
         */
        virtual bool hasInterruptOccurred(InterruptSource & source) volatile = 0;

        /**
         * Clear the interrupt flag specified source
         * @param source the interrupt source
         */
        virtual void clearFlag(InterruptSource & source) volatile = 0;
    };
}
#endif	/* ABSTRACTINTERRUPTCONTROLLER_H */

