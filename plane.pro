QT       += core gui
QT +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    citysql.cpp \
    dlg_addcity.cpp \
    dlg_setplane.cpp \
    dlg_query.cpp \
    main.cpp \
    mainwindow.cpp \
    page_login.cpp \
    plane.cpp \
    querycity.cpp


HEADERS += \
    citysql.h \
    dlg_addcity.h \
    dlg_setplane.h \
    dlg_query.h \
    mainwindow.h \
    page_login.h \
    plane.h \
    querycity.h

FORMS += \
    dlg_addcity.ui \
    dlg_setplane.ui \
    dlg_query.ui \
    mainwindow.ui \
    page_login.ui \
    plane.ui \
    querycity.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
