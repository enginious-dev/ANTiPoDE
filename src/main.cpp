#include <xc.h>
#include <sys/attribs.h>
#include <Devices.h>

#pragma config PMDL1WAY		= OFF
#pragma config IOL1WAY		= OFF
#pragma config FUSBIDIO		= ON
#pragma config FVBUSONIO	= ON
#pragma config FPLLIDIV		= DIV_2
#pragma config FPLLMUL		= MUL_20
#pragma config UPLLIDIV		= DIV_2
#pragma config UPLLEN		= OFF
#pragma config FPLLODIV		= DIV_2
#pragma config FNOSC		= FRCPLL
#pragma config FSOSCEN		= OFF
#pragma config IESO		    = ON
#pragma config POSCMOD		= OFF
#pragma config OSCIOFNC		= OFF
#pragma config FPBDIV		= DIV_1
#pragma config FCKSM		= CSDCMD
#pragma config WDTPS		= PS1048576
#pragma config WINDIS		= OFF
#pragma config FWDTEN		= OFF
#pragma config FWDTWINSZ	= WINSZ_25
#pragma config JTAGEN		= OFF
#pragma config ICESEL		= ICS_PGx1
#pragma config PWP		    = OFF
#pragma config BWP		    = OFF
#pragma config CP			= OFF

using namespace Antipode;

int main() {
    return 0;
}