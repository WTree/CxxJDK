/*
 * ENoConnectionPendingException.hh
 *
 *  Created on: 2013-12-18
 *      Author: cxxjava@163.com
 */

#ifndef ENOCONNECTIONPENDINGEXCEPTION_HH_
#define ENOCONNECTIONPENDINGEXCEPTION_HH_

#include "EIllegalStateException.hh"

namespace efc {
namespace nio {

#define ENOCONNECTIONPENDINGEXCEPTION        ENoConnectionPendingException(__FILE__, __LINE__, errno)
#define ENOCONNECTIONPENDINGEXCEPTIONS(msg)  ENoConnectionPendingException(msg, __FILE__, __LINE__, errno)

/**
 * Unchecked exception thrown when an attempt is made to connect a {@link
 * SocketChannel} for which a non-blocking connection operation is already in
 * progress.
 */

class ENoConnectionPendingException : public EIllegalStateException {
public:
	/**
	 * Constructs an <code>ENoConnectionPendingException</code> with no
	 * detail message.
	 *
	 * @param   _file_   __FILE__
	 * @param   _line_   __LINE__
	 * @param   errn     errno
	 */
	ENoConnectionPendingException(const char *_file_, int _line_, int errn = 0) :
		EIllegalStateException(_file_, _line_, errn) {
	}

	/**
	 * Constructs an <code>ENoConnectionPendingException</code> with the
	 * specified detail message.
	 *
	 * @param   s   the detail message.
	 * @param   _file_   __FILE__.
	 * @param   _line_   __LINE__.
	 * @param   errn   the errno.
	 */
	ENoConnectionPendingException(const char *s, const char *_file_,
			int _line_, int errn = 0) :
				EIllegalStateException(s, _file_, _line_, errn) {
	}
};

} /* namespace nio */
} /* namespace efc */
#endif /* ENOCONNECTIONPENDINGEXCEPTION_HH_ */
