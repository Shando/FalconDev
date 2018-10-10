#-------------------------------------------------
#
# Project created by QtCreator 2018-10-05T15:43:07
#
#-------------------------------------------------

QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Falcon
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    include/src/internal/QCodeEditor.cpp \
    include/src/internal/QFALCompleter.cpp \
    include/src/internal/QFALHighlighter.cpp \
    include/src/internal/QFramedTextAttribute.cpp \
    include/src/internal/QLanguage.cpp \
    include/src/internal/QLineNumberArea.cpp \
    include/src/internal/QStyleSyntaxHighlighter.cpp \
    include/src/internal/QSyntaxStyle.cpp \
    settings.cpp

HEADERS += \
        mainwindow.h \
    include/include/internal/QCodeEditor.hpp \
    include/include/internal/QFALCompleter.hpp \
    include/include/internal/QFALHighlighter.hpp \
    include/include/internal/QFramedTextAttribute.hpp \
    include/include/internal/QHighlightRule.hpp \
    include/include/internal/QLanguage.hpp \
    include/include/internal/QLineNumberArea.hpp \
    include/include/internal/QStyleSyntaxHighlighter.hpp \
    include/include/internal/QSyntaxStyle.hpp \
    include/include/QCodeEditor \
    include/include/QFALCompleter \
    include/include/QFALHighlighter \
    include/include/QFramedTextAttribute \
    include/include/QHighlightRule \
    include/include/QLanguage \
    include/include/QLineNumberArea \
    include/include/QStyleSyntaxHighlighter \
    include/include/QSyntaxStyle \
    settings.h

FORMS += \
        mainwindow.ui \
    about.ui \
    settings.ui \
    help.ui

INCLUDEPATH += \
        $$PWD/Resources/files

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    include/QCodeEditor/files/design_template.xml \
    include/QCodeEditor/files/rules_template.xml \
    resources/languages/fal.xml

RESOURCES += \
    falcon.qrc

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-Falcon-Desktop_Qt_5_12_0_MSVC2015_32bit-Debug/release/ -lFalcon
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-Falcon-Desktop_Qt_5_12_0_MSVC2015_32bit-Debug/debug/ -lFalcon

INCLUDEPATH += $$PWD/../build-Falcon-Desktop_Qt_5_12_0_MSVC2015_32bit-Debug/debug
DEPENDPATH += $$PWD/../build-Falcon-Desktop_Qt_5_12_0_MSVC2015_32bit-Debug/debug

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-Falcon-Desktop_Qt_5_12_0_MSVC2015_32bit-Debug/release/libFalcon.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-Falcon-Desktop_Qt_5_12_0_MSVC2015_32bit-Debug/debug/libFalcon.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../build-Falcon-Desktop_Qt_5_12_0_MSVC2015_32bit-Debug/release/Falcon.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../build-Falcon-Desktop_Qt_5_12_0_MSVC2015_32bit-Debug/debug/Falcon.lib
