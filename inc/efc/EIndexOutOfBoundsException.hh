/*
 * EIndexOutOfBoundsException.hh
 *
 *  Created on: 2013-3-14
 *      Author: cxxjava@163.com
 */

#ifndef EINDEXOUTOFBOUNDSEXCEPTION_H_
#define EINDEXOUTOFBOUNDSEXCEPTION_H_

#include "EException.hh"

namespace efc {

#define EINDEXOUTOFBOUNDSEXCEPTION       EIndexOutOfBoundsException(__FILE__, __LINE__, errno)
#define EINDEXOUTOFBOUNDSEXCEPTIONS(msg) EIndexOutOfBoundsException(msg, __FILE__, __LINE__, errno)

/**
 * Thrown to indicate that an index of some sort (such as to an array,
 * to a string, or to a vector) is out of range. 
 * <p>
 * Applications can subclass this class to indicate similar exceptions. 
 */

class EIndexOutOfBoundsException: public EException {
public:
	/**
	 * Constructs an <code>EIndexOutOfBoundsException</code> with no
	 * detail message.
	 *
	 * @param   _file_   __FILE__
	 * @param   _line_   __LINE__
	 * @param   errn     errno
	 */
	EIndexOutOfBoundsException(const char *_file_, int _line_, int errn = 0) :
			EException(_file_, _line_, errn) {
	}

	/**
	 * Constructs an <code>EIndexOutOfBoundsException</code> with the
	 * specified detail message.
	 *
	 * @param   s   the detail message.
	 * @param   _file_   __FILE__.
	 * @param   _line_   __LINE__.
	 * @param   errn   the errno.
	 */
	EIndexOutOfBoundsException(const char *s, const char *_file_,
			int _line_, int errn = 0) :
			EException(s, _file_, _line_, errn) {
	}
};

} /* namespace efc */
#endif /* EINDEXOUTOFBOUNDSEXCEPTION_H_ */
