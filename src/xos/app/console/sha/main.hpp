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
///   File: main.hpp
///
/// Author: $author$
///   Date: 4/3/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_SHA_MAIN_HPP
#define _XOS_APP_CONSOLE_SHA_MAIN_HPP

#include "xos/app/console/sha/main_opt.hpp"
#include "xos/crypto/hash/implemented.hpp"
#include "xos/io/crt/file/reader.hpp"
#include "xos/base/to_string.hpp"

namespace xos {
namespace app {
namespace console {
namespace sha {

typedef main_opt::implements maint_implements;
typedef main_opt maint_extends;
///////////////////////////////////////////////////////////////////////
///  Class: maint
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = maint_implements, class TExtends = maint_extends>

class _EXPORT_CLASS maint: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;
    typedef maint derives;

    typedef crypto::hash::base hash_t;
    typedef byte_array byte_array_t;
    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;

    maint(): run_(0), block_size_(64*1024) {
    }
    virtual ~maint() {
    }
private:
    maint(const maint &copy) {
    }

    int (derives::*run_)(int argc, char_t** argv, char_t** env);
    virtual int run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        if ((run_)) {
            err = (this->*run_)(argc, argv, env);
        } else {
            err = this->default_run(argc, argv, env);
        }
        return err;
    }
    virtual int default_run(int argc, char_t** argv, char_t** env) {
        int err = 0;
        if (!(err = this->version_run(argc, argv, env))) {
            this->usage(argc, argv, env);
        }
        return err;
    }

    virtual int hash_run(int argc, char_t **argv, char_t **env) {
        int err = 0;
        hash_t& hash = this->hash();

        if ((argc > optind) && (argv[optind]) && (argv[optind][0])) {
            const string_t location(argv[optind]);
            err = this->hash_source(hash, location);
        } else {
            const char_t* chars = 0;
            size_t length = 0;

            if ((chars = plain_text(length))) {
                LOG_DEBUG("...\"" << chars << "\" = plain_text(length = " << length << ")");
                err = this->hash_chars(hash, chars, length);
            } else {
                err = this->hash_chars(hash, 0,0);
            }
        }
        return err;
    }

    virtual int hash_source(hash_t& hash, const string_t& location) {
        int err = 1;
        const char_t* chars = 0;
        size_t length = 0;
        
        if ((chars = location.has_chars(length))) {
            io::crt::file::reader source;

            LOG_DEBUG("source.open(chars = \"" << chars << "\")...");
            if ((source.open(chars))) {
                LOG_DEBUG("...source.open(chars = \"" << chars << "\")");

                err = this->hash_source(hash, source);

                LOG_DEBUG("source.close() \"" << chars << "\"...");
                if ((source.close())) {
                    LOG_DEBUG("...source.close() \"" << chars << "\"");
                } else {
                    LOG_ERROR("...failed on source.close() \"" << chars << "\"");
                }
            } else {
                LOG_ERROR("...failed on source.open(chars = \"" << chars << "\")");
            }
        }
        return err;
    }
    virtual int hash_source(hash_t& hash, io::reader& source) {
        int err = 1;
        ssize_t blocksize = 0;

        if ((0 < (blocksize = this->block_size()))) {

            if ((blocksize <= (this->block().set_length(blocksize)))) {
                byte_t *block = 0;
                
                if ((block = this->block().elements())) {
                    
                    err = this->hash_source(hash, block, blocksize, source);
                }
            }
        }
        return err;
    }
    virtual int hash_source
    (hash_t& hash, byte_t* block, size_t blocksize, io::reader& source) {
        int err = 1;
        ssize_t hashsize = 0;
        size_t blockcount = 0;
        time_t t1 = 0, t2 = 0, t = 1;

        if ((0 < (hashsize = hash.hashsize())) && (0 <= (hash.initialize()))) {
            err = 0;

            ::time(&t1);
            for (ssize_t count = 0, amount = 0; 0 <= amount; count += amount, ++blockcount) {

                if (0 < (amount = source.read(block, blocksize))) {
                    if (amount != (hash.hash(block, amount))) {
                        err = 1;
                    } else {
                        ::time(&t2);
                        if ((t2 - t1) >= t) {
                            t1 = t2;
                            LOG_DEBUG("..." << (blockcount+1) << " blocks read");
                        }
                        continue;
                    }
                } else {
                    if (0 > (amount)) {
                        err = 1;
                    }
                }
                if (!(err)) {
                    err = this->hash_finalize(hash, hashsize, block, blocksize);
                }
                break;
            }
            if (!(err)) {
                LOG_DEBUG("..." << (blockcount+1) << " blocks read");
            }
        }
        return err;
    }

