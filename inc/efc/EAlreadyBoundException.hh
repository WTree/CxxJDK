/*
 * EAlreadyBoundException.h
 *
 *  Created on: 2013-3-14
 *      Author: cxxjava@163.com
 */

#ifndef EALREADYBOUNDEXCEPTION_HH_
#define EALREADYBOUNDEXCEPTION_HH_

#include "EException.hh"

namespace efc {

#define EALREADYBOUNDEXCEPTION       EAlreadyBoundException(__FILE__, __LINE__, errno)
#define EALREADYBOUNDEXCEPTIONS(msg) EAlreadyBoundException(msg, __FILE__, __LINE__, errno)

/**
 * An <code>AlreadyBoundException</code> is thrown if an attempt
 * is made to bind an object in the registry to a name that already
 * has an associated binding.
 *
 * @since   JDK1.1
 * @author  Ann Wollrath
 * @author  Roger Riggs
 * @see     java.rmi.Naming#bind(String, java.rmi.Remote)
 * @see     java.rmi.registry.Registry#bind(String, java.rmi.Remote)
 */

class EAlreadyBoundException: public EException {
public:
	/**
	 * Constructs an <code>EAlreadyBoundException</code> with no
	 * detail message.
	 *
	 * @param   _file_   __FILE__
	 * @param   _line_   __LINE__
	 * @param   errn     errno
	 */
	EAlreadyBoundException(const char *_file_, int _line_, int errn = 0) :
			EException(_file_, _line_, errn) {
	}

	/**
	 * Constructs an <code>EAlreadyBoundException</code> with the
	 * specified detail message.
	 *
	 * @param   s   the detail message.
	 * @param   _file_   __FILE__.
	 * @param   _line_   __LINE__.
	 * @param   errn   the errno.
	 */
	EAlreadyBoundException(const char *s, const char *_file_, int _line_, int errn =
			0) :
			EException(s, _file_, _line_, errn) {
	}
};

} /* namespace efc */
#endif /* EALREADYBOUNDEXCEPTION_HH_ */
