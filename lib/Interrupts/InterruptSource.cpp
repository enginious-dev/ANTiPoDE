/**
 *
 * InterruptSource
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#include "InterruptSource.h"

Antipode::InterruptSource::InterruptSource(const uint8 ifsVecIndex, const uint8 iecVecIndex, const uint8 ipcVecIndex, const uint32 ifsMask, const uint32 iecMask, const uint32 ipPosition, const uint32 ispPosition) {
    // Very trivial...
    this->ifsVecIndex = ifsVecIndex;
    this->ifsVecIndex = ifsVecIndex;
    this->iecVecIndex = iecVecIndex;
    this->ipcVecIndex = ipcVecIndex;
    this->ifsMask = ifsMask;
    this->iecMask = iecMask;
    this->ipPosition = ipPosition;
    this->ispPosition = ispPosition;
}
