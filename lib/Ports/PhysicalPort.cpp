/**
 *
 * PhysicalPort
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#include "PhysicalPort.h"
#include "IOException.h"

Antipode::PhysicalPort::PhysicalPort(volatile PortRegister & w) : reg(w) {
    // Set all digital
    reg.ansel.clear = ALL;
    // Set all input
    reg.tris.set = ALL;
    // Clear the latch
    reg.lat.clear = ALL;
    // Disable open drain
    reg.odc.clear = ALL;
    // Disable all pull-up
    reg.cnpu.clear = ALL;
    // Disable all pull-down
    reg.cnpd.clear = ALL;
    // Disable change-notice
    reg.cncon.clear = ALL;
    reg.cnen.clear = ALL;
    // Clear change-notice
    reg.cnstat.clear = ALL;
}

Antipode::uint32 Antipode::PhysicalPort::getAdcStatus() const volatile {
    // Very trivial...
    return reg.ansel.base;
}

bool Antipode::PhysicalPort::isDigital(const uint32 gpio) const volatile {
    // Very trivial...
    return RegisterUtils::areLo(reg.ansel.base, gpio);
}

bool Antipode::PhysicalPort::isAnalog(const uint32 gpio) const volatile {
    // Very trivial...
    return RegisterUtils::areHi(reg.ansel.base, gpio);
}

void Antipode::PhysicalPort::setDigital(const uint32 gpio) volatile {
    // Very trivial...
    reg.ansel.clear = gpio;
}

void Antipode::PhysicalPort::setAnalog(const uint32 gpio) volatile {
    // Very trivial...
    reg.ansel.set = gpio;
}

Antipode::uint32 Antipode::PhysicalPort::getIoStatus() const volatile {
    // Very trivial...
    return reg.tris.base;
}

bool Antipode::PhysicalPort::isInput(const uint32 gpio) const volatile {
    // Very trivial...
    return RegisterUtils::areHi(reg.tris.base, gpio);
}

bool Antipode::PhysicalPort::isOutput(const uint32 gpio) const volatile {
    // Very trivial...
    return RegisterUtils::areLo(reg.tris.base, gpio);
}

void Antipode::PhysicalPort::setInput(const uint32 gpio) volatile {
    // Very trivial...
    reg.tris.set = gpio;
}

void Antipode::PhysicalPort::setOutput(const uint32 gpio) volatile {
    // Very trivial...
    reg.tris.clear = gpio;
}

Antipode::uint32 Antipode::PhysicalPort::getOpenDrainStatus() const volatile {
    // Very trivial...
    return reg.odc.base;
}

bool Antipode::PhysicalPort::isOpenDrainEnabled(const uint32 gpio) const volatile {
    // Very trivial...
    return RegisterUtils::areHi(reg.odc.base, gpio);
}

bool Antipode::PhysicalPort::isOpenDrainDisabled(const uint32 gpio) const volatile {
    // Very trivial...
    return RegisterUtils::areLo(reg.odc.base, gpio);
}

void Antipode::PhysicalPort::setOpenDrainEnabled(const uint32 gpio) volatile {
    // Very trivial...
    reg.odc.set = gpio;
}

void Antipode::PhysicalPort::setOpenDrainDisabled(const uint32 gpio) volatile {
    // Very trivial...
    reg.odc.clear = gpio;
}

Antipode::uint32 Antipode::PhysicalPort::getPullUpStatus() const volatile {
    // Very trivial...
    return reg.cnpu.base;
}

bool Antipode::PhysicalPort::isPullUpEnabled(const uint32 gpio) const volatile {
    // Very trivial...
    return RegisterUtils::areHi(reg.cnpu.base, gpio);
}

bool Antipode::PhysicalPort::isPullUpDisabled(const uint32 gpio) const volatile {
    // Very trivial...
    return RegisterUtils::areLo(reg.cnpu.base, gpio);
}

void Antipode::PhysicalPort::setPullUpEnabled(const uint32 gpio) volatile {
    // Very trivial...
    reg.cnpu.set = gpio;
}

void Antipode::PhysicalPort::setPullUpDisabled(const uint32 gpio) volatile {
    // Very trivial...
    reg.cnpu.clear = gpio;
}

Antipode::uint32 Antipode::PhysicalPort::getPullDownStatus() const volatile {
    // Very trivial...
    return reg.cnpd.base;
}

bool Antipode::PhysicalPort::isPullDownEnabled(const uint32 gpio) const volatile {
    // Very trivial...
    return RegisterUtils::areHi(reg.cnpd.base, gpio);
}

bool Antipode::PhysicalPort::isPullDownDisabled(const uint32 gpio) const volatile {
    // Very trivial...
    return RegisterUtils::areLo(reg.cnpd.base, gpio);
}

void Antipode::PhysicalPort::setPullDownEnabled(const uint32 gpio) volatile {
    // Very trivial...
    reg.cnpd.set = gpio;
}

void Antipode::PhysicalPort::setPullDownDisabled(const uint32 gpio) volatile {
    // Very trivial...
    reg.cnpd.clear = gpio;
}

Antipode::uint32 Antipode::PhysicalPort::portRead() const volatile {
    // Very trivial...
    return reg.port.base;
}

Antipode::LogicLevel Antipode::PhysicalPort::portRead(const uint32 gpio) const volatile {
    // Check if valid bit is passed
    if (!RegisterUtils::isBitValid(gpio)) {
        throw IOException(IO_INVALID_BIT_PARAMETER_CODE, IO_INVALID_BIT_PARAMETER_MESSAGE);
    }

    // Very trivial...
    return RegisterUtils::areHi(reg.port.base, gpio) ? Hi : Lo;
}

void Antipode::PhysicalPort::portWrite(const uint32 value) volatile {
    // Very trivial...
    reg.port.base = value;
}

void Antipode::PhysicalPort::portWrite(const uint32 gpio, const LogicLevel value) volatile {
    // Very trivial...
    if (value == Hi) {
        reg.port.set = gpio;
    } else {
        reg.port.clear = gpio;
    }
}

void Antipode::PhysicalPort::portInvert(const uint32 gpio) volatile {
    // Very trivial...
    reg.port.invert = gpio;
}

Antipode::uint32 Antipode::PhysicalPort::latchRead() const volatile {
    // Very trivial...
    return reg.lat.base;
}

Antipode::LogicLevel Antipode::PhysicalPort::latchRead(const uint32 gpio) const volatile {
    // Check if valid bit is passed
    if (!RegisterUtils::isBitValid(gpio)) {
        throw IOException(IO_INVALID_BIT_PARAMETER_CODE, IO_INVALID_BIT_PARAMETER_MESSAGE);
    }

    // Very trivial...
    return RegisterUtils::areHi(reg.lat.base, gpio) ? Hi : Lo;
}

void Antipode::PhysicalPort::latchWrite(const uint32 value) volatile {
    // Very trivial...
    reg.lat.base = value;
}

void Antipode::PhysicalPort::latchWrite(const uint32 gpio, const LogicLevel value) volatile {
    // Very trivial...
    if (value == Hi) {
        reg.lat.set = gpio;
    } else {
        reg.lat.clear = gpio;
    }
}

void Antipode::PhysicalPort::latchInvert(const uint32 gpio) volatile {
    // Very trivial...
    reg.lat.invert = gpio;
}