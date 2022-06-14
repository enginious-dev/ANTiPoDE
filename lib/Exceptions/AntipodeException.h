/**
 *
 * AntipodeException
 * 
 * @author  Giuseppe Milazzo (giuseppe.milazzo@enginious-dev.com)
 * @since   1.0.0
 */

#ifndef ANTIPODEEXCEPTION_H
#define	ANTIPODEEXCEPTION_H

#include <exception>
#include <ExceptionCodes.h>

namespace Antipode {

    class AntipodeException : public std::exception {
    public:
        virtual const char* what() const throw();
        virtual const char* getMessage() const throw();
        virtual const int getCode() const;
    protected:
        AntipodeException(int code, char* message);
    private:
        int code;
        char * message;
    };

}

#endif	/* ANTIPODEEXCEPTION_H */

