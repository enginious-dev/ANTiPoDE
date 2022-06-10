/**
 *
 * OutputBit
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef OUTPUTBIT_H
#define	OUTPUTBIT_H

#include <PhysicalPort.h>

namespace Antipode {

    class OutputBit {
    public:
        /**
         * Creates an output bit on the desired 'port' at the 'gpio' bit.
         * @param port the desired port
         * @param gpio the gpio
         * @param autoAttach if true 'attach()' is called within the excution
         * @throws IOException if and invalid bit is passed
         */
        OutputBit(volatile PhysicalPort & port, volatile uint32 gpio, bool autoAttach = false);

        /**
         * Configure the corresponding TRISx bit of port as output
         */
        void attach() volatile;

        /**
         * Checks if the corresponding TRISx bit on port is configured as output
         * @return true if TRISx bit on port is configured as output, otherwise
         *         false
         */
        bool isAttached() volatile;

        /**
         * Checks if the corresponding TRISx bit on port is not configured as 
         * output
         * @return true if TRISx bit on port is not configured as output, 
         *         otherwise false
         */
        bool isDetached() volatile;

        /**
         * Set the corresponding LATx bit on port
         */
        void setHi() volatile;

        /**
         * Clear the corresponding LATx bit on port
         */
        void setLo() volatile;

        /**
         * Invert the corresponding LATx bit on port
         */
        void toggle() volatile;

        /**
         * Get the corresponding LATx bit value on port
         * @return the corresponding LATx bit value on port
         */
        LogicLevel getStatus() volatile;
    private:
        // the physical port
        volatile PhysicalPort & port;
        // the bit
        const uint32 gpio;
    };
}

#endif	/* OUTPUTBIT_H */

