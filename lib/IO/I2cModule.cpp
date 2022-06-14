/**
 *
 * I2cModule
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */
#include <cmath>
#include "I2cModule.h"

#define _I2C_UNDEFINED 0x00
#define _I2C_MASTER 0x01
#define _I2C_SLAVE  0x02
#define _I2CxCON_ON_MASK              0x00008000
#define _I2CxCON_SIDL_MASK            0x00002000
#define _I2CxCON_DISSLW_MASK          0x00000200

#define _I2CxCON_SEN_MASK             0x00000001
#define _I2CxCON_RSEN_MASK            0x00000002
#define _I2CxCON_PEN_MASK             0x00000004
#define _I2CxCON_RCEN_MASK            0x00000008
#define _I2CxCON_ACKEN_MASK           0x00000010
#define _I2CxCON_ACKDT_MASK           0x00000020

#define _I2CxSTAT_TBF_MASK            0x00000001
#define _I2CxSTAT_RBF_MASK            0x00000002
#define _I2CxSTAT_TRSTAT_MASK         0x00004000
#define _I2CxSTAT_ACKSTAT_MASK        0x00008000

Antipode::I2cModule::I2cModule(volatile I2cRegister & reg, volatile OutputBit & sdaBit, volatile OutputBit & sclBit, double pulseGobblerDelayTime) : reg(reg), sdaBit(sdaBit), sclBit(sclBit), pulseGobblerDelayTime(pulseGobblerDelayTime), open(false), mode(_I2C_UNDEFINED) {

}

void Antipode::I2cModule::openAsMaster(const I2cFrequency i2cFrequency, uint32 peripheralBusClockFrequency, const bool idleStop) volatile {
    // If module is already open throw exception
    if (open) {
        throw ModuleException(MODULE_ALREADY_OPEN_CODE, MODULE_ALREADY_OPEN_MESSAGE);
    }

    // Attach sda
    sdaBit.attach();
    // And set low
    sdaBit.setLo();
    // Attach scl
    sclBit.attach();
    // And set low
    sclBit.setLo();
    // Initialize config with ON bit
    uint32 config = _I2CxCON_ON_MASK;

    // Set the baud rate generator (BRG) according to requested frequency 
    // (@see Section 24. "Inter-Integrated Circuit (I2C)" - DS60001116)
    reg.brg.base = std::ceil((peripheralBusClockFrequency / (i2cFrequency << 1)) - 1 - (peripheralBusClockFrequency * pulseGobblerDelayTime) / 2);

    // If requested frequency is not 100KHz or 1MHz enable slew rate control bit 
    // (@see Section 24. "Inter-Integrated Circuit (I2C)" - DS60001116)
    if (i2cFrequency == Standard || i2cFrequency == FastPlus) {
        config |= _I2CxCON_DISSLW_MASK;
    }

    // If module must be stop in idle mode set the corresponding bit
    if (idleStop) {
        config |= _I2CxCON_SIDL_MASK;
    }

    // Set the config register: module is open
    reg.con.base = config;

    // Set mode as Master
    mode = _I2C_MASTER;

    // Set the open flag as true
    open = true;
}

bool Antipode::I2cModule::isOpen() volatile {
    // Very trivial...
    return open;
}

void Antipode::I2cModule::close() volatile {
    // If module is closed return (throwing an exception is too much...)
    if (!open) {
        return;
    }
    // Clear I2CxCON
    reg.con.clear = ALL;
    // Clear I2CxSTAT
    reg.stat.clear = ALL;
    // Clear I2CxADD
    reg.add.clear = ALL;
    // Clear I2CxMSK
    reg.msk.clear = ALL;
    // Clear I2CxTRN
    reg.trn.clear = ALL;
    // Set mode as Master
    mode = _I2C_UNDEFINED;
    // Set the open flag as false
    open = false;
}

