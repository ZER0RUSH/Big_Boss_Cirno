QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    client.cpp \
    connectmenu.cpp \
    enemy.cpp \
    enemybullet.cpp \
    hero2.cpp \
    herobullet.cpp \
    heroplane.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    server.cpp \
    startmenu.cpp

HEADERS += \
    client.h \
    config.h \
    connectmenu.h \
    enemy.h \
    enemybullet.h \
    hero2.h \
    herobullet.h \
    heroplane.h \
    mainwindow.h \
    map.h \
    server.h \
    startmenu.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
Qt += network

RESOURCES += \
    res.qrc

FORMS += \
    connectmenu.ui \
    startmenu.ui
