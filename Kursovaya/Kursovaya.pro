QT       += core gui sql axcontainer

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

TARGET = "qsqlpsql"

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add_apartment.cpp \
    add_owner.cpp \
    add_record.cpp \
    add_service.cpp \
    add_service_provider.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    print.cpp \
    report.cpp

HEADERS += \
    add_apartment.h \
    add_owner.h \
    add_record.h \
    add_service.h \
    add_service_provider.h \
    login.h \
    mainwindow.h \
    print.h \
    report.h

FORMS += \
    add_apartment.ui \
    add_owner.ui \
    add_record.ui \
    add_service.ui \
    add_service_provider.ui \
    login.ui \
    mainwindow.ui \
    print.ui \
    report.ui


TRANSLATIONS += \
    Kursovaya_ru_RU.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
