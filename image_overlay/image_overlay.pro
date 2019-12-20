TEMPLATE = app

CONFIG += console c++11

CONFIG -= app_bundle

CONFIG -= qt

SOURCES += main.cpp \

INCLUDEPATH += /usr/local/include \
                /usr/local/include/opencv \
                /usr/local/include/opencv2 \

LIBS += /usr/local/lib/libopencv_calib3d.so.4.1 \
        /usr/local/lib/libopencv_core.so.4.1 \
        /usr/local/lib/libopencv_dnn.so.4.1 \
        /usr/local/lib/libopencv_features2d.so.4.1 \
        /usr/local/lib/libopencv_highgui.so.4.1 \
        /usr/local/lib/libopencv_imgcodecs.so.4.1 \
        /usr/local/lib/libopencv_imgproc.so.4.1 \
        /usr/local/lib/libopencv_ml.so.4.1 \
        /usr/local/lib/libopencv_objdetect.so.4.1 \
        /usr/local/lib/libopencv_photo.so.4.1 \
        /usr/local/lib/libopencv_stitching.so.4.1 \
        /usr/local/lib/libopencv_video.so.4.1 \
        /usr/local/lib/libopencv_videoio.so.4.1 \
        /usr/local/lib/libopencv_gapi.so.4.1 \
        /usr/local/lib/libopencv_flann.so.4.1 \

/usr/local/lib/libopencv_imgcodecs.so.4.1


#`pkg-config opencv --libs --cflags opencv`


