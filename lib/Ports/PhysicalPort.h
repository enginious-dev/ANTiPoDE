/**
 *
 * PhysicalPort
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef PHYSICALPORT_H
#define	PHYSICALPORT_H

#include <Registers.h>

namespace Antipode {

    class PhysicalPort {
    public:

        /**
         * Builds a physical I/O port from a register
         * @param reg the port register
         */
        PhysicalPort(volatile PortRegister & reg);

        /**
         * Reads the ANSEL register
         * @return the ANSEL register value
         */
        uint32 getAdcStatus() const volatile;

        /**
         * Returns the status of the digital inputs. You can pass the various 
         * bits in or, in this case it returns the overall value. For example
         * consider that ANSELx contains value 5 (0101) wich means that only 
         * bit0 and bit2 are analog and all other are digital invoking it as 
         * below you will receive:
         * 
         * <pre>
         * myPort.isDigital(BIT_1); //true
         * myPort.isDigital(BIT_3); //true
         * myPort.isDigital(BIT_1 | BIT_3); //true
         * myPort.isDigital(BIT_1 | BIT_2); //false
         * </pre>
         * 
         * @param gpio the bits
         * @return true if all gpios passed are digital, otherwise false
         */
        bool isDigital(const uint32 gpio) const volatile;

        /**
         * Returns the status of the analog inputs. You can pass the various 
         * bits in or, in this case it returns the overall value. For example
         * consider that ANSELx contains value 5 (0101) wich means that only 
         * bit0 and bit2 are analog and all other are digital invoking it as 
         * below you will receive:
         * 
         * <pre>
         * myPort.isDigital(BIT_0); //true
         * myPort.isDigital(BIT_2); //true
         * myPort.isDigital(BIT_0 | BIT_2); //true
         * myPort.isDigital(BIT_0 | BIT_3); //false
         * </pre>
         * 
         * @param gpio the bits
         * @return true if all gpios passed are analog, otherwise false
         */
        bool isAnalog(const uint32 gpio) const volatile;

        /**
         * Set the selected bit as digital. You can pass the various bits in or:
         * 
         * <pre>
         * myPort.setDigital(BIT_0); //set bit0 as digital
         * myPort.setDigital(BIT_0 | BIT_2); //set bit0 and bit2 as digital
         * </pre>
         * @param gpio the bits
         */
        void setDigital(const uint32 gpio) volatile;

        /**
         * Set the selected bit as analog. You can pass the various bits in or:
         * 
         * <pre>
         * myPort.setAnalog(BIT_0); //set bit0 as analog
         * myPort.setAnalog(BIT_0 | BIT_2); //set bit0 and bit2 as analog
         * </pre>
         * @param gpio the bits
         */
        void setAnalog(const uint32 gpio) volatile;

        /**
         * Reads the TRIS register
         * @return the TRIS register value
         */
        uint32 getIoStatus() const volatile;

        /**
         * Returns the status of the inputs. You can pass the various bits in 
         * or, in this case it returns the overall value. For example consider 
         * that TRISx contains value 5 (0101) wich means that only  bit0 and 
         * bit2 are input and all other are output invoking it as  below you 
         * will receive:
         * 
         * <pre>
         * myPort.isInput(BIT_0); //true
         * myPort.isInput(BIT_2); //true
         * myPort.isInput(BIT_0 | BIT_2); //true
         * myPort.isInput(BIT_0 | BIT_3); //false
         * </pre>
         * 
         * @param gpio the bits
         * @return true if all gpios passed are inputs, otherwise false
         */
        bool isInput(const uint32 gpio) const volatile;

        /**
         * Returns the status of the outputs. You can pass the various bits in 
         * or, in this case it returns the overall value. For example consider 
         * that TRISx contains value 5 (0101) wich means that only  bit0 and 
         * bit2 are input and all other are output invoking it as  below you 
         * will receive:
         * 
         * <pre>
         * myPort.isOutput(BIT_1); //true
         * myPort.isOutput(BIT_3); //true
         * myPort.isOutput(BIT_1 | BIT_3); //true
         * myPort.isOutput(BIT_1 | BIT_2); //false
         * </pre>
         * 
         * @param gpio the bits
         * @return true if all gpios passed are outputs, otherwise false
         */
        bool isOutput(const uint32 gpio) const volatile;

        /**
         * Set the selected bit as input. You can pass the various bits in or:
         * 
         * <pre>
         * myPort.setInput(BIT_0); //set bit0 as input
         * myPort.setInput(BIT_0 | BIT_2); //set bit0 and bit2 as input
         * </pre>
         * @param gpio the bits
         */
        void setInput(const uint32 gpio) volatile;

        /**
         * Set the selected bit as output. You can pass the various bits in or:
         * 
         * <pre>
         * myPort.setOutput(BIT_0); //set bit0 as output
         * myPort.setOutput(BIT_0 | BIT_2); //set bit0 and bit2 as output
         * </pre>
         * @param gpio the bits
         */
        void setOutput(const uint32 gpio) volatile;

        /**
         * Reads the ODC register
         * @return the ODC register value
         */
        uint32 getOpenDrainStatus() const volatile;

        /**
         * Returns the status of the open drain. You can pass the various bits 
         * in or, in this case it returns the overall value. For example
         * that ODCx contains value 5 (0101) wich means that only  bit0 and 
         * bit2 are open drain and all other no invoking it as  below you 
         * will receive:
         * 
         * <pre>
         * myPort.isOpenDrainEnabled(BIT_0); //true
         * myPort.isOpenDrainEnabled(BIT_2); //true
         * myPort.isOpenDrainEnabled(BIT_0 | BIT_2); //true
         * myPort.isOpenDrainEnabled(BIT_0 | BIT_3); //false
         * </pre>
         * 
         * @param gpio the bits
         * @return true if all gpios passed are open drain enabled, otherwise 
         *         false
         */
        bool isOpenDrainEnabled(const uint32 gpio) const volatile;

        /**
         * Returns the status of the open drain. You can pass the various bits 
         * in or, in this case it returns the overall value. For example
         * that ODCx contains value 5 (0101) wich means that only  bit0 and 
         * bit2 are open drain and all other no invoking it as  below you 
         * will receive:
         * 
         * <pre>
         * myPort.isOpenDrainDisabled(BIT_1); //true
         * myPort.isOpenDrainDisabled(BIT_3); //true
         * myPort.isOpenDrainDisabled(BIT_1 | BIT_3); //true
         * myPort.isOpenDrainDisabled(BIT_1 | BIT_2); //false
         * </pre>
         * 
         * @param gpio the bits
         * @return true if all gpios passed are open drain disabled, otherwise 
         *         false
         */
        bool isOpenDrainDisabled(const uint32 gpio) const volatile;

        /**
         * Set the selected bit as open drain enabled. You can pass the various 
         * bits in or:
         * 
         * <pre>
         * myPort.setOpenDrainEnabled(BIT_0); //set bit0 as open drain enabled
         * myPort.setOpenDrainEnabled(BIT_0 | BIT_2); //set bit0 and bit2 as open drain enabled
         * </pre>
         * @param gpio the bits
         */
        void setOpenDrainEnabled(const uint32 gpio) volatile;

        /**
         * Set the selected bit as open drain disabled. You can pass the various 
         * bits in or:
         * 
         * <pre>
         * myPort.setOpenDrainDisabled(BIT_0); //set bit0 as open drain disabled
         * myPort.setOpenDrainDisabled(BIT_0 | BIT_2); //set bit0 and bit2 as open drain disabled
         * </pre>
         * @param gpio the bits
         */
        void setOpenDrainDisabled(const uint32 gpio) volatile;

        /**
         * Reads the CNPU register
         * @return the CNPU register value
         */
        uint32 getPullUpStatus() const volatile;

        /**
         * Returns the status of the pull up. You can pass the various bits in 
         * or, in this case it returns the overall value. For example assume 
         * that CNPUx contains value 5 (0101) wich means that only  bit0 and 
         * bit2 have pull-up enabled and all other no invoking it as below you 
         * will receive:
         * 
         * <pre>
         * myPort.isPullUpEnabled(BIT_0); //true
         * myPort.isPullUpEnabled(BIT_2); //true
         * myPort.isPullUpEnabled(BIT_0 | BIT_2); //true
         * myPort.isPullUpEnabled(BIT_0 | BIT_3); //false
         * </pre>
         * 
         * @param gpio the bits
         * @return true if all gpios passed have pull-up enabled, otherwise 
         *         false
         */
        bool isPullUpEnabled(const uint32 gpio) const volatile;

        /**
         * Returns the status of the pull up. You can pass the various bits in 
         * or, in this case it returns the overall value. For example assume
         * that CNPUx contains value 5 (0101) wich means that only  bit0 and 
         * bit2 have pull-up enabled and all other no invoking it as below you 
         * will receive:
         * 
         * <pre>
         * myPort.isPullUpDisabled(BIT_1); //true
         * myPort.isPullUpDisabled(BIT_3); //true
         * myPort.isPullUpDisabled(BIT_1 | BIT_3); //true
         * myPort.isPullUpDisabled(BIT_1 | BIT_2); //false
         * </pre>
         * 
         * @param gpio the bits
         * @return true if all gpios passed are open drain disabled, otherwise 
         *         false
         */
        bool isPullUpDisabled(const uint32 gpio) const volatile;

        /**
         * Enables the pull-up for the selected bit. You can pass the various 
         * bits in or:
         * 
         * <pre>
         * myPort.setPullUpEnabled(BIT_0); //enables pull-up for bit0
         * myPort.setPullUpEnabled(BIT_0 | BIT_2); //enables pull-up for bit0 and bit2
         * </pre>
         * @param gpio the bits
         */
        void setPullUpEnabled(const uint32 gpio) volatile;

        /**
         * Disables the pull-up for the selected bit. You can pass the various 
         * bits in or:
         * 
         * <pre>
         * myPort.setPullUpDisabled(BIT_0); //disables pull-up for bit0
         * myPort.setPullUpDisabled(BIT_0 | BIT_2); //disables pull-up for bit0 and bit2
         * </pre>
         * @param gpio the bits
         */
        void setPullUpDisabled(const uint32 gpio) volatile;

        /**
         * Reads the CNPD register
         * @return the CNPD register value
         */
        uint32 getPullDownStatus() const volatile;

        /**
         * Returns the status of the pull down. You can pass the various bits in 
         * or, in this case it returns the overall value. For example assume 
         * that CNPUx contains value 5 (0101) wich means that only  bit0 and 
         * bit2 have pull-down enabled and all other no invoking it as below you 
         * will receive:
         * 
         * <pre>
         * myPort.isPullDownEnabled(BIT_0); //true
         * myPort.isPullDownEnabled(BIT_2); //true
         * myPort.isPullDownEnabled(BIT_0 | BIT_2); //true
         * myPort.isPullDownEnabled(BIT_0 | BIT_3); //false
         * </pre>
         * 
         * @param gpio the bits
         * @return true if all gpios passed have pull-down enabled, otherwise 
         *         false
         */
        bool isPullDownEnabled(const uint32 gpio) const volatile;

        /**
         * Returns the status of the pull down. You can pass the various bits in 
         * or, in this case it returns the overall value. For example assume
         * that CNPUx contains value 5 (0101) wich means that only  bit0 and 
         * bit2 have pull-down enabled and all other no invoking it as below you 
         * will receive:
         * 
         * <pre>
         * myPort.isPullDownDisabled(BIT_1); //true
         * myPort.isPullDownDisabled(BIT_3); //true
         * myPort.isPullDownDisabled(BIT_1 | BIT_3); //true
         * myPort.isPullDownDisabled(BIT_1 | BIT_2); //false
         * </pre>
         * 
         * @param gpio the bits
         * @return true if all gpios passed have pull-down disabled, otherwise 
         *         false
         */
        bool isPullDownDisabled(const uint32 gpio) const volatile;

        /**
         * Enables the pull-down for the selected bit. You can pass the various 
         * bits in or:
         * 
         * <pre>
         * myPort.setPullDownEnabled(BIT_0); //enables pull-down for bit0
         * myPort.setPullDownEnabled(BIT_0 | BIT_2); //enables pull-down for bit0 and bit2
         * </pre>
         * @param gpio the bits
         */
        void setPullDownEnabled(const uint32 gpio) volatile;

        /**
         * Disables the pull-down for the selected bit. You can pass the various 
         * bits in or:
         * 
         * <pre>
         * myPort.setPullDownDisabled(BIT_0); //disables pull-down for bit0
         * myPort.setPullDownDisabled(BIT_0 | BIT_2); //disables pull-down for bit0 and bit2
         * </pre>
         * @param gpio the bits
         */
        void setPullDownDisabled(const uint32 gpio) volatile;

        /**
         * Reads the PORT register
         * @return the PORT register value
         */
        uint32 portRead() const volatile;

        /**
         * Reads a single bit from port
         * @param gpio the bit (must be at lease be power of 2)
         * @return LogicLeve.Hi if bit is Hi, otherwise LogicLevel.Lo
         * @throws IOException if and invalid bit is passed
         */
        LogicLevel portRead(const uint32 gpio) const volatile;

        /**
         * Writes on PORT register
         * @param value the value to write
         */
        void portWrite(const uint32 value) volatile;

        /**
         * Writes bits on PORT register, you can pass the various bits in or
         * @param gpio the bits
         * @param value the value
         */
        void portWrite(const uint32 gpio, const LogicLevel value) volatile;

        /**
         * Inverts bits on PORT register, you can pass the various bits in or
         * @param gpio the bits
         */
        void portInvert(const uint32 gpio) volatile;

        /**
         * Reads the LAT register
         * @return the LAT register value
         */
        uint32 latchRead() const volatile;
        /**
         * Reads a single bit from latch
         * @param gpio the bit (must be at lease be power of 2)
         * @return LogicLeve.Hi if bit is Hi, otherwise LogicLevel.Lo
         * @throws IOException if and invalid bit is passed
         */
        LogicLevel latchRead(const uint32 gpio) const volatile;

        /**
         * Writes on LAT register
         * @param value the value to write
         */
        void latchWrite(const uint32 value) volatile;

        /**
         * Writes bits on LAT register, you can pass the various bits in or
         * @param gpio the bits
         * @param value the value
         */
        void latchWrite(const uint32 gpio, const LogicLevel value) volatile;

        /**
         * Inverts bits on LAT register, you can pass the various bits in or
         * @param gpio the bits
         */
        void latchInvert(const uint32 gpio) volatile;
    private:
        volatile PortRegister & reg;
    };
}

#endif	/* PHYSICALPORT_H */

