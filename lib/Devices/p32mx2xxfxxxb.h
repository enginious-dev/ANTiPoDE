/**
 *
 * p32mx2xxfxxxb
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef P32MX2XXFXXXB_H
#define P32MX2XXFXXXB_H

#include <xc.h>
#include <Registers.h>
#include <PhysicalPort.h>
#include <InterruptController.h>
#include <ConfigController.h>
#include <PeripheralPinSelectController.h>
#include <I2cModule.h>
#include <CoreTimer.h>
#include <UartModule.h>

// PIN CONSTANTS
#define A0  BIT_0
#define A1  BIT_1
#define A2  BIT_2
#define A3  BIT_3
#define A4  BIT_4

#define B0  BIT_0
#define B1  BIT_1
#define B2  BIT_2
#define B3  BIT_3
#define B4  BIT_4
#define B7  BIT_7
#define B8  BIT_8
#define B9  BIT_9
#define B10 BIT_10
#define B11 BIT_11
#define B13 BIT_13
#define B14 BIT_14
#define B15 BIT_15

// INTERRUPT CONSTANTS
#define _IFSVEC_MAX 0x03
#define _IECVEC_MAX 0x03
#define _IPCVEC_MAX 0x0D

#define _IFS0 0x00
#define _IFS1 0x01
#define _IFSVEC_CTIF_INDEX     _IFS0
#define _IFSVEC_CS0IF_INDEX    _IFS0
#define _IFSVEC_CS1IF_INDEX    _IFS0
#define _IFSVEC_INT0IF_INDEX   _IFS0
#define _IFSVEC_T1IF_INDEX     _IFS0
#define _IFSVEC_IC1EIF_INDEX   _IFS0
#define _IFSVEC_IC1IF_INDEX    _IFS0
#define _IFSVEC_OC1IF_INDEX    _IFS0
#define _IFSVEC_INT1IF_INDEX   _IFS0
#define _IFSVEC_T2IF_INDEX     _IFS0
#define _IFSVEC_IC2EIF_INDEX   _IFS0
#define _IFSVEC_IC2IF_INDEX    _IFS0
#define _IFSVEC_OC2IF_INDEX    _IFS0
#define _IFSVEC_INT2IF_INDEX   _IFS0
#define _IFSVEC_T3IF_INDEX     _IFS0
#define _IFSVEC_IC3EIF_INDEX   _IFS0
#define _IFSVEC_IC3IF_INDEX    _IFS0
#define _IFSVEC_OC3IF_INDEX    _IFS0
#define _IFSVEC_INT3IF_INDEX   _IFS0
#define _IFSVEC_T4IF_INDEX     _IFS0
#define _IFSVEC_IC4EIF_INDEX   _IFS0
#define _IFSVEC_IC4IF_INDEX    _IFS0
#define _IFSVEC_OC4IF_INDEX    _IFS0
#define _IFSVEC_INT4IF_INDEX   _IFS0
#define _IFSVEC_T5IF_INDEX     _IFS0
#define _IFSVEC_IC5EIF_INDEX   _IFS0
#define _IFSVEC_IC5IF_INDEX    _IFS0
#define _IFSVEC_OC5IF_INDEX    _IFS0
#define _IFSVEC_AD1IF_INDEX    _IFS0
#define _IFSVEC_FSCMIF_INDEX   _IFS0
#define _IFSVEC_RTCCIF_INDEX   _IFS0
#define _IFSVEC_FCEIF_INDEX    _IFS0
#define _IFSVEC_CMP1IF_INDEX   _IFS1
#define _IFSVEC_CMP2IF_INDEX   _IFS1
#define _IFSVEC_CMP3IF_INDEX   _IFS1
#define _IFSVEC_USBIF_INDEX    _IFS1
#define _IFSVEC_SPI1EIF_INDEX  _IFS1
#define _IFSVEC_SPI1RXIF_INDEX _IFS1
#define _IFSVEC_SPI1TXIF_INDEX _IFS1
#define _IFSVEC_U1EIF_INDEX    _IFS1
#define _IFSVEC_U1RXIF_INDEX   _IFS1
#define _IFSVEC_U1TXIF_INDEX   _IFS1
#define _IFSVEC_I2C1BIF_INDEX  _IFS1
#define _IFSVEC_I2C1SIF_INDEX  _IFS1
#define _IFSVEC_I2C1MIF_INDEX  _IFS1
#define _IFSVEC_CNAIF_INDEX    _IFS1
#define _IFSVEC_CNBIF_INDEX    _IFS1
#define _IFSVEC_CNCIF_INDEX    _IFS1
#define _IFSVEC_PMPIF_INDEX    _IFS1
#define _IFSVEC_PMPEIF_INDEX   _IFS1
#define _IFSVEC_SPI2EIF_INDEX  _IFS1
#define _IFSVEC_SPI2RXIF_INDEX _IFS1
#define _IFSVEC_SPI2TXIF_INDEX _IFS1
#define _IFSVEC_U2EIF_INDEX    _IFS1
#define _IFSVEC_U2RXIF_INDEX   _IFS1
#define _IFSVEC_U2TXIF_INDEX   _IFS1
#define _IFSVEC_I2C2BIF_INDEX  _IFS1
#define _IFSVEC_I2C2SIF_INDEX  _IFS1
#define _IFSVEC_I2C2MIF_INDEX  _IFS1
#define _IFSVEC_CTMUIF_INDEX   _IFS1
#define _IFSVEC_DMA0IF_INDEX   _IFS1
#define _IFSVEC_DMA1IF_INDEX   _IFS1
#define _IFSVEC_DMA2IF_INDEX   _IFS1
#define _IFSVEC_DMA3IF_INDEX   _IFS1

#define _IEC0 0x00
#define _IEC1 0x01
#define _IECVEC_CTIE_INDEX     _IEC0
#define _IECVEC_CS0IE_INDEX    _IEC0
#define _IECVEC_CS1IE_INDEX    _IEC0
#define _IECVEC_INT0IE_INDEX   _IEC0
#define _IECVEC_T1IE_INDEX     _IEC0
#define _IECVEC_IC1EIE_INDEX   _IEC0
#define _IECVEC_IC1IE_INDEX    _IEC0
#define _IECVEC_OC1IE_INDEX    _IEC0
#define _IECVEC_INT1IE_INDEX   _IEC0
#define _IECVEC_T2IE_INDEX     _IEC0
#define _IECVEC_IC2EIE_INDEX   _IEC0
#define _IECVEC_IC2IE_INDEX    _IEC0
#define _IECVEC_OC2IE_INDEX    _IEC0
#define _IECVEC_INT2IE_INDEX   _IEC0
#define _IECVEC_T3IE_INDEX     _IEC0
#define _IECVEC_IC3EIE_INDEX   _IEC0
#define _IECVEC_IC3IE_INDEX    _IEC0
#define _IECVEC_OC3IE_INDEX    _IEC0
#define _IECVEC_INT3IE_INDEX   _IEC0
#define _IECVEC_T4IE_INDEX     _IEC0
#define _IECVEC_IC4EIE_INDEX   _IEC0
#define _IECVEC_IC4IE_INDEX    _IEC0
#define _IECVEC_OC4IE_INDEX    _IEC0
#define _IECVEC_INT4IE_INDEX   _IEC0
#define _IECVEC_T5IE_INDEX     _IEC0
#define _IECVEC_IC5EIE_INDEX   _IEC0
#define _IECVEC_IC5IE_INDEX    _IEC0
#define _IECVEC_OC5IE_INDEX    _IEC0
#define _IECVEC_AD1IE_INDEX    _IEC0
#define _IECVEC_FSCMIE_INDEX   _IEC0
#define _IECVEC_RTCCIE_INDEX   _IEC0
#define _IECVEC_FCEIE_INDEX    _IEC0
#define _IECVEC_CMP1IE_INDEX   _IEC1
#define _IECVEC_CMP2IE_INDEX   _IEC1
#define _IECVEC_CMP3IE_INDEX   _IEC1
#define _IECVEC_USBIE_INDEX    _IEC1
#define _IECVEC_SPI1EIE_INDEX  _IEC1
#define _IECVEC_SPI1RXIE_INDEX _IEC1
#define _IECVEC_SPI1TXIE_INDEX _IEC1
#define _IECVEC_U1EIE_INDEX    _IEC1
#define _IECVEC_U1RXIE_INDEX   _IEC1
#define _IECVEC_U1TXIE_INDEX   _IEC1
#define _IECVEC_I2C1BIE_INDEX  _IEC1
#define _IECVEC_I2C1SIE_INDEX  _IEC1
#define _IECVEC_I2C1MIE_INDEX  _IEC1
#define _IECVEC_CNAIE_INDEX    _IEC1
#define _IECVEC_CNBIE_INDEX    _IEC1
#define _IECVEC_CNCIE_INDEX    _IEC1
#define _IECVEC_PMPIE_INDEX    _IEC1
#define _IECVEC_PMPEIE_INDEX   _IEC1
#define _IECVEC_SPI2EIE_INDEX  _IEC1
#define _IECVEC_SPI2RXIE_INDEX _IEC1
#define _IECVEC_SPI2TXIE_INDEX _IEC1
#define _IECVEC_U2EIE_INDEX    _IEC1
#define _IECVEC_U2RXIE_INDEX   _IEC1
#define _IECVEC_U2TXIE_INDEX   _IEC1
#define _IECVEC_I2C2BIE_INDEX  _IEC1
#define _IECVEC_I2C2SIE_INDEX  _IEC1
#define _IECVEC_I2C2MIE_INDEX  _IEC1
#define _IECVEC_CTMUIE_INDEX   _IEC1
#define _IECVEC_DMA0IE_INDEX   _IEC1
#define _IECVEC_DMA1IE_INDEX   _IEC1
#define _IECVEC_DMA2IE_INDEX   _IEC1
#define _IECVEC_DMA3IE_INDEX   _IEC1

#define _IPC0 0x00
#define _IPC1 0x01
#define _IPC2 0x02
#define _IPC3 0x03
#define _IPC4 0x04
#define _IPC5 0x05
#define _IPC6 0x06
#define _IPC7 0x07
#define _IPC8 0x08
#define _IPC9 0x09
#define _IPC10 0x10

#define _IPCVEC_CTIP_INDEX     _IPC0
#define _IPCVEC_CS0IP_INDEX    _IPC0
#define _IPCVEC_CS1IP_INDEX    _IPC0
#define _IPCVEC_INT0IP_INDEX   _IPC0
#define _IPCVEC_T1IP_INDEX     _IPC1
#define _IPCVEC_IC1IP_INDEX    _IPC1
#define _IPCVEC_OC1IP_INDEX    _IPC1
#define _IPCVEC_INT1IP_INDEX   _IPC1
#define _IPCVEC_T2IP_INDEX     _IPC2
#define _IPCVEC_IC2IP_INDEX    _IPC2
#define _IPCVEC_OC2IP_INDEX    _IPC2
#define _IPCVEC_INT2IP_INDEX   _IPC2
#define _IPCVEC_T3IP_INDEX     _IPC3
#define _IPCVEC_IC3IP_INDEX    _IPC3
#define _IPCVEC_OC3IP_INDEX    _IPC3
#define _IPCVEC_INT3IP_INDEX   _IPC3
#define _IPCVEC_T4IP_INDEX     _IPC4
#define _IPCVEC_IC4IP_INDEX    _IPC4
#define _IPCVEC_OC4IP_INDEX    _IPC4
#define _IPCVEC_INT4IP_INDEX   _IPC4
#define _IPCVEC_T5IP_INDEX     _IPC5
#define _IPCVEC_IC5IP_INDEX    _IPC5
#define _IPCVEC_OC5IP_INDEX    _IPC5
#define _IPCVEC_AD1IP_INDEX    _IPC5
#define _IPCVEC_FSCMIP_INDEX   _IPC6
#define _IPCVEC_RTCCIP_INDEX   _IPC6
#define _IPCVEC_FCEIP_INDEX    _IPC6
#define _IPCVEC_CMP1IP_INDEX   _IPC6
#define _IPCVEC_CMP2IP_INDEX   _IPC7
#define _IPCVEC_CMP3IP_INDEX   _IPC7
#define _IPCVEC_USBIP_INDEX    _IPC7
#define _IPCVEC_SPI1IP_INDEX   _IPC7
#define _IPCVEC_U1IP_INDEX     _IPC8
#define _IPCVEC_I2C1IP_INDEX   _IPC8
#define _IPCVEC_CNIP_INDEX     _IPC8
#define _IPCVEC_PMPIP_INDEX    _IPC8
#define _IPCVEC_SPI2IP_INDEX   _IPC9
#define _IPCVEC_U2IP_INDEX     _IPC9
#define _IPCVEC_I2C2IP_INDEX   _IPC9
#define _IPCVEC_CTMUIP_INDEX   _IPC9
#define _IPCVEC_DMA0IP_INDEX   _IPC10
#define _IPCVEC_DMA1IP_INDEX   _IPC10
#define _IPCVEC_DMA2IP_INDEX   _IPC10
#define _IPCVEC_DMA3IP_INDEX   _IPC10

#define _IFS_CTIF_MASK     _IFS0_CTIF_MASK
#define _IFS_CS0IF_MASK    _IFS0_CS0IF_MASK
#define _IFS_CS1IF_MASK    _IFS0_CS1IF_MASK
#define _IFS_INT0IF_MASK   _IFS0_INT0IF_MASK
#define _IFS_T1IF_MASK     _IFS0_T1IF_MASK
#define _IFS_IC1EIF_MASK   _IFS0_IC1EIF_MASK
#define _IFS_IC1IF_MASK    _IFS0_IC1IF_MASK
#define _IFS_OC1IF_MASK    _IFS0_OC1IF_MASK
#define _IFS_INT1IF_MASK   _IFS0_INT1IF_MASK
#define _IFS_T2IF_MASK     _IFS0_T2IF_MASK
#define _IFS_IC2EIF_MASK   _IFS0_IC2EIF_MASK
#define _IFS_IC2IF_MASK    _IFS0_IC2IF_MASK
#define _IFS_OC2IF_MASK    _IFS0_OC2IF_MASK
#define _IFS_INT2IF_MASK   _IFS0_INT2IF_MASK
#define _IFS_T3IF_MASK     _IFS0_T3IF_MASK
#define _IFS_IC3EIF_MASK   _IFS0_IC3EIF_MASK
#define _IFS_IC3IF_MASK    _IFS0_IC3IF_MASK
#define _IFS_OC3IF_MASK    _IFS0_OC3IF_MASK
#define _IFS_INT3IF_MASK   _IFS0_INT3IF_MASK
#define _IFS_T4IF_MASK     _IFS0_T4IF_MASK
#define _IFS_IC4EIF_MASK   _IFS0_IC4EIF_MASK
#define _IFS_IC4IF_MASK    _IFS0_IC4IF_MASK
#define _IFS_OC4IF_MASK    _IFS0_OC4IF_MASK
#define _IFS_INT4IF_MASK   _IFS0_INT4IF_MASK
#define _IFS_T5IF_MASK     _IFS0_T5IF_MASK
#define _IFS_IC5EIF_MASK   _IFS0_IC5EIF_MASK
#define _IFS_IC5IF_MASK    _IFS0_IC5IF_MASK
#define _IFS_OC5IF_MASK    _IFS0_OC5IF_MASK
#define _IFS_AD1IF_MASK    _IFS0_AD1IF_MASK
#define _IFS_FSCMIF_MASK   _IFS0_FSCMIF_MASK
#define _IFS_RTCCIF_MASK   _IFS0_RTCCIF_MASK
#define _IFS_FCEIF_MASK    _IFS0_FCEIF_MASK
#define _IFS_CMP1IF_MASK   _IFS1_CMP1IF_MASK
#define _IFS_CMP2IF_MASK   _IFS1_CMP2IF_MASK
#define _IFS_CMP3IF_MASK   _IFS1_CMP3IF_MASK
#define _IFS_USBIF_MASK    _IFS1_USBIF_MASK
#define _IFS_SPI1EIF_MASK  _IFS1_SPI1EIF_MASK
#define _IFS_SPI1RXIF_MASK _IFS1_SPI1RXIF_MASK
#define _IFS_SPI1TXIF_MASK _IFS1_SPI1TXIF_MASK
#define _IFS_U1EIF_MASK    _IFS1_U1EIF_MASK
#define _IFS_U1RXIF_MASK   _IFS1_U1RXIF_MASK
#define _IFS_U1TXIF_MASK   _IFS1_U1TXIF_MASK
#define _IFS_I2C1BIF_MASK  _IFS1_I2C1BIF_MASK
#define _IFS_I2C1SIF_MASK  _IFS1_I2C1SIF_MASK
#define _IFS_I2C1MIF_MASK  _IFS1_I2C1MIF_MASK
#define _IFS_CNAIF_MASK    _IFS1_CNAIF_MASK
#define _IFS_CNBIF_MASK    _IFS1_CNBIF_MASK
#define _IFS_CNCIF_MASK    _IFS1_CNCIF_MASK
#define _IFS_PMPIF_MASK    _IFS1_PMPIF_MASK
#define _IFS_PMPEIF_MASK   _IFS1_PMPEIF_MASK
#define _IFS_SPI2EIF_MASK  _IFS1_SPI2EIF_MASK
#define _IFS_SPI2RXIF_MASK _IFS1_SPI2RXIF_MASK
#define _IFS_SPI2TXIF_MASK _IFS1_SPI2TXIF_MASK
#define _IFS_U2EIF_MASK    _IFS1_U2EIF_MASK
#define _IFS_U2RXIF_MASK   _IFS1_U2RXIF_MASK
#define _IFS_U2TXIF_MASK   _IFS1_U2TXIF_MASK
#define _IFS_I2C2BIF_MASK  _IFS1_I2C2BIF_MASK
#define _IFS_I2C2SIF_MASK  _IFS1_I2C2SIF_MASK
#define _IFS_I2C2MIF_MASK  _IFS1_I2C2MIF_MASK
#define _IFS_CTMUIF_MASK   _IFS1_CTMUIF_MASK
#define _IFS_DMA0IF_MASK   _IFS1_DMA0IF_MASK
#define _IFS_DMA1IF_MASK   _IFS1_DMA1IF_MASK
#define _IFS_DMA2IF_MASK   _IFS1_DMA2IF_MASK
#define _IFS_DMA3IF_MASK   _IFS1_DMA3IF_MASK

#define _IEC_CTIE_MASK     _IEC0_CTIE_MASK
#define _IEC_CS0IE_MASK    _IEC0_CS0IE_MASK
#define _IEC_CS1IE_MASK    _IEC0_CS1IE_MASK
#define _IEC_INT0IE_MASK   _IEC0_INT0IE_MASK
#define _IEC_T1IE_MASK     _IEC0_T1IE_MASK
#define _IEC_IC1EIE_MASK   _IEC0_IC1EIE_MASK
#define _IEC_IC1IE_MASK    _IEC0_IC1IE_MASK
#define _IEC_OC1IE_MASK    _IEC0_OC1IE_MASK
#define _IEC_INT1IE_MASK   _IEC0_INT1IE_MASK
#define _IEC_T2IE_MASK     _IEC0_T2IE_MASK
#define _IEC_IC2EIE_MASK   _IEC0_IC2EIE_MASK
#define _IEC_IC2IE_MASK    _IEC0_IC2IE_MASK
#define _IEC_OC2IE_MASK    _IEC0_OC2IE_MASK
#define _IEC_INT2IE_MASK   _IEC0_INT2IE_MASK
#define _IEC_T3IE_MASK     _IEC0_T3IE_MASK
#define _IEC_IC3EIE_MASK   _IEC0_IC3EIE_MASK
#define _IEC_IC3IE_MASK    _IEC0_IC3IE_MASK
#define _IEC_OC3IE_MASK    _IEC0_OC3IE_MASK
#define _IEC_INT3IE_MASK   _IEC0_INT3IE_MASK
#define _IEC_T4IE_MASK     _IEC0_T4IE_MASK
#define _IEC_IC4EIE_MASK   _IEC0_IC4EIE_MASK
#define _IEC_IC4IE_MASK    _IEC0_IC4IE_MASK
#define _IEC_OC4IE_MASK    _IEC0_OC4IE_MASK
#define _IEC_INT4IE_MASK   _IEC0_INT4IE_MASK
#define _IEC_T5IE_MASK     _IEC0_T5IE_MASK
#define _IEC_IC5EIE_MASK   _IEC0_IC5EIE_MASK
#define _IEC_IC5IE_MASK    _IEC0_IC5IE_MASK
#define _IEC_OC5IE_MASK    _IEC0_OC5IE_MASK
#define _IEC_AD1IE_MASK    _IEC0_AD1IE_MASK
#define _IEC_FSCMIE_MASK   _IEC0_FSCMIE_MASK
#define _IEC_RTCCIE_MASK   _IEC0_RTCCIE_MASK
#define _IEC_FCEIE_MASK    _IEC0_FCEIE_MASK
#define _IEC_CMP1IE_MASK   _IEC1_CMP1IE_MASK
#define _IEC_CMP2IE_MASK   _IEC1_CMP2IE_MASK
#define _IEC_CMP3IE_MASK   _IEC1_CMP3IE_MASK
#define _IEC_USBIE_MASK    _IEC1_USBIE_MASK
#define _IEC_SPI1EIE_MASK  _IEC1_SPI1EIE_MASK
#define _IEC_SPI1RXIE_MASK _IEC1_SPI1RXIE_MASK
#define _IEC_SPI1TXIE_MASK _IEC1_SPI1TXIE_MASK
#define _IEC_U1EIE_MASK    _IEC1_U1EIE_MASK
#define _IEC_U1RXIE_MASK   _IEC1_U1RXIE_MASK
#define _IEC_U1TXIE_MASK   _IEC1_U1TXIE_MASK
#define _IEC_I2C1BIE_MASK  _IEC1_I2C1BIE_MASK
#define _IEC_I2C1SIE_MASK  _IEC1_I2C1SIE_MASK
#define _IEC_I2C1MIE_MASK  _IEC1_I2C1MIE_MASK
#define _IEC_CNAIE_MASK    _IEC1_CNAIE_MASK
#define _IEC_CNBIE_MASK    _IEC1_CNBIE_MASK
#define _IEC_CNCIE_MASK    _IEC1_CNCIE_MASK
#define _IEC_PMPIE_MASK    _IEC1_PMPIE_MASK
#define _IEC_PMPEIE_MASK   _IEC1_PMPEIE_MASK
#define _IEC_SPI2EIE_MASK  _IEC1_SPI2EIE_MASK
#define _IEC_SPI2RXIE_MASK _IEC1_SPI2RXIE_MASK
#define _IEC_SPI2TXIE_MASK _IEC1_SPI2TXIE_MASK
#define _IEC_U2EIE_MASK    _IEC1_U2EIE_MASK
#define _IEC_U2RXIE_MASK   _IEC1_U2RXIE_MASK
#define _IEC_U2TXIE_MASK   _IEC1_U2TXIE_MASK
#define _IEC_I2C2BIE_MASK  _IEC1_I2C2BIE_MASK
#define _IEC_I2C2SIE_MASK  _IEC1_I2C2SIE_MASK
#define _IEC_I2C2MIE_MASK  _IEC1_I2C2MIE_MASK
#define _IEC_CTMUIE_MASK   _IEC1_CTMUIE_MASK
#define _IEC_DMA0IE_MASK   _IEC1_DMA0IE_MASK
#define _IEC_DMA1IE_MASK   _IEC1_DMA1IE_MASK
#define _IEC_DMA2IE_MASK   _IEC1_DMA2IE_MASK
#define _IEC_DMA3IE_MASK   _IEC1_DMA3IE_MASK

#define _IPC_CTIS_POSITION   _IPC0_CTIS_POSITION
#define _IPC_CTIP_POSITION   _IPC0_CTIP_POSITION
#define _IPC_CS0IS_POSITION  _IPC0_CS0IS_POSITION
#define _IPC_CS0IP_POSITION  _IPC0_CS0IP_POSITION
#define _IPC_CS1IS_POSITION  _IPC0_CS1IS_POSITION
#define _IPC_CS1IP_POSITION  _IPC0_CS1IP_POSITION
#define _IPC_INT0IS_POSITION _IPC0_INT0IS_POSITION
#define _IPC_INT0IP_POSITION _IPC0_INT0IP_POSITION
#define _IPC_T1IS_POSITION   _IPC1_T1IS_POSITION
#define _IPC_T1IP_POSITION   _IPC1_T1IP_POSITION
#define _IPC_IC1IS_POSITION  _IPC1_IC1IS_POSITION
#define _IPC_IC1IP_POSITION  _IPC1_IC1IP_POSITION
#define _IPC_OC1IS_POSITION  _IPC1_OC1IS_POSITION
#define _IPC_OC1IP_POSITION  _IPC1_OC1IP_POSITION
#define _IPC_INT1IS_POSITION _IPC1_INT1IS_POSITION
#define _IPC_INT1IP_POSITION _IPC1_INT1IP_POSITION
#define _IPC_T2IS_POSITION   _IPC2_T2IS_POSITION
#define _IPC_T2IP_POSITION   _IPC2_T2IP_POSITION
#define _IPC_IC2IS_POSITION  _IPC2_IC2IS_POSITION
#define _IPC_IC2IP_POSITION  _IPC2_IC2IP_POSITION
#define _IPC_OC2IS_POSITION  _IPC2_OC2IS_POSITION
#define _IPC_OC2IP_POSITION  _IPC2_OC2IP_POSITION
#define _IPC_INT2IS_POSITION _IPC2_INT2IS_POSITION
#define _IPC_INT2IP_POSITION _IPC2_INT2IP_POSITION
#define _IPC_T3IS_POSITION   _IPC3_T3IS_POSITION
#define _IPC_T3IP_POSITION   _IPC3_T3IP_POSITION
#define _IPC_IC3IS_POSITION  _IPC3_IC3IS_POSITION
#define _IPC_IC3IP_POSITION  _IPC3_IC3IP_POSITION
#define _IPC_OC3IS_POSITION  _IPC3_OC3IS_POSITION
#define _IPC_OC3IP_POSITION  _IPC3_OC3IP_POSITION
#define _IPC_INT3IS_POSITION _IPC3_INT3IS_POSITION
#define _IPC_INT3IP_POSITION _IPC3_INT3IP_POSITION
#define _IPC_T4IS_POSITION   _IPC4_T4IS_POSITION
#define _IPC_T4IP_POSITION   _IPC4_T4IP_POSITION
#define _IPC_IC4IS_POSITION  _IPC4_IC4IS_POSITION
#define _IPC_IC4IP_POSITION  _IPC4_IC4IP_POSITION
#define _IPC_OC4IS_POSITION  _IPC4_OC4IS_POSITION
#define _IPC_OC4IP_POSITION  _IPC4_OC4IP_POSITION
#define _IPC_INT4IS_POSITION _IPC4_INT4IS_POSITION
#define _IPC_INT4IP_POSITION _IPC4_INT4IP_POSITION
#define _IPC_T5IS_POSITION   _IPC5_T5IS_POSITION
#define _IPC_T5IP_POSITION   _IPC5_T5IP_POSITION
#define _IPC_IC5IS_POSITION  _IPC5_IC5IS_POSITION
#define _IPC_IC5IP_POSITION  _IPC5_IC5IP_POSITION
#define _IPC_OC5IS_POSITION  _IPC5_OC5IS_POSITION
#define _IPC_OC5IP_POSITION  _IPC5_OC5IP_POSITION
#define _IPC_AD1IS_POSITION  _IPC5_AD1IS_POSITION
#define _IPC_AD1IP_POSITION  _IPC5_AD1IP_POSITION
#define _IPC_FSCMIS_POSITION _IPC6_FSCMIS_POSITION
#define _IPC_FSCMIP_POSITION _IPC6_FSCMIP_POSITION
#define _IPC_RTCCIS_POSITION _IPC6_RTCCIS_POSITION
#define _IPC_RTCCIP_POSITION _IPC6_RTCCIP_POSITION
#define _IPC_FCEIS_POSITION  _IPC6_FCEIS_POSITION
#define _IPC_FCEIP_POSITION  _IPC6_FCEIP_POSITION
#define _IPC_CMP1IS_POSITION _IPC6_CMP1IS_POSITION
#define _IPC_CMP1IP_POSITION _IPC6_CMP1IP_POSITION
#define _IPC_CMP2IS_POSITION _IPC7_CMP2IS_POSITION
#define _IPC_CMP2IP_POSITION _IPC7_CMP2IP_POSITION
#define _IPC_CMP3IS_POSITION _IPC7_CMP3IS_POSITION
#define _IPC_CMP3IP_POSITION _IPC7_CMP3IP_POSITION
#define _IPC_USBIS_POSITION  _IPC7_USBIS_POSITION
#define _IPC_USBIP_POSITION  _IPC7_USBIP_POSITION
#define _IPC_SPI1IS_POSITION _IPC7_SPI1IS_POSITION
#define _IPC_SPI1IP_POSITION _IPC7_SPI1IP_POSITION
#define _IPC_U1IS_POSITION   _IPC8_U1IS_POSITION
#define _IPC_U1IP_POSITION   _IPC8_U1IP_POSITION
#define _IPC_I2C1IS_POSITION _IPC8_I2C1IS_POSITION
#define _IPC_I2C1IP_POSITION _IPC8_I2C1IP_POSITION
#define _IPC_CNIS_POSITION   _IPC8_CNIS_POSITION
#define _IPC_CNIP_POSITION   _IPC8_CNIP_POSITION
#define _IPC_PMPIS_POSITION  _IPC8_PMPIS_POSITION
#define _IPC_PMPIP_POSITION  _IPC8_PMPIP_POSITION
#define _IPC_SPI2IS_POSITION _IPC9_SPI2IS_POSITION
#define _IPC_SPI2IP_POSITION _IPC9_SPI2IP_POSITION
#define _IPC_U2IS_POSITION   _IPC9_U2IS_POSITION
#define _IPC_U2IP_POSITION   _IPC9_U2IP_POSITION
#define _IPC_I2C2IS_POSITION _IPC9_I2C2IS_POSITION
#define _IPC_I2C2IP_POSITION _IPC9_I2C2IP_POSITION
#define _IPC_CTMUIS_POSITION _IPC9_CTMUIS_POSITION
#define _IPC_CTMUIP_POSITION _IPC9_CTMUIP_POSITION
#define _IPC_DMA0IS_POSITION _IPC10_DMA0IS_POSITION
#define _IPC_DMA0IP_POSITION _IPC10_DMA0IP_POSITION
#define _IPC_DMA1IS_POSITION _IPC10_DMA1IS_POSITION
#define _IPC_DMA1IP_POSITION _IPC10_DMA1IP_POSITION
#define _IPC_DMA2IS_POSITION _IPC10_DMA2IS_POSITION
#define _IPC_DMA2IP_POSITION _IPC10_DMA2IP_POSITION
#define _IPC_DMA3IS_POSITION _IPC10_DMA3IS_POSITION
#define _IPC_DMA3IP_POSITION _IPC10_DMA3IP_POSITION

// I2C CONSTANTS
#define _I2C_PULSE_GOBBLER_DELAY_TIME 0.00000013

// PPS CONSTANTS
#define _PPS_INVEC_MAX  46
#define _PPS_OUTVEC_MAX 37

// PPS INPUT GROUPS
#define _PPS_INPUT_GROUP_0        0x00000000 // (15 << _PPS_INPUT_GROUP_POSITION[ = 8])
#define _PPS_INPUT_GROUP_1        0x00000100 // (1  << _PPS_INPUT_GROUP_POSITION[ = 8])
#define _PPS_INPUT_GROUP_2        0x00000200 // (2  << _PPS_INPUT_GROUP_POSITION[ = 8])
#define _PPS_INPUT_GROUP_3        0x00000400 // (4  << _PPS_INPUT_GROUP_POSITION[ = 8])
#define _PPS_INPUT_GROUP_4        0x00000800 // (8  << _PPS_INPUT_GROUP_POSITION[ = 8])

// PPS OUTPUT GROUPS
#define _PPS_OUTPUT_GROUP_0        0x00000000 // (0  << _PPS_OUTPUT_GROUP_POSITION[ = 12])
#define _PPS_OUTPUT_GROUP_1        0x00001000 // (1  << _PPS_OUTPUT_GROUP_POSITION[ = 12])
#define _PPS_OUTPUT_GROUP_2        0x00002000 // (2  << _PPS_OUTPUT_GROUP_POSITION[ = 12])
#define _PPS_OUTPUT_GROUP_3        0x00004000 // (4  << _PPS_OUTPUT_GROUP_POSITION[ = 12])
#define _PPS_OUTPUT_GROUP_4        0x00008000 // (8  << _PPS_OUTPUT_GROUP_POSITION[ = 12])

// PPS VALUES
#define _PPS_VALUE_0        0x00000000 // (0  << _PPS_TYPE_POSITION[ = 18])
#define _PPS_VALUE_1        0x00040000 // (1  << _PPS_TYPE_POSITION[ = 18])
#define _PPS_VALUE_2        0x00080000 // (2  << _PPS_TYPE_POSITION[ = 18])
#define _PPS_VALUE_3        0x000C0000 // (3  << _PPS_TYPE_POSITION[ = 18])
#define _PPS_VALUE_4        0x00100000 // (4  << _PPS_TYPE_POSITION[ = 18])
#define _PPS_VALUE_5        0x00140000 // (5  << _PPS_TYPE_POSITION[ = 18])
#define _PPS_VALUE_6        0x00180000 // (6  << _PPS_TYPE_POSITION[ = 18])
#define _PPS_VALUE_7        0x001C0000 // (7  << _PPS_TYPE_POSITION[ = 18])

// PPS VECTOR INDEXES
#define _PPS_VECTOR_INDEX_0  0
#define _PPS_VECTOR_INDEX_1  1
#define _PPS_VECTOR_INDEX_2  2
#define _PPS_VECTOR_INDEX_3  3
#define _PPS_VECTOR_INDEX_4  4
#define _PPS_VECTOR_INDEX_5  5
#define _PPS_VECTOR_INDEX_6  6
#define _PPS_VECTOR_INDEX_7  7
#define _PPS_VECTOR_INDEX_8  8
#define _PPS_VECTOR_INDEX_9  9
#define _PPS_VECTOR_INDEX_10 10
#define _PPS_VECTOR_INDEX_11 11
#define _PPS_VECTOR_INDEX_12 12
#define _PPS_VECTOR_INDEX_13 13
#define _PPS_VECTOR_INDEX_14 14
#define _PPS_VECTOR_INDEX_15 15
#define _PPS_VECTOR_INDEX_16 16
#define _PPS_VECTOR_INDEX_17 17
#define _PPS_VECTOR_INDEX_18 18
#define _PPS_VECTOR_INDEX_19 19
#define _PPS_VECTOR_INDEX_20 20
#define _PPS_VECTOR_INDEX_21 21
#define _PPS_VECTOR_INDEX_22 22
#define _PPS_VECTOR_INDEX_23 23
#define _PPS_VECTOR_INDEX_24 24
#define _PPS_VECTOR_INDEX_25 25
#define _PPS_VECTOR_INDEX_26 26
#define _PPS_VECTOR_INDEX_27 27
#define _PPS_VECTOR_INDEX_28 28
#define _PPS_VECTOR_INDEX_29 29
#define _PPS_VECTOR_INDEX_30 30
#define _PPS_VECTOR_INDEX_31 31
#define _PPS_VECTOR_INDEX_32 32
#define _PPS_VECTOR_INDEX_33 33
#define _PPS_VECTOR_INDEX_34 34
#define _PPS_VECTOR_INDEX_35 35
#define _PPS_VECTOR_INDEX_36 36
#define _PPS_VECTOR_INDEX_37 37
#define _PPS_VECTOR_INDEX_38 38
#define _PPS_VECTOR_INDEX_39 39
#define _PPS_VECTOR_INDEX_40 40
#define _PPS_VECTOR_INDEX_41 41
#define _PPS_VECTOR_INDEX_42 42
#define _PPS_VECTOR_INDEX_43 43
#define _PPS_VECTOR_INDEX_44 44
#define _PPS_VECTOR_INDEX_45 45
#define _PPS_VECTOR_INDEX_46 46
#define _PPS_VECTOR_INDEX_47 47
#define _PPS_VECTOR_INDEX_48 48

// PPS PORT PINS
#define RPA0            (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_0)
#define RPA1            (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_2 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_1)
#define RPA2            (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_2)
#define RPA3            (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_3)
#define RPA4            (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_2 | _PPS_VECTOR_INDEX_4)
// #define RPA8            (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_2 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_5 | _PPS_VECTOR_INDEX_8)
// #define RPA9            (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_2 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_7 | _PPS_VECTOR_INDEX_9)
#define RPB0            (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_2 | _PPS_VECTOR_INDEX_11)
#define RPB1            (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_2 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_2 | _PPS_VECTOR_INDEX_12)
#define RPB2            (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_4 | _PPS_VECTOR_INDEX_13)
#define RPB3            (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_1 | _PPS_VECTOR_INDEX_14)
#define RPB4            (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_2 | _PPS_VECTOR_INDEX_15)
#define RPB5            (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_2 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_1 | _PPS_VECTOR_INDEX_16)
// #define RPB6            (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_1 | _PPS_VECTOR_INDEX_17)
#define RPB7            (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_4 | _PPS_VECTOR_INDEX_18)
#define RPB8            (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_2 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_4 | _PPS_VECTOR_INDEX_19)
#define RPB9            (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_4 | _PPS_VECTOR_INDEX_20)
#define RPB10           (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_3 | _PPS_VECTOR_INDEX_21)
#define RPB11           (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_2 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_3 | _PPS_VECTOR_INDEX_22)
#define RPB13           (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_3 | _PPS_VECTOR_INDEX_24)
#define RPB14           (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_1 | _PPS_VECTOR_INDEX_25)
#define RPB15           (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_3 | _PPS_VECTOR_INDEX_26)
// #define RPC0            (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_6 | _PPS_VECTOR_INDEX_27)
// #define RPC1            (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_6 | _PPS_VECTOR_INDEX_28)
// #define RPC2            (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_6 | _PPS_VECTOR_INDEX_29)
// #define RPC3            (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_7 | _PPS_VECTOR_INDEX_30)
// #define RPC4            (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_7 | _PPS_VECTOR_INDEX_31)
// #define RPC5            (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_7 | _PPS_VECTOR_INDEX_32)
// #define RPC6            (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_5 | _PPS_VECTOR_INDEX_33)
// #define RPC7            (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_5 | _PPS_VECTOR_INDEX_34)
// #define RPC8            (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_2 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_6 | _PPS_VECTOR_INDEX_35)
// #define RPC9            (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_PORT_PIN | _PPS_VALUE_5 | _PPS_VECTOR_INDEX_36)

// PPS INPUTS
#define INT1             (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_0)
#define INT2             (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_1)
#define INT3             (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_2)
#define INT4             (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_3)
#define T2CK             (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_5)
#define T3CK             (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_6)
#define T4CK             (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_7)
#define T5CK             (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_8)
#define IC1              (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_9)
#define IC2              (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_10)
#define IC3              (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_11)
#define IC4              (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_12)
#define IC5              (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_13)
#define OCFA             (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_17)
#define OCFB             (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_18)
#define U1RX             (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_19)
#define U1CTS            (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_20)
#define U2RX             (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_21)
#define U2CTS            (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_22)
#define SDI1             (_PPS_INPUT_GROUP_2 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_32)
#define SS1              (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_33)
#define SDI2             (_PPS_INPUT_GROUP_3 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_35)
#define SS2              (_PPS_INPUT_GROUP_4 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_36)
#define REFCLKI          (_PPS_INPUT_GROUP_1 | _PPS_OUTPUT_GROUP_0 | _PPS_TYPE_INPUT | _PPS_VALUE_0 | _PPS_VECTOR_INDEX_45)

// PPS OUTPUTS
#define U1TX             (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_OUTPUT | _PPS_VALUE_1 | _PPS_VECTOR_INDEX_0)
#define U2RTS            (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_OUTPUT | _PPS_VALUE_2 | _PPS_VECTOR_INDEX_0)
#define SS1OUT           (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_OUTPUT | _PPS_VALUE_3 | _PPS_VECTOR_INDEX_0)
#define OC1              (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_OUTPUT | _PPS_VALUE_5 | _PPS_VECTOR_INDEX_0)
#define C2OUT            (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_1 | _PPS_TYPE_OUTPUT | _PPS_VALUE_7 | _PPS_VECTOR_INDEX_0)
#define OC2              (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_2 | _PPS_TYPE_OUTPUT | _PPS_VALUE_5 | _PPS_VECTOR_INDEX_0)
#define C3OUT            (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_2 | _PPS_TYPE_OUTPUT | _PPS_VALUE_7 | _PPS_VECTOR_INDEX_0)
#define OC4              (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_OUTPUT | _PPS_VALUE_5 | _PPS_VECTOR_INDEX_0)
#define OC5              (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_OUTPUT | _PPS_VALUE_6 | _PPS_VECTOR_INDEX_0)
#define REFCLKO          (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_OUTPUT | _PPS_VALUE_7 | _PPS_VECTOR_INDEX_0)
#define SDO1             (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_2 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_OUTPUT | _PPS_VALUE_3 | _PPS_VECTOR_INDEX_0)
#define SDO2             (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_2 | _PPS_OUTPUT_GROUP_3 | _PPS_TYPE_OUTPUT | _PPS_VALUE_4 | _PPS_VECTOR_INDEX_0)
#define U1RTS            (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_OUTPUT | _PPS_VALUE_1 | _PPS_VECTOR_INDEX_0)
#define U2TX             (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_OUTPUT | _PPS_VALUE_2 | _PPS_VECTOR_INDEX_0)
#define SS2OUT           (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_OUTPUT | _PPS_VALUE_4 | _PPS_VECTOR_INDEX_0)
#define OC3              (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_OUTPUT | _PPS_VALUE_5 | _PPS_VECTOR_INDEX_0)
#define C1OUT            (_PPS_INPUT_GROUP_0 | _PPS_OUTPUT_GROUP_4 | _PPS_TYPE_OUTPUT | _PPS_VALUE_7 | _PPS_VECTOR_INDEX_0)

// SYSKEY
#define SYSKEY_UNLOCK_SIZE 3
#define SYSKEY_UNLOCK_0    0x00000000
#define SYSKEY_UNLOCK_1    0xAA996655
#define SYSKEY_UNLOCK_2    0x556699AA

#define SYSKEY_LOCK_SIZE   1
#define SYSKEY_LOCK_0      0x00000000

// UART
#define _UxMODE_ON_MASK        _U1MODE_ON_MASK
#define _UxMODE_SIDL_MASK      _U1MODE_SIDL_MASK
#define _UxMODE_PDSEL_POSITION _U1MODE_PDSEL_POSITION
#define _UxSTA_URXEN_MASK      _U1STA_URXEN_MASK
#define _UxSTA_UTXEN_MASK      _U1STA_UTXEN_MASK
#define _UxSTA_UTXBF_MASK      _U1STA_UTXBF_MASK
#define _UxSTA_TRMT_MASK       _U1STA_TRMT_MASK
/**
 * I/O PORTS
 */
