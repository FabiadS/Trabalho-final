QT       += core gui\
           multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    about.cpp \
    button.cpp \
    coin.cpp \
    coin1.cpp \
    enemycobra.cpp \
    enemypassaro.cpp \
    game.cpp \
    health.cpp \
    heart.cpp \
    main.cpp \
    plataforma.cpp \
    player.cpp \
    playwindow.cpp \
    score.cpp

HEADERS += \
    about.h \
    button.h \
    coin.h \
    coin1.h \
    enemycobra.h \
    enemypassaro.h \
    game.h \
    health.h \
    heart.h \
    plataforma.h \
    player.h \
    playwindow.h \
    score.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
