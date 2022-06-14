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
#include <ModuleException.h>

#define _I2C_STANDARD  0x000186A0 // 100KHz
#define _I2C_FAST      0x00061A80 // 400KHz
#define _I2C_FAST_PLUS 0x000F4240 // 1MHz

namespace Antipode {

    class I2cModule {
    public:

        enum I2cFrequency {
            Standard = _I2C_STANDARD, // 100KHz
            Fast = _I2C_FAST, // 400KHz
            FastPlus = _I2C_FAST_PLUS // 1MHz
        };

        /**
         * Builds an I2c module from register, sda and scl pins and device 
         * specific pulse gobbler delay time.
         * @param reg the i2c register
         * @param sdaBit the sda pin
         * @param sclBit the scl pin
         * @param pulseGobblerDelayTime the pulse gobbler delay time
         */
        I2cModule(volatile I2cRegister & reg, volatile OutputBit & sdaBit, volatile OutputBit & sclBit, double pulseGobblerDelayTime);

        /**
         * Initializes module as master
         * @param i2cFrequency the desired frequency
         * @param peripheralBusClockFrequency the peripheral bus clock frequency
         * @param idleStop flag for stop module when mcu is in idle
         * @throws ModuleException if the module is already open
         */
        void openAsMaster(const I2cFrequency i2cFrequency, uint32 peripheralBusClockFrequency, const bool idleStop = false) volatile; // throws ModuleException - already open

        /**
         * Get the module status
         * @return true if module is open, otherwise false
         */
        bool isOpen() volatile;

        /**
         * Close the module
         */
        void close() volatile;

        /**
         * Send the start sequence
         * @throws ModuleException if the module is closed or if is configured 
         *         as slave
         */
        void start() volatile;

        /**
         * Send the stop sequence
         * @throws ModuleException if the module is closed or if is configured 
         *         as slave
         */
        void stop() volatile;

        /**
         * Send the restart sequence
         * @throws ModuleException if the module is closed or if is configured 
         *         as slave
         */
        void restart() volatile;

        /**
         * Write data
         * @param data the data that will be written
         * @throws ModuleException if the module is closed or if is configured 
         *         as slave
         */
        void write(const uint8 data) volatile;

        /**
         * Read data
         * @return the received data
         * @throws ModuleException if the module is closed or if is configured 
         *         as slave
         */
        uint8 read() volatile;

        /**
         * Send a nack
         * @throws ModuleException if the module is closed or if is configured 
         *         as slave
         */
        void nack() volatile;

        /**
         * Send a ack
         * @throws ModuleException if the module is closed or if is configured 
         *         as slave
         */
        void ack() volatile;
    private:
        void checkStatus(uint8 mode) volatile;
        // The register
        volatile I2cRegister & reg;
        // The sda pin
        volatile OutputBit & sdaBit;
        // The scl pin
        volatile OutputBit & sclBit;
        // Device specific delay
        double pulseGobblerDelayTime;
        // Status flag
        bool open;
        // The operating mode (master | slave)
        uint8 mode;
    };
}

#endif	/* I2CMODULE_H */