__asm__ volatile ("_PORTA_W = 0xBF886000");
__asm__ volatile (".global _PORTA_W");
__asm__ volatile ("_PORTB_W = 0xBF886100");
__asm__ volatile (".global _PORTB_W");

/**
 * Interrupt
 */
__asm__ volatile ("_INT_W = 0xBF881000");
__asm__ volatile (".global _INT_W");

/**
 * I2C
 */
__asm__ volatile ("_I2C1_W = 0xBF885000");
__asm__ volatile (".global _I2C1_W");
__asm__ volatile ("_I2C2_W = 0xBF885100");
__asm__ volatile (".global _I2C2_W");

/**
 * Configuration Bits
 */
__asm__ volatile ("_DEVCFG_W = 0xBF80F200");
__asm__ volatile (".global _DEVCFG_W");

/**
 * PPS
 */
__asm__ volatile ("_PPS_IN_W = 0xBF80FA04");
__asm__ volatile (".global _PPS_IN_W");

__asm__ volatile ("_PPS_OUT_W = 0xBF80FB00");
__asm__ volatile (".global _PPS_OUT_W");

/**
 * UART
 */
__asm__ volatile ("_UART1_W = 0xBF806000");
__asm__ volatile (".global _UART1_W");

__asm__ volatile ("_UART2_W = 0xBF806200");
__asm__ volatile (".global _UART2_W");

