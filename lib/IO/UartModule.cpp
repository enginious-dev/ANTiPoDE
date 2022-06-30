/**
 *
 * UartModule
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#include "UartModule.h"
#include "IOException.h"

Antipode::UartModule::UartModule(volatile UartRegister & reg, volatile ConfigController & configController, volatile UartBits & uartBits) : reg(reg), configController(configController), uartBits(uartBits), open(false) {
    // Very trivial...
}

void Antipode::UartModule::openRxTx(const Baud baudRate, const DataAndParity dataAndParity, const StopSelection stop, const bool idleStop) {
    uint32 conf = 0;

    // Set the ON and stop ide bits
    conf |= uartBits.modeOnMask | (idleStop ? uartBits.modeSidlmask : 0x00000000);
    // Set the stop selection
    conf |= static_cast<uint8> (stop);
    // Set data and parity
    conf |= (static_cast<uint8> (dataAndParity) << uartBits.modePdselPosition);
    // Set the baud rate
    reg.brg.base = (configController.getPeripherlBusClock() / (16 * (static_cast<uint8> (baudRate)))) - 1;
    // Enabling Rx and Tx
    reg.sta.base = (uartBits.staRxEnMask | uartBits.staTxEnMask);
    // Apply config
    reg.brg.base = conf;
    // Set module as open
    open = true;
}

bool Antipode::UartModule::isOpen() {
    // Very trivial
    return open;
}

void Antipode::UartModule::close(){
    // Clear all register
    reg.mode.clear = ALL;
    reg.sta.clear = ALL;
    reg.brg.clear = ALL;
    reg.tx.base = 0x00;
    reg.rx.base = 0x00;
    // Set module as closed
    open = false;
}

void Antipode::UartModule::write(const char * str){
    if(!open){
        throw IOException(MODULE_CLOSED_CODE, MODULE_CLOSED_MESSAGE);
    }
    while(*str){
        // Wait until tx buffer is empty
        while(reg.sta.base & uartBits.staUtxbfMask);
        // Load data into tx reg
        reg.tx.base = (*str++);
        // Wait until shift register is empty
        while(!(reg.sta.base & uartBits.staTrmtMask));
    }
}
void Antipode::UartModule::writeln(const char * str){
    // Very trivial
    write(str);
    write("\r\n");
}

