TEMPLATE = app

CONFIG += console c++11

CONFIG -= app_bundle

CONFIG -= qt

SOURCES += main.cpp \

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2 \

LIBS += /usr/local/lib/libopencv_* \


#`pkg-config opencv --libs --cflags opencv`


