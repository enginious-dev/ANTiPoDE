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
#include <I2cModule.h>
#include <CoreTimer.h>

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

#define _I2C_PULSE_GOBBLER_DELAY_TIME 0.00000013



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
}

#endif	/* P32MX2XXFXXXB_H */