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
///   File: main_opt.hpp
///
/// Author: $author$
///   Date: 4/3/2019
///////////////////////////////////////////////////////////////////////
#ifndef _XOS_APP_CONSOLE_SHA_MAIN_OPT_HPP
#define _XOS_APP_CONSOLE_SHA_MAIN_OPT_HPP

#include "xos/console/lib/version/main.hpp"
#include "xos/lib/cifra/version.hpp"

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPT "hash"
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_MD5_C "m"
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_MD5_S "md5"
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA1_C "1"
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA1_S "sha1"
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA256_C "2"
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA256_S "sha256"
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA512_C "5"
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA512_S "sha512"
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_ALGS "{ " \
    "(" XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_MD5_C ")" \
        XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_MD5_S \
    " | (" XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA1_C ")" \
           XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA1_S \
    " | (" XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA256_C ")" \
           XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA256_S \
    " | (" XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA512_C ")" \
           XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_SHA512_S \
    " }"
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG ""
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTUSE "simple hash"
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTVAL_S "h"
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTVAL_C 'h'
#define XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTION \
   {XOS_APP_CONSOLE_SHA_MAIN_HASH_OPT, \
    XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPT "merkel"
#define XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTARG ""
#define XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTUSE "merkel hash"
#define XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTVAL_S "m"
#define XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTVAL_C 'm'
#define XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTION \
   {XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPT, \
    XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SHA_MAIN_D_OPT "md5"
#define XOS_APP_CONSOLE_SHA_MAIN_D_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_SHA_MAIN_D_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SHA_MAIN_D_OPTARG ""
#define XOS_APP_CONSOLE_SHA_MAIN_D_OPTUSE "md5 algorithm"
#define XOS_APP_CONSOLE_SHA_MAIN_D_OPTVAL_S "d"
#define XOS_APP_CONSOLE_SHA_MAIN_D_OPTVAL_C 'd'
#define XOS_APP_CONSOLE_SHA_MAIN_D_OPTION \
   {XOS_APP_CONSOLE_SHA_MAIN_D_OPT, \
    XOS_APP_CONSOLE_SHA_MAIN_D_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SHA_MAIN_D_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SHA_MAIN_D_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SHA_MAIN_1_OPT "sha1"
#define XOS_APP_CONSOLE_SHA_MAIN_1_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_SHA_MAIN_1_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SHA_MAIN_1_OPTARG ""
#define XOS_APP_CONSOLE_SHA_MAIN_1_OPTUSE "sha1 algorithm"
#define XOS_APP_CONSOLE_SHA_MAIN_1_OPTVAL_S "1"
#define XOS_APP_CONSOLE_SHA_MAIN_1_OPTVAL_C '1'
#define XOS_APP_CONSOLE_SHA_MAIN_1_OPTION \
   {XOS_APP_CONSOLE_SHA_MAIN_1_OPT, \
    XOS_APP_CONSOLE_SHA_MAIN_1_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SHA_MAIN_1_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SHA_MAIN_1_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SHA_MAIN_2_OPT "sha256"
#define XOS_APP_CONSOLE_SHA_MAIN_2_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_SHA_MAIN_2_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SHA_MAIN_2_OPTARG ""
#define XOS_APP_CONSOLE_SHA_MAIN_2_OPTUSE "sha256 algorithm"
#define XOS_APP_CONSOLE_SHA_MAIN_2_OPTVAL_S "2"
#define XOS_APP_CONSOLE_SHA_MAIN_2_OPTVAL_C '2'
#define XOS_APP_CONSOLE_SHA_MAIN_2_OPTION \
   {XOS_APP_CONSOLE_SHA_MAIN_2_OPT, \
    XOS_APP_CONSOLE_SHA_MAIN_2_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SHA_MAIN_2_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SHA_MAIN_2_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SHA_MAIN_5_OPT "sha512"
#define XOS_APP_CONSOLE_SHA_MAIN_5_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_NONE
#define XOS_APP_CONSOLE_SHA_MAIN_5_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SHA_MAIN_5_OPTARG ""
#define XOS_APP_CONSOLE_SHA_MAIN_5_OPTUSE "sha512 algorithm"
#define XOS_APP_CONSOLE_SHA_MAIN_5_OPTVAL_S "5"
#define XOS_APP_CONSOLE_SHA_MAIN_5_OPTVAL_C '5'
#define XOS_APP_CONSOLE_SHA_MAIN_5_OPTION \
   {XOS_APP_CONSOLE_SHA_MAIN_5_OPT, \
    XOS_APP_CONSOLE_SHA_MAIN_5_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SHA_MAIN_5_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SHA_MAIN_5_OPTVAL_C}, \

#define XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPT "plain"
#define XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTARG_REQUIRED MAIN_OPT_ARGUMENT_REQUIRED
#define XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTARG_RESULT 0
#define XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTARG ""
#define XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTUSE "plain text"
#define XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTVAL_S "p:"
#define XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTVAL_C 'p'
#define XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTION \
   {XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPT, \
    XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTARG_REQUIRED, \
    XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTARG_RESULT, \
    XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTVAL_C}, \

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_SHA_MAIN_OPTIONS_CHARS \
    XOS_APP_CONSOLE_SHA_MAIN_D_OPTVAL_S \
    XOS_APP_CONSOLE_SHA_MAIN_1_OPTVAL_S \
    XOS_APP_CONSOLE_SHA_MAIN_2_OPTVAL_S \
    XOS_APP_CONSOLE_SHA_MAIN_5_OPTVAL_S \
   XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTVAL_S \
   XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTVAL_S \
   XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTVAL_S \
   XOS_CONSOLE_MAIN_LOGGING_OPTVAL_S \
   XOS_CONSOLE_MAIN_USAGE_OPTVAL_S

#define XOS_APP_CONSOLE_SHA_MAIN_OPTIONS_OPTIONS \
    XOS_APP_CONSOLE_SHA_MAIN_D_OPTION \
    XOS_APP_CONSOLE_SHA_MAIN_1_OPTION \
    XOS_APP_CONSOLE_SHA_MAIN_2_OPTION \
    XOS_APP_CONSOLE_SHA_MAIN_5_OPTION \
   XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTION \
   XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTION \
   XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTION \
   XOS_CONSOLE_MAIN_LOGGING_OPTION \
   XOS_CONSOLE_MAIN_USAGE_OPTION

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////
#define XOS_APP_CONSOLE_SHA_MAIN_ARGS 0
#define XOS_APP_CONSOLE_SHA_MAIN_ARGV

///////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////

namespace xos {
namespace app {
namespace console {
namespace sha {

typedef xos::console::lib::version::main::implements main_optt_implements;
typedef xos::console::lib::version::maint<xos::lib::cifra::version> main_optt_extends;
///////////////////////////////////////////////////////////////////////
///  Class: main_optt
///////////////////////////////////////////////////////////////////////
template 
<class TImplements = main_optt_implements, class TExtends = main_optt_extends>

class _EXPORT_CLASS main_optt: virtual public TImplements, public TExtends {
public:
    typedef TImplements implements;
    typedef TExtends extends;

    typedef typename extends::string_t string_t;
    typedef typename extends::char_t char_t;
    
    main_optt() {
    }
    virtual ~main_optt() {
    }
private:
    main_optt(const main_optt &copy) {
    }

    virtual int on_d_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_1_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_2_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_5_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_hash_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_merkel_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }
    virtual int on_plain_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        if ((optarg) && (optarg[0])) {
        }
        return err;
    }

    virtual int on_option
    (int optval, const char_t* optarg,
     const char_t* optname, int optind,
     int argc, char_t**argv, char_t**env) {
        int err = 0;
        switch(optval) {
        case XOS_APP_CONSOLE_SHA_MAIN_D_OPTVAL_C:
            err = on_d_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SHA_MAIN_1_OPTVAL_C:
            err = on_1_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SHA_MAIN_2_OPTVAL_C:
            err = on_2_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SHA_MAIN_5_OPTVAL_C:
            err = on_5_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTVAL_C:
            err = on_hash_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTVAL_C:
            err = on_merkel_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTVAL_C:
            err = on_plain_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        case XOS_CONSOLE_MAIN_USAGE_OPTVAL_C:
            err = this->on_usage_option
            (optval, optarg, optname, optind, argc, argv, env);
            break;
        default:
            err = extends::on_option
            (optval, optarg, optname, optind, argc, argv, env);
        }
        return err;
    }
    virtual const char_t* option_usage
    (const char_t*& optarg, const struct option* longopt) {
        const char_t* chars = "";
        switch(longopt->val) {
        case XOS_APP_CONSOLE_SHA_MAIN_D_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_SHA_MAIN_D_OPTARG;
            chars = XOS_APP_CONSOLE_SHA_MAIN_D_OPTUSE;
            break;
        case XOS_APP_CONSOLE_SHA_MAIN_1_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_SHA_MAIN_1_OPTARG;
            chars = XOS_APP_CONSOLE_SHA_MAIN_1_OPTUSE;
            break;
        case XOS_APP_CONSOLE_SHA_MAIN_2_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_SHA_MAIN_2_OPTARG;
            chars = XOS_APP_CONSOLE_SHA_MAIN_2_OPTUSE;
            break;
        case XOS_APP_CONSOLE_SHA_MAIN_5_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_SHA_MAIN_5_OPTARG;
            chars = XOS_APP_CONSOLE_SHA_MAIN_5_OPTUSE;
            break;
        case XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTARG;
            chars = XOS_APP_CONSOLE_SHA_MAIN_HASH_OPTUSE;
            break;
        case XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTARG;
            chars = XOS_APP_CONSOLE_SHA_MAIN_MERKEL_OPTUSE;
            break;
        case XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTVAL_C:
            optarg = XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTARG;
            chars = XOS_APP_CONSOLE_SHA_MAIN_PLAIN_OPTUSE;
            break;
        case XOS_CONSOLE_MAIN_USAGE_OPTVAL_C:
            chars = this->usage_option_usage(optarg, longopt);
            break;
        default:
            chars = extends::option_usage(optarg, longopt);
        }
        return chars;
    }
    virtual const char_t* options(const struct option*& longopts) {
        int err = 0;
        static const char_t* chars = XOS_APP_CONSOLE_SHA_MAIN_OPTIONS_CHARS;
        static struct option optstruct[]= {
            XOS_APP_CONSOLE_SHA_MAIN_OPTIONS_OPTIONS
            {0, 0, 0, 0}};
        longopts = optstruct;
        return chars;
    }

    virtual const char_t* arguments(const char_t**& argv) {
        static const char_t* _args = XOS_APP_CONSOLE_SHA_MAIN_ARGS;
        static const char_t* _argv[] = {
            XOS_APP_CONSOLE_SHA_MAIN_ARGV
            0};
        argv = _argv;
        return _args;
    }
}; /// class _EXPORT_CLASS main_optt

typedef main_optt<> main_opt;

} /// namespace sha
} /// namespace console
} /// namespace app
} /// namespace xos

#endif /// _XOS_APP_CONSOLE_SHA_MAIN_OPT_HPP 
