/*
 * ENonReadableChannelException.hh
 *
 *  Created on: 2013-12-16
 *      Author: cxxjava@163.com
 */

#ifndef ENONREADABLECHANNELEXCEPTION_HH_
#define ENONREADABLECHANNELEXCEPTION_HH_

#include "EIllegalStateException.hh"

namespace efc {
namespace nio {

#define ENONREADABLECHANNELEXCEPTION       ENonReadableChannelException(__FILE__, __LINE__, errno)
#define ENONREADABLECHANNELEXCEPTIONS(msg) ENonReadableChannelException(msg, __FILE__, __LINE__, errno)

/**
 * Unchecked exception thrown when an attempt is made to read
 * from a channel that was not originally opened for reading.
 */

class ENonReadableChannelException: public EIllegalStateException {
public:
	/**
	 * Constructs an <code>ENonReadableChannelException</code> with no
	 * detail message.
	 *
	 * @param   _file_   __FILE__
	 * @param   _line_   __LINE__
	 * @param   errn     errno
	 */
	ENonReadableChannelException(const char *_file_, int _line_, int errn = 0) :
		EIllegalStateException(_file_, _line_, errn) {
	}

	/**
	 * Constructs an <code>ENonReadableChannelException</code> with the
	 * specified detail message.
	 *
	 * @param   s   the detail message.
	 * @param   _file_   __FILE__.
	 * @param   _line_   __LINE__.
	 * @param   errn   the errno.
	 */
	ENonReadableChannelException(const char *s, const char *_file_, int _line_,
			int errn = 0) :
			EIllegalStateException(s, _file_, _line_, errn) {
	}
};

} /* namespace nio */
} /* namespace efc */
#endif /* ENONREADABLECHANNELEXCEPTION_HH_ */