namespace Antipode {

    extern volatile PortRegister PORTA_W __asm__("_PORTA_W") __attribute__((section("sfrs")));
    PhysicalPort portA = PhysicalPort(PORTA_W);

    extern volatile PortRegister PORTB_W __asm__("_PORTB_W") __attribute__((section("sfrs")));
    PhysicalPort portB = PhysicalPort(PORTB_W);

    extern volatile InterruptRegister<_IFSVEC_MAX, _IECVEC_MAX, _IPCVEC_MAX> INT_W __asm__("_INT_W") __attribute__((section("sfrs")));
    InterruptController<_IFSVEC_MAX, _IECVEC_MAX, _IPCVEC_MAX> interruptController = InterruptController<_IFSVEC_MAX, _IECVEC_MAX, _IPCVEC_MAX>(INT_W, _INTCON_MVEC_MASK);

    extern volatile I2cRegister I2C1_W __asm__("_I2C1_W") __attribute__((section("sfrs")));
    OutputBit sda1 = OutputBit(portB, BIT_9, false);
    OutputBit scl1 = OutputBit(portB, BIT_8, false);
    I2cModule i2c1 = I2cModule(I2C1_W, sda1, scl1, _I2C_PULSE_GOBBLER_DELAY_TIME);

    extern volatile I2cRegister I2C2_W __asm__("_I2C2_W") __attribute__((section("sfrs")));
    OutputBit sda2 = OutputBit(portB, BIT_2, false);
    OutputBit scl2 = OutputBit(portB, BIT_3, false);
    I2cModule i2c2 = I2cModule(I2C2_W, sda2, scl2, _I2C_PULSE_GOBBLER_DELAY_TIME);

