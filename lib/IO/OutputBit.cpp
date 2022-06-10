/**
 *
 * OutputBit
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#include "OutputBit.h"
#include "IOException.h"

Antipode::OutputBit::OutputBit(volatile PhysicalPort & port, volatile uint32 gpio, bool autoAttach) : port(port), gpio(gpio) {
    // Very trivial...
    if (!RegisterUtils::isBitValid(this->gpio)) {
        throw IOException(IO_INVALID_BIT_PARAMETER_CODE, IO_INVALID_BIT_PARAMETER_MESSAGE);
    }
    if (autoAttach) {
        attach();
    }
}

void Antipode::OutputBit::attach() volatile {
    // Very trivial...
    port.setDigital(gpio);
    port.setOutput(gpio);
}

bool Antipode::OutputBit::isAttached() volatile {
    // Very trivial...
    return port.isDigital(gpio) && port.isOutput(gpio);
}

bool Antipode::OutputBit::isDetached() volatile {
    // Very trivial...
    return !isAttached();
}

void Antipode::OutputBit::setHi() volatile {
    port.latchWrite(gpio, Hi);
}

void Antipode::OutputBit::setLo() volatile {
    port.latchWrite(gpio, Lo);
}

void Antipode::OutputBit::toggle() volatile {
    port.latchInvert(gpio);
}

Antipode::LogicLevel Antipode::OutputBit::getStatus() volatile {
    return port.latchRead(gpio);
}
