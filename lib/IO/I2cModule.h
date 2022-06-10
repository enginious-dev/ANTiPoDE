/**
 *
 * I2cModule
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef I2CMODULE_H
#define	I2CMODULE_H

#include <Registers.h>
#include <OutputBit.h>

#define _I2C_STANDARD  0x000186A0
#define _I2C_FAST      0x00061A80
#define _I2C_FAST_PLUS 0x000F4240

namespace Antipode {

    class I2cModule {
    public:

        enum I2cFrequency {
            Standard = _I2C_STANDARD,
            Fast = _I2C_FAST,
            FastPlus = _I2C_FAST_PLUS
        };

        I2cModule(volatile I2cRegister & reg, volatile OutputBit & sdaBit, volatile OutputBit & sclBit, double pulseGobblerDelayTime);
        bool open(const I2cFrequency i2cFrequency, uint32 peripheralBusClockFrequency, const bool idleStop = false) volatile;
        bool isOpen() volatile;
        void close() volatile;
        bool start() volatile;
        bool stop() volatile;
        bool restart() volatile;
        bool write(const uint8 data) volatile;
        uint8 read() volatile;
        bool nack() volatile;
        bool ack() volatile;
    private:
        volatile I2cRegister & reg;
        volatile OutputBit & sdaBit;
        volatile OutputBit & sclBit;
        double pulseGobblerDelayTime;
    };
}

#endif	/* I2CMODULE_H */