    virtual int hash_chars(hash_t& hash, const char_t* source, size_t length) {
        int err = 1;
        ssize_t hashsize = 0;

        if ((0 < (hashsize = hash.hashsize()))) {

            if ((hashsize <= (this->block().set_length(hashsize)))) {
                byte_t *block = 0;
                
                if ((block = this->block().elements())) {
                    
                    err = this->hash_chars
                    (hash, hashsize, block, hashsize, source, length);
                }
            }
        }
        return err;
    }
    virtual int hash_chars
    (hash_t& hash, size_t hashsize, 
     byte_t* block, size_t blocksize, const char_t* source, size_t length) {
        int err = 1;

        if ((block) && (blocksize)) {

            if ((0 <= (hash.initialize()))) {
                ssize_t count = 0;
    
                if ((source) && (length)) {
                    LOG_DEBUG("hash.hash(source = \"" << string_t(source, length) << "\", length = " << length << ")...");
                    if (length != (hash.hash(source, length))) {
                        return err = 1;
                    }
                }
                err = this->hash_finalize(hash, hashsize, block, blocksize);
            }
        }
        return err;
    }

    int (derives::*hash_finalize_)
    (hash_t& hash, ssize_t hashsize, byte_t* block, size_t blocksize);
    virtual int hash_finalize
    (hash_t& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 0;
        if ((this->hash_finalize_)) {
            err = (this->*hash_finalize_)(hash, hashsize, block, blocksize);
        } else {
            err = this->simple_hash_finalize(hash, hashsize, block, blocksize);            
        }
        return err;
    }
    virtual int simple_hash_finalize
    (hash_t& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 1;

        if (0 < (hashsize)) {
            ssize_t count = 0;

            if (hashsize == (count = hash.finalize(block, blocksize))) {
                LOG_DEBUG("..." << count << " = hash.finalize(block = " << x_to_string(block, hashsize) << ", hashsize = " << hashsize << ")");
                this->output_hash(block, count);
                err = 0;
            }
        }
        return err;
    }
    virtual int merkel_hash_finalize
    (hash_t& hash, ssize_t hashsize, byte_t* block, size_t blocksize) {
        int err = 1;

        if (0 < (hashsize)) {
            ssize_t count = 0;

            if (hashsize == (count = hash.finalize(block, blocksize))) {
                LOG_DEBUG("..." << count << " = hash.finalize(block = " << x_to_string(block, hashsize) << ", hashsize = " << hashsize << ")");

                if ((0 <= (hash.initialize()))) {

                    if (count == (hash.hash(block, count))) {
    
                        if (hashsize == (count = hash.finalize(block, hashsize))) {
                            LOG_DEBUG("..." << count << " = hash.finalize(block = " << x_to_string(block, hashsize) << ", hashsize = " << hashsize << ")");
                            this->output_hash(block, count);
                            err = 0;
                        }
                    }
                }
            }
        }
        return err;
    }
    virtual ssize_t output_hash(const void* block, size_t length) {
        if ((block) && (length)) {
            return this->outxln(block, length);
        }
        return 0;
    }

