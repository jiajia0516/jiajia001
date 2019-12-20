#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

//#define TANGYUAN_OR_HUAJI 0
#define TANGYUAN_OR_HUAJI 1

using namespace std;
using namespace cv;

void detectAndDisplay( Mat frame );
String face_cascade_name = "../image_overlay/haarcascade_frontalface_alt.xml";
String eyes_cascade_name = "../image_overlay/haarcascade_eye_tree_eyeglasses.xml";
CascadeClassifier face_cascade;
CascadeClassifier eyes_cascade;

const int FRAME_WIDTH = 1280;
const int FRAME_HEIGHT = 240;


int main( void )
{
    // Load the cascades
    if( !face_cascade.load( face_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };
    if( !eyes_cascade.load( eyes_cascade_name ) ){ printf("--(!)Error loading\n"); return -1; };

//            frame = imread("/home/jiajia/workspace/maozi/005.jpg");//背景图片
    // Apply the classifier to the frame
//            if( !frame.empty() )
//            { detectAndDisplay( frame );}

    VideoCapture cap(0);
    if(!cap.isOpened())  //检测是否打开成功
        return -1;

    while(1)
    {
        Mat frame;
        cap >> frame; // 从摄像头中获取新的一帧
        detectAndDisplay( frame );

        if(waitKey(30) >= 0) break;
    }

    return 0;
}

void mapToMat(const cv::Mat &srcAlpha, cv::Mat &dest, int x, int y)
{
    int nc = 3;
    int alpha = 0;

    for (int j = 0; j < srcAlpha.rows; j++)
    {
        for (int i = 0; i < srcAlpha.cols*3; i += 3)
        {
            alpha = srcAlpha.ptr<uchar>(j)[i / 3*4 + 3];
            //alpha = 255-alpha;
            if(alpha != 0) //4通道图像的alpha判断
            {
                for (int k = 0; k < 3; k++)
                {
                    // if (src1.ptr<uchar>(j)[i / nc*nc + k] != 0)
                    if( (j+y < dest.rows) && (j+y>=0) &&
                        ((i+x*3) / 3*3 + k < dest.cols*3) && ((i+x*3) / 3*3 + k >= 0) &&
                        (i/nc*4 + k < srcAlpha.cols*4) && (i/nc*4 + k >=0) )
                    {
                        dest.ptr<uchar>(j+y)[(i+x*nc) / nc*nc + k] = srcAlpha.ptr<uchar>(j)[(i) / nc*4 + k];
                    }
                }
            }
        }
    }
}

void detectAndDisplay( Mat frame )
{
    std::vector<Rect> faces;
    Mat frame_gray;
    Mat hatAlpha;
#if TANGYUAN_OR_HUAJI  == 0

     hatAlpha = imread("../image_overlay/汤圆.png",-1);//叠加的图片

#elif TANGYUAN_OR_HUAJI  == 1

    hatAlpha = imread("../image_overlay/滑稽.png",-1);//叠加的图片

#endif

//        imshow("1",hatAlpha);

    cvtColor( frame, frame_gray, COLOR_BGR2GRAY );
    equalizeHist( frame_gray, frame_gray );

    face_cascade.detectMultiScale( frame_gray, faces, 1.1, 2, 0|CASCADE_SCALE_IMAGE, Size(30, 30) );
    for( size_t i = 0; i < faces.size(); i++ )
    {
//        Point center( faces[i].x + faces[i].width/2, faces[i].y + faces[i].height/2 );
//        Mat faceROI = frame_gray( faces[i] );
//        std::vector<Rect> eyes;

//        eyes_cascade.detectMultiScale( faceROI, eyes, 1.1, 2, 0 |CASCADE_SCALE_IMAGE, Size(30, 30) );

//        for( size_t j = 0; j < eyes.size(); j++ )
//        {
//            Point eye_center( faces[i].x + eyes[j].x + eyes[j].width/2, faces[i].y + eyes[j].y + eyes[j].height/2 );
//            int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
//        }
            resize(hatAlpha,hatAlpha,Size(faces[i].width, faces[i].height),0,0,INTER_LANCZOS4);   //叠加图片的尺寸大小
#if TANGYUAN_OR_HUAJI  == 0

     mapToMat(hatAlpha,frame,faces[i].x,faces[i].y+0.5*faces[i].height);//叠加图片的位置

#elif TANGYUAN_OR_HUAJI  == 1

    mapToMat(hatAlpha,frame,faces[i].x,faces[i].y+0.1*faces[i].height);//叠加图片的位置

#endif
    }
    imshow( "result", frame );
    imwrite("../image_overlay/yourself.jpg",frame);
}
