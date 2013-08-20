//
// LibSourcey
// Copyright (C) 2005, Sourcey <http://sourcey.com>
//
// LibSourcey is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or (at your option) any later version.
//
// LibSourcey is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//


#ifndef SOURCEY_Net_SSLSession_H
#define SOURCEY_Net_SSLSession_H


#include "Sourcey/Memory.h"

#include "Sourcey/Net/Types.h"

#include <openssl/ssl.h>


namespace scy {
namespace net {

	
class SSLSession : public SharedObject
	/// This class encapsulates a SSL session object
	/// used with session caching on the client side.
	///
	/// For session caching to work, a client must
	/// save the session object from an existing connection,
	/// if it wants to reuse it with a future connection.
{
public:
	typedef SharedPtr<SSLSession> Ptr;

	SSL_SESSION* sslSession() const;
		/// Returns the stored OpenSSL SSL_SESSION object.

	SSLSession(SSL_SESSION* ptr);
		/// Creates a new Session object, using the given
		/// SSL_SESSION object. 
		/// 
		/// The SSL_SESSION's reference count is not changed.

	~SSLSession();
		/// Destroys the Session.
		///
		/// Calls SSL_SESSION_free() on the stored
		/// SSL_SESSION object.

	SSLSession();

protected:
	SSL_SESSION* _ptr;
};


} } // namespace scy::net


#endif // SOURCEY_Net_SSLSession_H


// Copyright (c) 2005-2006, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
//
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