    hash_t& (derives::*hash_)();
    virtual hash_t& hash() {
        if ((this->hash_)) {
            return (this->*hash_)();
        } else {
            return this->md5();
        }
    }
    hash_t& (derives::*md5_implemented_)();
    virtual hash_t& md5() {
        if ((this->md5_implemented_)) {
            return (this->*md5_implemented_)();
        }
        return this->md5_;
    }
    hash_t& (derives::*sha1_implemented_)();
    virtual hash_t& sha1() {
        if ((this->sha1_implemented_)) {
            return (this->*sha1_implemented_)();
        }
        return this->sha1_;
    }
    hash_t& (derives::*sha256_implemented_)();
    virtual hash_t& sha256() {
        if ((this->sha256_implemented_)) {
            return (this->*sha256_implemented_)();
        }
        return this->sha256_;
    }
    hash_t& (derives::*sha512_implemented_)();
    virtual hash_t& sha512() {
        if ((this->sha512_implemented_)) {
            return (this->*sha512_implemented_)();
        }
        return this->sha512_;
    }

    virtual const char_t* plain_text(size_t& length) const {
        return this->plain_.has_chars(length);
    }
    virtual byte_array_t& block() const {
        return (byte_array_t&)this->block_;
    }
    virtual size_t block_size() const {
        return this->block_size_;
    }

    virtual void set_hash_algorithm_md5() {
        run_ = &derives::hash_run;
        hash_ = &derives::md5;
    }
    virtual void set_hash_algorithm_sha1() {
        run_ = &derives::hash_run;
        hash_ = &derives::sha1;
    }
    virtual void set_hash_algorithm_sha256() {
        run_ = &derives::hash_run;
        hash_ = &derives::sha256;
    }
    virtual void set_hash_algorithm_sha512() {
        run_ = &derives::hash_run;
        hash_ = &derives::sha512;
    }
    virtual void set_simple_hash() {
        hash_finalize_ = &derives::simple_hash_finalize;
    }
    virtual void set_merkel_hash() {
        hash_finalize_ = &derives::merkel_hash_finalize;
    }

    virtual int on_d_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_hash_algorithm_md5();
        return err;
    }
    virtual int on_1_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_hash_algorithm_sha1();
        return err;
    }
    virtual int on_2_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_hash_algorithm_sha256();
        return err;
    }
    virtual int on_5_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_hash_algorithm_sha512();
        return err;
    }
    virtual int on_hash_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            if ((!(optarg[1]) && (XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_MD5_C[0] == (optarg[0])))
                || !(chars_t::compare(optarg, XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_MD5_S))) {
                this->set_hash_algorithm_md5();
            } else {
                if ((!(optarg[1]) && (XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA1_C[0] == (optarg[0])))
                    || !(chars_t::compare(optarg, XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA1_S))) {
                    this->set_hash_algorithm_sha1();
                } else {
                    if ((!(optarg[1]) && (XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA256_C[0] == (optarg[0])))
                        || !(chars_t::compare(optarg, XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA256_S))) {
                        this->set_hash_algorithm_sha256();
                    } else {
                        if ((!(optarg[1]) && (XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA512_C[0] == (optarg[0])))
                            || !(chars_t::compare(optarg, XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA512_S))) {
                            this->set_hash_algorithm_sha512();
                        } else {
                            err = this->on_invalid_option_arg
                            (optval, optarg, optname, optind, argc, argv, env);
                        }
                    }
                }
            }
        } else {
            this->set_simple_hash();
        }
        return err;
    }
    virtual int on_merkel_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        this->set_merkel_hash();
        return err;
    }
    virtual int on_plain_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
            plain_.assign(optarg);
        }
        return err;
    }
    
protected:
    size_t block_size_;
    crypto::hash::implemented::md5 md5_;
    crypto::hash::implemented::sha1 sha1_;
    crypto::hash::implemented::sha256 sha256_;
    crypto::hash::implemented::sha512 sha512_;
    string_t plain_;
    byte_array_t block_;
}; /// class _EXPORT_CLASS maint

typedef maint<> main;

} /// namespace sha
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_SHA_MAIN_HPP 
