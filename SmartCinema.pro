QT       += core gui charts sql
QT       += printsupport network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    CLIENTANDSUBS/client.cpp \
    CLIENTANDSUBS/clientgroupbox.cpp \
    CLIENTANDSUBS/subscription.cpp \
    CLIENTANDSUBS/subscriptiongroupbox.cpp \
    CLIENTANDSUBS/tab_client.cpp \
    CLIENTANDSUBS/tab_subscription.cpp \
    current_user.cpp \
    database.cpp \
    employeesFiles/employee.cpp \
    employeesFiles/employeegroupbox.cpp \
    employeesFiles/tab_employees.cpp \
    loginpage.cpp \
    main.cpp \
    mainwindow.cpp \
    moviesFiles\movie.cpp \
    moviesFiles\moviegroupbox.cpp \
    poll_chart.cpp \
    smtp.cpp \
    moviesFiles\tab_movies.cpp \
    tab_theatres.cpp \
    ticketsFiles\tab_tickets.cpp \
    ticketsFiles\ticket.cpp \
    ticketsFiles\ticketgroupbox.cpp

HEADERS += \
    CLIENTANDSUBS/client.h \
    CLIENTANDSUBS/clientgroupbox.h \
    CLIENTANDSUBS/subscription.h \
    CLIENTANDSUBS/subscriptiongroupbox.h \
    CLIENTANDSUBS/tab_client.h \
    CLIENTANDSUBS/tab_subscription.h \
    current_user.h \
    database.h \
    employeesFiles/employee.h \
    employeesFiles/employeegroupbox.h \
    employeesFiles/tab_employees.h \
    loginpage.h \
    mainwindow.h \
    moviesFiles\movie.h \
    moviesFiles\moviegroupbox.h \
    poll_chart.h \
    smtp.h \
    moviesFiles\tab_movies.h \
    tab_theatres.h \
    ticketsFiles\tab_tickets.h \
    ticketsFiles\ticket.h \
    ticketsFiles\ticketgroupbox.h

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
