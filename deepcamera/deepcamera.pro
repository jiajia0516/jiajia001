TEMPLATE = app

CONFIG += console c++11

CONFIG -= app_bundle

CONFIG -= qt

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2 \
                /usr/local/include/librealsense2

LIBS += /usr/local/lib/libopencv_* \
        /usr/local/lib/librealsense2.so \

SOURCES += \
    main.cpp
