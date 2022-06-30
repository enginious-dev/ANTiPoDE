/**
 *
 * RuntimeException
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#include "RuntimeException.h"

Antipode::RuntimeException::RuntimeException(int code, char* message) : Antipode::AntipodeException(code, message) {

}
