/**
 *
 * UartModule
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef UARTMODULE_H
#define	UARTMODULE_H

#include <Registers.h>
#include <IOException.h>
#include <ConfigController.h>

namespace Antipode {

    struct UartBits {
        const uint32 modeOnMask;
        const uint32 modeSidlmask;
        const uint32 modePdselPosition;
        const uint32 staRxEnMask;
        const uint32 staTxEnMask;
        const uint32 staUtxbfMask;
        const uint32 staTrmtMask;
    };

    class UartModule {
    public:

        enum Baud {
            Baud9600 = 9600,
            Baud19200 = 19200,
            Baud115200 = 115200
        };

        enum DataAndParity {
            Data8bitNoParity,
            Data8bitEvenParity,
            Data9bitOddParity,
            Data9bitNoParity
        };

        enum StopSelection {
            Stop1bit,
            Stop2bit
        };

        UartModule(volatile UartRegister & reg, volatile ConfigController & configController, volatile UartBits & uartBits);
        void openRxTx(const Baud baudRate, const DataAndParity dataAndParity, const StopSelection stop, const bool idleStop = false);
        bool isOpen();
        void close();
        void write(const char * str);
        void writeln(const char * str);

    private:
        volatile UartRegister & reg;
        volatile ConfigController & configController;
        volatile UartBits & uartBits;
        bool open;
    };
}
#endif	/* UARTMODULE_H */

