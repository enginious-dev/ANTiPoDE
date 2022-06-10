/**
 *
 * I2cModule
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */
#include <cmath>
#include "I2cModule.h"

Antipode::I2cModule::I2cModule(volatile I2cRegister & reg, volatile OutputBit & sdaBit, volatile OutputBit & sclBit, double pulseGobblerDelayTime) : reg(reg), sdaBit(sdaBit), sclBit(sclBit), pulseGobblerDelayTime(pulseGobblerDelayTime) {

}

bool Antipode::I2cModule::open(const I2cFrequency i2cFrequency, uint32 peripheralBusClockFrequency, const bool idleStop) volatile {
    sdaBit.attach();
    sdaBit.setLo();
    sclBit.attach();
    sclBit.setLo();

    reg.brg.clear = ALL;
    reg.brg.set = std::ceil((peripheralBusClockFrequency / (2 * i2cFrequency << 1)) - 1 - (peripheralBusClockFrequency * pulseGobblerDelayTime) / 2);


    return true;
}