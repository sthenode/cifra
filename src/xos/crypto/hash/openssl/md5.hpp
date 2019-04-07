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
///   File: md5.hpp
///
/// Author: $author$
///   Date: 4/3/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_CRYPTO_HASH_OPENSSL_MD5_HPP
#define _XOS_CRYPTO_HASH_OPENSSL_MD5_HPP

#include "xos/crypto/hash/md5.hpp"

namespace xos {
namespace crypto {
namespace hash {
namespace openssl {

typedef hash::md5::implements md5_implements;
typedef hash::md5 md5_extends;
///////////////////////////////////////////////////////////////////////
///  Class: md5
///////////////////////////////////////////////////////////////////////
class _EXPORT_CLASS md5: virtual public md5_implements, public md5_extends {
public:
    typedef md5_implements implements;
    typedef md5_extends extends;

    md5(void* out, size_t outsize, const void* in, size_t inlen) {
        if (0 > (this->operator()(out, outsize, in, inlen))) {
            error e = error_failed;
            throw (e);
        }
    }
    md5(const md5 &copy): extends(copy) {
    }
    md5() {
    }
    virtual ~md5() {
    }

protected:
    virtual void initial();
    virtual void final();
    virtual void transform();
    virtual void update(const uint8_t* in, size_t inlen);
}; /// class _EXPORT_CLASS md5

} /// namespace openssl
} /// namespace hash
} /// namespace crypto
} /// namespace xos

#endif /// _XOS_CRYPTO_HASH_OPENSSL_MD5_HPP 
