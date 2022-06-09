/**
 *
 * InterruptSource
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef INTERRUPTSOURCE_H
#define	INTERRUPTSOURCE_H

#include <Types.h>

namespace Antipode {

    template <uint32 IFSVEC_MAX, uint32 IECVEC_MAX, uint32 IPCVEC_MAX> class InterruptController;

    /**
     * 
     * Represents an interrupt source.
     */
    class InterruptSource {
        template <uint32 IFSVEC_MAX, uint32 IECVEC_MAX, uint32 IPCVEC_MAX> friend class InterruptController;
    public:
        /**
         * Build an interrupt source.
         * 
         * @param ifsVecIndex interrupt flags vector index
         * @param iecVecIndex interrupt enable vector index
         * @param ipcVecIndex interrupt priority vector index
         * @param ifsMask interrupt flag mask
         * @param iecMask interrupt enable mask
         * @param ipPosition interrupt priority position
         * @param ispPosition interrupt sub-priority position
         */
        InterruptSource(const uint8 ifsVecIndex, const uint8 iecVecIndex, const uint8 ipcVecIndex, const uint32 ifsMask, const uint32 iecMask, const uint32 ipPosition, const uint32 ispPosition);
    private:
        // interrupt flags vector index
        uint8 ifsVecIndex;
        // interrupt enable vector index
        uint8 iecVecIndex;
        // interrupt priority vector index
        uint8 ipcVecIndex;
        // interrupt flag mask
        uint32 ifsMask;
        // interrupt enable mask
        uint32 iecMask;
        // interrupt priority position
        uint32 ipPosition;
        // interrupt sub-priority position
        uint32 ispPosition;
    };
}
#endif	/* INTERRUPTSOURCE_H */

