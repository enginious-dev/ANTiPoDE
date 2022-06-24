#include <xc.h>
#include <sys/attribs.h>
#include <Devices.h>
#include <Delay.h>

#pragma config FNOSC     = PRIPLL // Primary oscillator selected with PLL
#pragma config POSCMOD   = XT     // XT for <= 4MHz | HS for > 4MHz
#pragma config FPLLIDIV  = DIV_2  // 4MHz / 2 = 2MHz
#pragma config FPLLMUL   = MUL_20 // 2MHz * 2 = 40MHz
#pragma config FPLLODIV  = DIV_1  // 40MHz / 1 = 40MHz
#pragma config FPBDIV    = DIV_1  // 40MHz / 1 = 40MHz

#pragma config PMDL1WAY  = OFF
#pragma config IOL1WAY   = OFF
#pragma config FUSBIDIO  = ON
#pragma config FVBUSONIO = ON
#pragma config UPLLIDIV  = DIV_2
#pragma config UPLLEN    = OFF
#pragma config FSOSCEN   = OFF
#pragma config IESO      = ON
#pragma config OSCIOFNC  = OFF
#pragma config FCKSM     = CSDCMD
#pragma config WDTPS     = PS1048576
#pragma config WINDIS    = OFF
#pragma config FWDTEN    = OFF
#pragma config FWDTWINSZ = WINSZ_25
#pragma config JTAGEN    = OFF
#pragma config ICESEL    = ICS_PGx1
#pragma config PWP       = OFF
#pragma config BWP       = OFF
#pragma config CP        = OFF

using namespace Antipode;

int main() {



    return 0;
}