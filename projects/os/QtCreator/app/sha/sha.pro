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
#   File: sha.pro
#
# Author: $author$
#   Date: 4/5/2019
#
# QtCreator .pro file for cifra executable sha
########################################################################
include(../../../../../build/QtCreator/cifra.pri)
include(../../../../QtCreator/cifra.pri)
include(../../cifra.pri)
include(../../../../QtCreator/app/sha/sha.pri)

TARGET = $${sha_TARGET}

########################################################################
# INCLUDEPATH
#
INCLUDEPATH += \
$${sha_INCLUDEPATH} \

# DEFINES
# 
DEFINES += \
$${sha_DEFINES} \

########################################################################
# OBJECTIVE_HEADERS
#
OBJECTIVE_HEADERS += \
$${sha_OBJECTIVE_HEADERS} \

# OBJECTIVE_SOURCES
#
OBJECTIVE_SOURCES += \
$${sha_OBJECTIVE_SOURCES} \

########################################################################
# HEADERS
#
HEADERS += \
$${sha_HEADERS} \
$${OBJECTIVE_HEADERS} \

# SOURCES
#
SOURCES += \
$${sha_SOURCES} \

########################################################################
# FRAMEWORKS
#
FRAMEWORKS += \
$${sha_FRAMEWORKS} \

# LIBS
#
LIBS += \
$${sha_LIBS} \
$${FRAMEWORKS} \