    CoreTimer coreTimer = CoreTimer(_IFSVEC_CTIF_INDEX, _IECVEC_CTIE_INDEX, _IPCVEC_CTIP_INDEX, _IFS_CTIF_MASK, _IEC_CTIE_MASK, _IPC_CTIP_POSITION, _IPC_CTIS_POSITION);

    extern volatile ConfigurationBitsRegister DEVCFG_W __asm__("_DEVCFG_W") __attribute__((section("sfrs")));

    ConfigController configController = ConfigController(DEVCFG_W, 1, (uint32[]) {
        SYSKEY_UNLOCK_0, SYSKEY_UNLOCK_1, SYSKEY_UNLOCK_2
    }, SYSKEY_UNLOCK_SIZE, (uint32[]) {
        SYSKEY_LOCK_0
    }, SYSKEY_LOCK_SIZE, &interruptController);

    extern volatile PeripheralPinSelectRegister<_PPS_INVEC_MAX> PPS_IN_W __asm__("_PPS_IN_W") __attribute__((section("sfrs")));
    extern volatile PeripheralPinSelectRegister<_PPS_OUTVEC_MAX> PPS_OUT_W __asm__("_PPS_OUT_W") __attribute__((section("sfrs")));
    PeripheralPinSelectController<_PPS_INVEC_MAX, _PPS_OUTVEC_MAX> peripheralPinSelectController = PeripheralPinSelectController<_PPS_INVEC_MAX, _PPS_OUTVEC_MAX>(PPS_IN_W, _PPS_INVEC_MAX, PPS_OUT_W, _PPS_OUTVEC_MAX, configController);

    UartBits uartBits = {
        _UxMODE_ON_MASK, // modeOnMask
        _UxMODE_SIDL_MASK, // modeSidlmask
        _UxMODE_PDSEL_POSITION, // modePdselPosition
        _UxSTA_URXEN_MASK, // staRxEnMask
        _UxSTA_UTXEN_MASK, // staTxEnMask
        _UxSTA_UTXBF_MASK, // staUtxbfMask
        _UxSTA_TRMT_MASK //staTrmtMask
    };

    extern volatile UartRegister UART1_W __asm__("_UART1_W") __attribute__((section("sfrs")));
    extern volatile UartRegister UART2_W __asm__("_UART2_W") __attribute__((section("sfrs")));
    UartModule uart1 = UartModule(UART1_W, configController, uartBits);
    UartModule uart2 = UartModule(UART2_W, configController, uartBits);


#define _PPS_INVEC_MAX  46
#define _PPS_OUTVEC_MAX 37


}

#endif	/* P32MX2XXFXXXB_H */