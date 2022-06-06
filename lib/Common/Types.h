/* 
 * File:   Types.h
 * Author: Giuseppe Milazzo
 *
 * Created on 2 giugno 2022, 11.51
 */

#ifndef TYPES_H
#define	TYPES_H

#include <stddef.h>

#define BIT_0 0x0001
#define BIT_1 0x0002
#define BIT_2 0x0004
#define BIT_3 0x0008
#define BIT_4 0x0010
#define BIT_5 0x0020
#define BIT_6 0x0040
#define BIT_7 0x0080
#define BIT_8 0x0100
#define BIT_9 0x0200
#define BIT_10 0x0400
#define BIT_11 0x0800
#define BIT_12 0x1000
#define BIT_13 0x2000
#define BIT_14 0x4000
#define BIT_15 0x8000

#define ALL 0xFFFFFFFF
#define NONE 0x00000000

namespace Antipode {

    /**
     * 
     * Custom framework types
     */
    typedef unsigned char uchar;
    typedef signed char schar;
    typedef unsigned char uint8;
    typedef signed char sint8;
    typedef unsigned short int uint16;
    typedef signed short int sint16;
    typedef unsigned int uint32;
    typedef signed int sint32;
    typedef unsigned long long uint64;
    typedef signed long long sint64;

    /**
     * 
     * Logic level values
     */
    enum LogicLevel {
        Lo,
        Hi
    };
}

#endif	/* TYPES_H */