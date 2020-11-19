QT       += core gui charts sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    current_user.cpp \
    database.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    moviegroupbox.cpp \
    poll_chart.cpp \
    tab_employees.cpp

HEADERS += \
    current_user.h \
    database.h \
    loginpage.h \
    mainwindow.h \
    moviegroupbox.h \
    poll_chart.h \
    tab_employees.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imgs.qrc \
    login_icon.qrc \
    logo.qrc \
    profil_icon.qrc

DISTFILES += \
    imgs/mother-poster-crop.jpg
