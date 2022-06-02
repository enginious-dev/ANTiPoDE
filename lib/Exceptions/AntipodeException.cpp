/**
 *
 * AntipodeException
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#include "AntipodeException.h"

Antipode::AntipodeException::AntipodeException(int code, char* message) {
    this->message = message;
    this->message = message;
}

const char* Antipode::AntipodeException::what() const throw() {
    return message;
}

const char* Antipode::AntipodeException::getMessage() const throw() {
    return what();
}

const int Antipode::AntipodeException::getCode() const {
    return code;
}

