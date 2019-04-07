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
#   File: cifra.pri
#
# Author: $author$
#   Date: 4/3/2019
#
# QtCreator .pri file for cifra executable cifra
########################################################################

########################################################################
# cifra

# cifra_exe TARGET
#
cifra_exe_TARGET = cifra

# cifra_exe INCLUDEPATH
#
cifra_exe_INCLUDEPATH += \
$${cifra_INCLUDEPATH} \

# cifra_exe DEFINES
#
cifra_exe_DEFINES += \
$${cifra_DEFINES} \

########################################################################
# cifra_exe OBJECTIVE_HEADERS
#
#cifra_exe_OBJECTIVE_HEADERS += \
#$${CIFRA_SRC}/cifra/base/Base.hh \

# cifra_exe OBJECTIVE_SOURCES
#
#cifra_exe_OBJECTIVE_SOURCES += \
#$${CIFRA_SRC}/cifra/base/Base.mm \

########################################################################
# cifra_exe HEADERS
#
cifra_exe_HEADERS += \
$${CIFRA_SRC}/xos/app/console/cifra/main_main.hpp \
$${CIFRA_SRC}/xos/app/console/cifra/main_opt.hpp \
$${CIFRA_SRC}/xos/app/console/cifra/main.hpp \

# cifra_exe SOURCES
#
cifra_exe_SOURCES += \
$${CIFRA_SRC}/xos/app/console/cifra/main_main.cpp \
$${CIFRA_SRC}/xos/app/console/cifra/main_opt.cpp \
$${CIFRA_SRC}/xos/app/console/cifra/main.cpp \

########################################################################
# cifra_exe FRAMEWORKS
#
cifra_exe_FRAMEWORKS += \
$${cifra_FRAMEWORKS} \

# cifra_exe LIBS
#
cifra_exe_LIBS += \
$${cifra_LIBS} \


