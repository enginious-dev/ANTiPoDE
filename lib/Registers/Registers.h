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
    };

    /**
     * 
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
     * 
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
     * 
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
     * 
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
     * 
     * Represents a 1x32 bits register.
     */
    class StandardRegister {
    public:
        volatile uint32 base;
    };

    /**
     * 
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

    template <uint32 IFSVEC_MAX, uint32 IECVEC_MAX, uint32 IPCVEC_MAX> class InterruptRegister {
    public:
        volatile ClrSetInvRegister intcon;
        volatile BaseOnlyRegister intstat;
        volatile ClrSetInvRegister iptmr;
        volatile ClrSetInvRegister ifs[IFSVEC_MAX];
        volatile ClrSetInvRegister iec[IECVEC_MAX];
        volatile ClrSetInvRegister ipc[IPCVEC_MAX];
    };
}

#endif	/* REGISTERS_H */

