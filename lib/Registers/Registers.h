/**
 *
 * Registers
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef REGISTERS_H
#define	REGISTERS_H

#include <Types.h>

// PPS 
#define _PPS_VECTOR_MASK       0x000000FF // (255 << _PPS_VECTOR_POSITION[ = 0])
#define _PPS_INPUT_GROUP_MASK  0x00000F00 // (15 << _PPS_INPUT_GROUP_POSITION[ = 8])
#define _PPS_OUTPUT_GROUP_MASK 0x0000F000 // (15 << _PPS_OUTPUT_GROUP_POSITION[ = 12])
#define _PPS_TYPE_MASK         0x00030000 // (3  << _PPS_TYPE_POSITION[ = 16])
#define _PPS_TYPE_INPUT        0x00020000 // (2  << _PPS_TYPE_POSITION[ = 16])
#define _PPS_TYPE_OUTPUT       0x00010000 // (1  << _PPS_TYPE_POSITION[ = 16])
#define _PPS_TYPE_PORT_PIN     0x00030000 // (3  << _PPS_TYPE_POSITION[ = 16])
#define _PPS_VALUE_MASK        0x003C0000 // (15 << _PPS_VALUE_POSITION[ = 18])

namespace Antipode {

    /**
     * 
     * Register utilities
     */
    class RegisterUtils {
    public:

        /**
         * Checks if all 'bits' are Hi in 'reg' value
         * @param reg the value
         * @param bits the bits
         * @return true if all bits are Hi otherwise false
         */
        static bool areHi(volatile uint32 reg, uint32 bits) {
            return (reg & bits) == bits;
        }

        /**
         * Checks if all 'bits' are Lo in 'reg' value
         * @param reg the value
         * @param bits the bits
         * @return true if all bits are Lo otherwise false
         */
        static bool areLo(volatile uint32 reg, uint32 bits) {
            return (~reg & bits) == bits;
        }

        /**
         * Checks if 'value' represent a valid bit (must be a power of 2)
         * @param value the value
         * @return true if value is valid otherwise false
         */
        static bool isBitValid(uint32 value) {
            return (value != 0) && ((value & (value - 1)) == 0);
        }

        /**
         * Returns the least non zero significant bit position:
         * 
         * <pre>
         * RegisterUtils::getLsbPosition(0b11110000); // 4
         * RegisterUtils::getLsbPosition(0b11100000); // 5
         * </pre>
         * 
         * @param value the value
         * @return the least non zero significant bit position
         */
        static uint8 getLsbPosition(uint32 value) {
            if (!value) {
                return 0;
            }
            uint32 res = 0;
            while ((value & (1 << res++)) == 0) {
            }
            return res - 1;
        }
    };

    /**
     * Represents a 4x32 bits register that has clr, set & inv sub-registers 
     * associated.
     */
    class ClrSetInvRegister {
    public:
        volatile uint32 base;
        volatile uint32 clear;
        volatile uint32 set;
        volatile uint32 invert;
    };

    /**
     * Represents a 4x32 bits register that has only clr sub-register 
     * associated.
     */
    class ClrOnlyRegister {
    public:
        volatile uint32 base;
        volatile uint32 clear;
        volatile uint32 : 0x20;
        volatile uint32 : 0x20;
    };

    /**
     * Represents a 4x32 bits register that does not have clr, set & 
     * inv sub-registers associated.
     */
    class BaseOnlyRegister {
    public:
        volatile uint32 base;
        volatile uint32 : 0x20;
        volatile uint32 : 0x20;
        volatile uint32 : 0x20;
    };

    /**
     * Represents a 4x32 bits pad register.
     */
    class PadRegister {
    public:
        volatile uint32 : 0x20;
        volatile uint32 : 0x20;
        volatile uint32 : 0x20;
        volatile uint32 : 0x20;
    };

    /**
     * Represents a 1x32 bits register.
     */
    class StandardRegister {
    public:
        volatile uint32 base;
    };

    /**
     * Represents a port register set.
     */
    class PortRegister {
    public:
        volatile ClrSetInvRegister ansel;
        volatile ClrSetInvRegister tris;
        volatile ClrSetInvRegister port;
        volatile ClrSetInvRegister lat;
        volatile ClrSetInvRegister odc;
        volatile ClrSetInvRegister cnpu;
        volatile ClrSetInvRegister cnpd;
        volatile ClrSetInvRegister cncon;
        volatile ClrSetInvRegister cnen;
        volatile ClrSetInvRegister cnstat;
    };

    /**
     * Represents an interrupt register set.
     */
    template <uint32 IFSVEC_MAX, uint32 IECVEC_MAX, uint32 IPCVEC_MAX> class InterruptRegister {
    public:
        volatile ClrSetInvRegister intcon;
        volatile BaseOnlyRegister intstat;
        volatile ClrSetInvRegister iptmr;
        volatile ClrSetInvRegister ifs[IFSVEC_MAX];
        volatile ClrSetInvRegister iec[IECVEC_MAX];
        volatile ClrSetInvRegister ipc[IPCVEC_MAX];
    };

    /**
     * Represents an I2C register set.
     */
    class I2cRegister {
    public:
        volatile ClrSetInvRegister con;
        volatile ClrSetInvRegister stat;
        volatile ClrSetInvRegister add;
        volatile ClrSetInvRegister msk;
        volatile ClrSetInvRegister brg;
        volatile ClrSetInvRegister trn;
        volatile BaseOnlyRegister rcv;
    };

    /**
     * Represents a peripheral pin select (PPS) register set.
     */
    template <uint32 PPSVEC_MAX> class PeripheralPinSelectRegister {
    public:
        volatile BaseOnlyRegister pps[PPSVEC_MAX];
    };

    /**
     * Represents configuration bits register set.
     */
    class ConfigurationBitsRegister {
    public:
        volatile BaseOnlyRegister cfgcon;
        volatile PadRegister pad;
        volatile BaseOnlyRegister devid;
        volatile ClrSetInvRegister syskey;
    };
}

#endif	/* REGISTERS_H */