void Antipode::I2cModule::start() volatile {
    // If module is closed or is not configured as Master throw exception
    checkStatus(_I2C_MASTER);
    // Set for start sequence transmission
    reg.con.set = _I2CxCON_SEN_MASK;
    // Just a little delay
    asm volatile("nop");
    // Wait until start sequence has been transitted
    while (reg.con.base & _I2CxCON_SEN_MASK);
}

void Antipode::I2cModule::stop() volatile {
    // If module is closed or is not configured as Master throw exception
    checkStatus(_I2C_MASTER);
    // Set for stop sequence transmission
    reg.con.set = _I2CxCON_PEN_MASK;
    // Just a little delay
    asm volatile("nop");
    // Wait until stop sequence has been transitted
    while (reg.con.base & _I2CxCON_PEN_MASK);
}

void Antipode::I2cModule::restart() volatile {
    // If module is closed or is not configured as Master throw exception
    checkStatus(_I2C_MASTER);
    // Set for repeated start sequence transmission
    reg.con.set = _I2CxCON_RSEN_MASK;
    // Just a little delay
    asm volatile("nop");
    // Wait until repeated start sequence has been transitted
    while (reg.con.base & _I2CxCON_RSEN_MASK);
}

void Antipode::I2cModule::write(const uint8 data) volatile {
    // If module is closed or is not configured as Master throw exception
    checkStatus(_I2C_MASTER);
    // Write data on transmit register
    reg.trn.base = static_cast<uint32> (data);
    // Just a little delay
    asm volatile("nop");
    // Wait until trasmission is end
    while (reg.stat.base & _I2CxSTAT_TRSTAT_MASK);
    // Wait until transmit buffer is empty
    while (reg.stat.base & _I2CxSTAT_TBF_MASK);
    // Wait until ack is received
    while (reg.stat.base & _I2CxSTAT_ACKSTAT_MASK);
}

Antipode::uint8 Antipode::I2cModule::read() volatile {
    // If module is closed or is not configured as Master throw exception
    checkStatus(_I2C_MASTER);
    // Enable receive data
    reg.con.set = _I2CxCON_RCEN_MASK;
    // Wait until data is received
    while (reg.con.base & _I2CxCON_RCEN_MASK);
    // Wait until received buffer is full
    while (!(reg.stat.base & _I2CxSTAT_RBF_MASK));
    // Return the appropriately truncated data
    return static_cast<uint8> (reg.rcv.base & 0xFF);
}

void Antipode::I2cModule::nack() volatile {
    // If module is closed or is not configured as Master throw exception
    checkStatus(_I2C_MASTER);
    // Set for nack sequence transmission
    reg.con.set = _I2CxCON_ACKDT_MASK;
    // Just a little delay
    asm volatile("nop");
    // Start nack transmission
    reg.con.set = _I2CxCON_ACKEN_MASK;
    // Wait until nack sequence has been transitted
    while (reg.con.base & _I2CxCON_ACKEN_MASK);
}

void Antipode::I2cModule::ack() volatile {
    // If module is closed or is not configured as Master throw exception
    checkStatus(_I2C_MASTER);
    // Set for ack sequence transmission
    reg.con.clear = _I2CxCON_ACKDT_MASK;
    // Just a little delay
    asm volatile("nop");
    // Start ack transmission
    reg.con.set = _I2CxCON_ACKEN_MASK;
    // Wait until ack sequence has been transitted
    while (reg.con.base & _I2CxCON_ACKEN_MASK);
}

void Antipode::I2cModule::checkStatus(uint8 mode) volatile {
    // If module is closed throw exception
    if (!open) {
        throw ModuleException(MODULE_CLOSED_CODE, MODULE_CLOSED_MESSAGE);
    }
    // If module is not configured as requested
    if (mode != _I2C_UNDEFINED && this->mode != mode) {
        throw ModuleException(MODULE_OPERATION_NOT_ALLOWED_WITHIN_CURRENT_CONFIG_CODE, MODULE_OPERATION_NOT_ALLOWED_WITHIN_CURRENT_CONFIG_MESSAGE);
    }
}