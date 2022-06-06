/**
 *
 * p32mx2xxfxxxb
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef P32MX2XXFXXXB_H
#define P32MX2XXFXXXB_H

#include <Registers.h>
#include <PhysicalPort.h>

/**
 * I/O PORTS
 */
// port a
__asm__ volatile ("_PORTA_w = 0xBF886000");
__asm__ volatile (".global _PORTA_w");
// port b
__asm__ volatile ("_PORTB_w = 0xBF886100");
__asm__ volatile (".global _PORTB_w");

namespace Antipode {
    extern volatile PortRegister PORTA_W __asm__("_PORTA_w") __attribute__((section("sfrs")));
    extern volatile PortRegister PORTB_W __asm__("_PORTB_w") __attribute__((section("sfrs")));
    
    PhysicalPort PortA = PhysicalPort(PORTA_W);
    PhysicalPort PortB = PhysicalPort(PORTB_W);
}

#endif	/* P32MX2XXFXXXB_H */