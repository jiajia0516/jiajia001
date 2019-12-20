#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <librealsense2/rs.hpp>
#include <librealsense2/rsutil.h>
#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace cv;
using namespace std;
using namespace rs2;

float get_depth_scale(device dev)                         //获取深度像素对应长度单位（米）的换算比例
{
    for (sensor& sensor : dev.query_sensors())            //检查设备的传感器
    {
        if (depth_sensor dpt = sensor.as<depth_sensor>()) //检查传感器是否为深度传感器
        {
            return dpt.get_depth_scale();
        }
    }
}

Mat depth_interception(Mat depth,pipeline_profile profile)      //深度截取函数
{
    float depth_scale = get_depth_scale(profile.get_device());  //获取深度像素与现实单位比例
    Mat roi_img (depth.rows, depth.cols, CV_8UC3, Scalar::all(0));

    for(int row=0;row<depth.rows;row++)                         //对深度图像遍历
    {
        for(int col=0;col<depth.cols;col++)
        {
            uint16_t depth_value=depth.at<uint16_t>(row,col);   //取当前点对应的深度值
            float depth_m = depth_value*depth_scale;

            if( depth_m >0.50 && depth_m < 1.0)         //自定义深度范围
            {
                roi_img.at<Vec3b>(row,col)[0]=250;       //自定义颜色
                roi_img.at<Vec3b>(row,col)[1]=0;
                roi_img.at<Vec3b>(row,col)[2]=50;
            }
        }
    }
    return roi_img;
}

int main()
{
    colorizer color_map;            //帮助着色深度图像
    pipeline pipe;                  //创建数据管道
    config pipe_config;
    pipe_config.enable_stream(RS2_STREAM_DEPTH,640,480,RS2_FORMAT_Z16,30);
    pipe_config.enable_stream(RS2_STREAM_COLOR,640,480,RS2_FORMAT_BGR8,30);
    pipeline_profile profile = pipe.start(pipe_config); //start()函数返回数据管道的profile

    while (1)
    {
        double t = (double)cv::getTickCount();

        frameset frameset = pipe.wait_for_frames();         //堵塞程序直到新的一帧捕获
        frame depth_frame = frameset.get_depth_frame();     //取深度图
        frame depth_frame_tee = frameset.get_depth_frame().apply_filter(color_map);

        const int depth_w=depth_frame.as<video_frame>().get_width();        //获取宽高
        const int depth_h=depth_frame.as<video_frame>().get_height();

        Mat depth_image(Size(depth_w,depth_h),                              //创建OPENCV类型 并传入数据
                        CV_16U,(void*)depth_frame.get_data(),Mat::AUTO_STEP);
        Mat depth_image_tee(Size(depth_w,depth_h),
                          CV_8UC3,(void*)depth_frame_tee.get_data(),Mat::AUTO_STEP);
        Mat result = depth_interception(depth_image,profile);               //实现深度截取

        Mat bin_img;
        inRange(result,Scalar(249,0,49),Scalar(251,0,51),bin_img);
//        GaussianBlur(bin_img, bin_img, Size(3,3), 1, 1);

        Mat element1 = getStructuringElement(MORPH_RECT, Size(50, 50));
        Mat element2 = getStructuringElement(MORPH_RECT, Size(55, 55));

        erode ( bin_img, bin_img, element1 );
        dilate( bin_img, bin_img, element2 );

        vector<vector<Point>>contours;
        vector<Vec4i>hierarchy;
        findContours(bin_img,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));

        vector<RotatedRect>minRects(contours.size());
//        vector<Rect> boundRect(contours.size());

        for (uint i = 0; i < contours.size(); ++i)
                {
//                    boundRect[i] = boundingRect(Mat(contours[i]));
                    minRects[i] = minAreaRect(Mat(contours[i]));

                        Point2f rectPoints[4];
                        minRects[i].points(rectPoints);

                        double x0 = rectPoints[0].x;
                        double y0 = rectPoints[0].y;
                        double x1 = rectPoints[1].x;
                        double y1 = rectPoints[1].y;
                        double x2 = rectPoints[2].x;
                        double y2 = rectPoints[2].y;
//                        double x3 = rectPoints[3].x;
//                        double y3 = rectPoints[3].y;

                        double width  = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
                        double height = sqrt((x0-x1)*(x0-x1)+(y0-y1)*(y0-y1));    //定义长宽
                        double area = width * height;                             //面积
                        float slope = (y2 - y0)/(x2 - x0);
                        /*-----轮廓左上角点为 Point１-----*/
                        double rect_x = x1 + fabs(x2-x1)*0.5;           //以左上角为原点，x轴加弹药箱的宽*0.5
                        double rect_y = y1 + fabs(x2-x1)*0.5 ;          //以左上角为原点，y轴加弹药箱的宽*0.5
                        //double rect_y1 = (y0 + y2)/2;                 //轮廓中点在Y轴上的坐标
                        Point contour_center = Point(rect_x, rect_y);

//                        string text0 = "0";
                        string text1 = "1";
                        string text2 = "2";
//                        string text3 = "3";

                        if(area>10000.0 && slope < 0)
                        {
//                            cout << "slope ==" << area <<endl;
                            for (int j = 0; j < 4; j++)
                            {
                                line(result, rectPoints[j], rectPoints[(j + 1) % 4],
                                       Scalar(0,255,0), 4, 8, 0);
                                circle(result, contour_center,1,Scalar( 0,255, 0),2,8,0);
//                                putText(result, text0, rectPoints[0], FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);
                                putText(result, text1, rectPoints[1], FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);
                                putText(result, text2, rectPoints[2], FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);
//                                putText(result, text3, rectPoints[3], FONT_HERSHEY_COMPLEX, 2, cv::Scalar(0, 255, 255), 2, 8, 0);
                            }
                        }
                }

        imshow("depth_image",depth_image_tee);
        imshow("result",result);
        imshow("bin_img",bin_img);

        t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
        int fps = int(1.0 / t);
        cout << "FPS: " << fps<<endl;

        int key = waitKey(1);
        if(char(key) == 27)break;
    }
    return 0;
}

