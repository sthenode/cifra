########################################################################
# Copyright (c) 1988-2019 $organization$
#
# This software is provided by the author and contributors ``as is''
# and any express or implied warranties, including, but not limited to,
# the implied warranties of merchantability and fitness for a particular
# purpose are disclaimed. In no event shall the author or contributors
# be liable for any direct, indirect, incidental, special, exemplary,
# or consequential damages (including, but not limited to, procurement
# of substitute goods or services; loss of use, data, or profits; or
# business interruption) however caused and on any theory of liability,
# whether in contract, strict liability, or tort (including negligence
# or otherwise) arising in any way out of the use of this software,
# even if advised of the possibility of such damage.
#
#   File: Makefile
#
# Author: $author$
#   Date: 4/5/2019
#
# generic Gcc Makefile for cifra Executable sha
########################################################################


#
# target
#
sha_EXETARGET = sha

########################################################################

#
# user c++ flags
#
sha_USRCXXFLAGS += \
${cifra_USRCXXFLAGS} \

#
# user defines
#
sha_USRDEFINES += \
${cifra_USRDEFINES} \

#
# user includes
#
sha_USRINCLUDES += \
${cifra_USRINCLUDES} \

#
# user libdirs
#
sha_USRLIBDIRS += \
${cifra_USRLIBDIRS} \

########################################################################

#
# Executable .c sources
#
#sha_EXE_C_SOURCES += \
#${CIFRA_SRC}/cifra/base/Base.c \

#
# Executable .cc sources
#
#sha_EXE_CC_SOURCES += \
#${CIFRA_SRC}/cifra/base/Base.cc \

#
# Executable .cxx sources
#
#sha_EXE_CXX_SOURCES += \
#${CIFRA_SRC}/cifra/base/Base.cxx \

#
# Executable .cpp sources
#
sha_EXE_CPP_SOURCES += \
${CIFRA_SRC}/xos/app/console/cifra/main_main.cpp \
${CIFRA_SRC}/xos/app/console/sha/main_opt.cpp \
${CIFRA_SRC}/xos/app/console/sha/main.cpp \

#
# Executable .m sources
#
#sha_EXE_M_SOURCES += \
#${CIFRA_SRC}/cifra/base/Base.m \

#
# Executable .mm sources
#
#sha_EXE_MM_SOURCES += \
#${CIFRA_SRC}/cifra/base/Base.mm \


########################################################################

#
# Executable libraries
#
sha_LIBS += \
${cifra_LIBS}
