/**
 *
 * ExceptionCodes
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef EXCEPTIONCODES_H
#define	EXCEPTIONCODES_H

/**
 * Codes
 */
#define MEMORY_ERROR 0x01000000
#define IO_ERROR     0x02000000
#define TIMER_ERROR  0x03000000
#define MODULE_ERROR 0x04000000

/**
 * Memory errors
 */
#define MEMORY_ERROR_MINIMUM_HEAP_SIZE_VIOLATED_CODE (MEMORY_ERROR | 1)
#define MEMORY_ERROR_MINIMUM_HEAP_SIZE_VIOLATED_MESSAGE ((char *) "minimum heap size violated")

#define MEMORY_ERROR_NOT_ENOUGH_SPACE_TO_INITIALIZE_HEAP_CODE (MEMORY_ERROR | 2)
#define MEMORY_ERROR_NOT_ENOUGH_SPACE_TO_INITIALIZE_HEAP_MESSAGE ((char *) "not enough space to initialize heap")

#define MEMORY_ERROR_HEAP_NOT_INITIALIZED_CODE (MEMORY_ERROR | 3)
#define MEMORY_ERROR_HEAP_NOT_INITIALIZED_MESSAGE ((char *) "heap not initialized")

#define MEMORY_ERROR_INVALID_SIZE_PARAMETER_CODE (MEMORY_ERROR | 4)
#define MEMORY_ERROR_INVALID_SIZE_PARAMETER_MESSAGE ((char *) "invalid size parameter")

#define MEMORY_ERROR_INVALID_POINTER_PARAMETER_CODE (MEMORY_ERROR | 5)
#define MEMORY_ERROR_INVALID_POINTER_PARAMETER_MESSAGE ((char *) "invalid pointer parameter")

/**
 * IO errors
 */
#define IO_INVALID_BIT_PARAMETER_CODE (IO_ERROR | 1)
#define IO_INVALID_BIT_PARAMETER_MESSAGE ((char *) "invalid bit parameter")

#define PPS_INPUT_OUT_OF_RANGE_CODE (IO_ERROR | 2)
#define PPS_INPUT_OUT_OF_RANGE_MESSAGE ((char *) "pps input vector position out of range")

#define PPS_OUTPUT_OUT_OF_RANGE_CODE (IO_ERROR | 3)
#define PPS_OUTPUT_OUT_OF_RANGE_MESSAGE ((char *) "pps output vector position out of range")

#define PPS_NOT_A_GPIO_CODE (IO_ERROR | 4)
#define PPS_NOT_A_GPIO_MESSAGE ((char *) "invalid gpio passed as parameter")

#define PPS_NOT_A_INPUT_CODE (IO_ERROR | 5)
#define PPS_NOT_A_INPUT_MESSAGE ((char *) "invalid input passed as parameter")

#define PPS_NOT_A_OUTPUT_CODE (IO_ERROR | 6)
#define PPS_NOT_A_OUTPUT_MESSAGE ((char *) "invalid output passed as parameter")

#define PPS_DIFFERENT_INPUT_GROUP_CODE (IO_ERROR | 7)
#define PPS_DIFFERENT_INPUT_GROUP_MESSAGE ((char *) "gpio and input have different input group")

#define PPS_DIFFERENT_OUTPUT_GROUP_CODE (IO_ERROR | 8)
#define PPS_DIFFERENT_OUTPUT_GROUP_MESSAGE ((char *) "gpio and output have different output group")

/**
 * Timer errors
 */
#define TIMER_ERROR_INVALID_TIMEUNIT_CODE (TIMER_ERROR | 1)
#define TIMER_ERROR_INVALID_TIMEUNIT_MESSAGE ((char *) "invalid time unit")

/**
 * Module errors
 */
#define MODULE_ALREADY_OPEN_CODE (MODULE_ERROR | 1)
#define MODULE_ALREADY_OPEN_MESSAGE ((char *) "module already open")

#define MODULE_CLOSED_CODE (MODULE_ERROR | 2)
#define MODULE_CLOSED_MESSAGE ((char *) "module is closed")

#define MODULE_OPERATION_NOT_ALLOWED_WITHIN_CURRENT_CONFIG_CODE (MODULE_ERROR | 2)
#define MODULE_OPERATION_NOT_ALLOWED_WITHIN_CURRENT_CONFIG_MESSAGE ((char *) "operation not allowed within current configuration")

#endif	/* EXCEPTIONCODES_H */