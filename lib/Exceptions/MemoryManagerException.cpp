/**
 *
 * MemoryManagerException
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#include "MemoryManagerException.h"
#include "AntipodeException.h"

Antipode::MemoryManagerException::MemoryManagerException(int code, char* message) : Antipode::AntipodeException(code, message) {

}

