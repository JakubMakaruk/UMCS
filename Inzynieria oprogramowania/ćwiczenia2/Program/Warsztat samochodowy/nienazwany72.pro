TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        Budynek.cpp \
        GarazDoNapraw.cpp \
        Kolo.cpp \
        Pracownik.cpp \
        SamochodDoNaprawy.cpp \
        Silnik.cpp \
        Usluga.cpp \
        Zawod.cpp \
        ZestawNarzedzi.cpp \
        main.cpp

HEADERS += \
    Budynek.h \
    GarazDoNapraw.h \
    Kolo.h \
    Pracownik.h \
    SamochodDoNaprawy.h \
    Silnik.h \
    Usluga.h \
    Zawod.h \
    ZestawNarzedzi.h
