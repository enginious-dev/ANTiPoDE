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
}

#endif	/* REGISTERS_H */

