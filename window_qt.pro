TEMPLATE     = vcapp
TARGET       = window_qt
CONFIG      += warn_on qt debug windows console

HEADERS     += headers/interface.h \
               headers/scene.h \
               scenes/menu.h \
               scenes/game.h

SOURCES     += sources/main.cpp \
               sources/interface.cpp \
               sources/scene.cpp

QT          += core widgets multimedia
