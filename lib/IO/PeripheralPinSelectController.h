/**
 *
 * PeripheralPinSelectController
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef PERIPHERALPINSELECTCONTROLLER_H
#define	PERIPHERALPINSELECTCONTROLLER_H

#include <Registers.h>
#include <IOException.h>

namespace Antipode {

    template <uint32 PPS_INVEC_MAX, uint32 PPS_OUTVEC_MAX> class PeripheralPinSelectController {
    public:

        template <uint32 MAPPER_PPS_INVEC_MAX, uint32 MAPPER_PPS_OUTVEC_MAX> class Mapper {
            friend class PeripheralPinSelectController;
        public:

            /**
             * Ends the mapping
             * @param autoEnableGlobalInterrupt if true enable global interrupt 
             *                                  after locking OSCCON
             * @param multivectorMode used only if 'enableGlobalInterrupt' is true, 
             *                        enables (if true) the multivector mode
             */
            void end(bool autoEnableGlobalInterrupt = true, bool multivectorMode = true) {
                // Set the IOLOCK bit
                configController.setIoLock();
                // Lock the OSCON register
                configController.lockOscCon(autoEnableGlobalInterrupt, multivectorMode);
            }

            /**
             * Maps 'input' function to 'rpn' pin.
             * @param rpn the gpio
             * @param input the input function
             * @return this instance
             * @throws IOException if and invalid 'rpn'/'input' is passed or if 
             *         requested function is not assignable to selected pin.
             */
            Mapper<MAPPER_PPS_INVEC_MAX, MAPPER_PPS_OUTVEC_MAX> & asInput(uint32 gpio, uint32 input) {

                // Check that the value passed to be sure that is in array bounds
                if ((input & _PPS_VECTOR_MASK) >= ppsInVecMax) {
                    throw IOException(PPS_INPUT_OUT_OF_RANGE_CODE, PPS_INPUT_OUT_OF_RANGE_MESSAGE);
                }

                // Check that 'gpio' is a real gpio
                if ((gpio & _PPS_TYPE_MASK) != _PPS_TYPE_PORT_PIN) {
                    throw IOException(PPS_NOT_A_GPIO_CODE, PPS_NOT_A_GPIO_MESSAGE);
                }

                // Check that 'input' is a real input
                if ((input & _PPS_TYPE_MASK) != _PPS_TYPE_INPUT) {
                    throw IOException(PPS_NOT_A_INPUT_CODE, PPS_NOT_A_INPUT_MESSAGE);
                }

                // Check that the two groups are compatible
                if (((gpio & _PPS_INPUT_GROUP_MASK) & (input & _PPS_INPUT_GROUP_MASK)) == 0) {
                    throw IOException(PPS_DIFFERENT_INPUT_GROUP_CODE, PPS_DIFFERENT_INPUT_GROUP_MESSAGE);
                }
                // Do the mapping
                in.pps[input & _PPS_VECTOR_MASK].base = ((gpio & _PPS_VALUE_MASK) >> RegisterUtils::getLsbPosition(_PPS_VALUE_MASK));
                // Return the instance
                return *this;
            }

            /**
             * Maps 'output' function to 'rpn' pin.
             * @param rpn the gpio
             * @param output the output function
             * @return this instance
             * @throws IOException if and invalid 'rpn'/'output' is passed or if 
             *         requested function is not assignable to selected pin.
             */
            Mapper<MAPPER_PPS_INVEC_MAX, MAPPER_PPS_OUTVEC_MAX> asOutput(uint32 gpio, uint32 output) {

                // Check that the value passed to be sure that is in array bounds
                if ((gpio & _PPS_VECTOR_MASK) >= ppsOutVecMax) {
                    throw IOException(PPS_OUTPUT_OUT_OF_RANGE_CODE, PPS_OUTPUT_OUT_OF_RANGE_MESSAGE);
                }

                // Check that 'gpio' is a real gpio
                if ((gpio & _PPS_TYPE_MASK) != _PPS_TYPE_PORT_PIN) {
                    throw IOException(PPS_NOT_A_GPIO_CODE, PPS_NOT_A_GPIO_MESSAGE);
                }

                // Check that 'output' is a real output
                if ((output & _PPS_TYPE_MASK) != _PPS_TYPE_OUTPUT) {
                    throw IOException(PPS_NOT_A_OUTPUT_CODE, PPS_NOT_A_OUTPUT_MESSAGE);
                }

                // Check that the two groups are compatible
                if (((gpio & _PPS_OUTPUT_GROUP_MASK) & (output & _PPS_OUTPUT_GROUP_MASK)) == 0) {
                    throw IOException(PPS_DIFFERENT_OUTPUT_GROUP_CODE, PPS_DIFFERENT_OUTPUT_GROUP_MESSAGE);
                }
                // Do the mapping
                out.pps[gpio & _PPS_VECTOR_MASK].base = ((output & _PPS_VALUE_MASK) >> RegisterUtils::getLsbPosition(_PPS_VALUE_MASK));
                // Return the instance
                return *this;
            }

            /**
             * Disconnect the output function (if any) from selected pin.
             * @param rpn the gpio
             * @return this instance
             * @throws IOException if and invalid 'rpn' is passed
             */
            Mapper<MAPPER_PPS_INVEC_MAX, MAPPER_PPS_OUTVEC_MAX> disconnectOutput(uint32 gpio) {
                // Check that the value passed to be sure that is in array bounds
                if ((gpio & _PPS_VECTOR_MASK) >= ppsOutVecMax) {
                    throw IOException(PPS_INPUT_OUT_OF_RANGE_CODE, PPS_INPUT_OUT_OF_RANGE_MESSAGE);
                }

                // Check that 'gpio' is a real gpio
                if ((gpio & _PPS_TYPE_MASK) != _PPS_TYPE_PORT_PIN) {
                    throw IOException(PPS_NOT_A_GPIO_CODE, PPS_NOT_A_GPIO_MESSAGE);
                }
                // Undo the mapping (set as 0)
                out.pps[gpio & _PPS_VECTOR_MASK].base = 0;
                // Return the instance
                return *this;
            }

        private:

            Mapper(volatile PeripheralPinSelectRegister<MAPPER_PPS_INVEC_MAX> & in, uint32 ppsInVecMax, volatile PeripheralPinSelectRegister<MAPPER_PPS_OUTVEC_MAX> & out, uint32 ppsOutVecMax, volatile ConfigController & configController) : in(in), ppsInVecMax(ppsInVecMax), out(out), ppsOutVecMax(ppsOutVecMax), configController(configController) {
            }
            // The pps input register
            volatile PeripheralPinSelectRegister<MAPPER_PPS_INVEC_MAX> & in;
            // The pps input vector size
            uint32 ppsInVecMax;
            // The pps output register
            volatile PeripheralPinSelectRegister<MAPPER_PPS_OUTVEC_MAX> & out;
            // The pps output vector size
            uint32 ppsOutVecMax;
            // The config controller
            volatile ConfigController & configController;
        };

        /**
         * Builds a Peripheral Pin Select controller starting from a pps input 
         * and output register.
         * @param in the input register
         * @param in the output register
         */
        PeripheralPinSelectController(volatile PeripheralPinSelectRegister<PPS_INVEC_MAX> & in, uint32 ppsInVecMax, volatile PeripheralPinSelectRegister<PPS_OUTVEC_MAX> & out, uint32 ppsOutVecMax, volatile ConfigController & configController) : configController(configController), mapper(Mapper<PPS_INVEC_MAX, PPS_OUTVEC_MAX>(in, ppsInVecMax, out, ppsOutVecMax, configController)) {
        }

        /**
         * Starts the mapping
         * @return a mapper
         */
        Mapper<PPS_INVEC_MAX, PPS_OUTVEC_MAX> & map() {
            // Unlock the OSCON register
            configController.unlockOscCon();
            // Clear the IOLOCK bit
            configController.clearIoLock();
            // Return the instance
            return mapper;
        }

    private:
        // The config controller
        volatile ConfigController & configController;
        // A mapper
        Mapper<PPS_INVEC_MAX, PPS_OUTVEC_MAX> mapper;

    };
}
#endif	/* PERIPHERALPINSELECTCONTROLLER_H */

