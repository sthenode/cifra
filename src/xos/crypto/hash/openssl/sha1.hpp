///////////////////////////////////////////////////////////////////////
/// Copyright (c) 1988-2019 $organization$
///
/// This software is provided by the author and contributors ``as is'' 
/// and any express or implied warranties, including, but not limited to, 
/// the implied warranties of merchantability and fitness for a particular 
/// purpose are disclaimed. In no event shall the author or contributors 
/// be liable for any direct, indirect, incidental, special, exemplary, 
/// or consequential damages (including, but not limited to, procurement 
/// of substitute goods or services; loss of use, data, or profits; or 
/// business interruption) however caused and on any theory of liability, 
/// whether in contract, strict liability, or tort (including negligence 
/// or otherwise) arising in any way out of the use of this software, 
/// even if advised of the possibility of such damage.
///
///   File: sha1.hpp
///
/// Author: $author$
///   Date: 4/4/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CRYPTO_HASH_OPENSSL_SHA1_HPP
#define _XOS_CRYPTO_HASH_OPENSSL_SHA1_HPP

#include "xos/crypto/hash/sha1.hpp"

namespace xos {
namespace crypto {
namespace hash {
namespace openssl {

typedef hash::sha1::implements sha1_implements;
typedef hash::sha1 sha1_extends;
///////////////////////////////////////////////////////////////////////
///  Class: sha1
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS sha1: virtual public sha1_implements, public sha1_extends {
public:
    typedef sha1_implements implements;
    typedef sha1_extends extends;

    sha1(void* out, size_t outsize, const void* in, size_t inlen) {
        if (0 > (this->operator()(out, outsize, in, inlen))) {
            error e = error_failed;
            throw (e);
        }
    }
    sha1(const sha1t &copy): extends(copy) {
    }
    sha1() {
    }
    virtual ~sha1() {
    }

protected:
    virtual void initial();
    virtual void final();
    virtual void transform();
    virtual void update(const uint8_t* in, size_t inlen);
}; /// class _EXPORT_CLASS sha1t

} /// namespace openssl
} /// namespace hash
} /// namespace crypto
} /// namespace xos

#endif /// _XOS_CRYPTO_HASH_OPENSSL_SHA1_HPP 
