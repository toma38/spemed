#-------------------------------------------------
#
# Project created by QtCreator 2012-01-27T15:51:33
#
#-------------------------------------------------

QT       += core gui sql webkit

TARGET = spemed
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    detaildialog.cpp \
    spedialog.cpp \
    customsqlmodel.cpp \
    afssapsdetailwidget.cpp

HEADERS  += mainwindow.h \
    detaildialog.h \
    spedialog.h \
    customsqlmodel.h \
    afssapsdetailwidget.h

FORMS    += mainwindow.ui \
    detaildialog.ui \
    spedialog.ui


RESOURCES += \
    gfx/gfx.qrc

 RC_FILE = myapp.rc


