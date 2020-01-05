#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/opencv.hpp>
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

        float depth_scale = get_depth_scale(profile.get_device());  //获取深度像素与现实单位比例
        Mat roi_img (depth_image.rows, depth_image.cols, CV_8UC3, Scalar::all(0));

        for(int row=0;row<depth_image.rows;row++)                         //对深度图像遍历
        {
            for(int col=0;col<depth_image.cols;col++)
            {
                uint16_t depth_value=depth_image.at<uint16_t>(row,col);   //取当前点对应的深度值
                float depth_m = depth_value*depth_scale;

                if( depth_m >0.300 && depth_m < 1.000)         //自定义深度范围
                {
                    roi_img.at<Vec3b>(row,col)[0]=250;       //自定义颜色
                    roi_img.at<Vec3b>(row,col)[1]=0;
                    roi_img.at<Vec3b>(row,col)[2]=50;
                }
            }
        }

        Mat result = roi_img;
        Mat bin_img;
        inRange(result,Scalar(249,0,49),Scalar(251,0,51),bin_img);

        Mat element1 = getStructuringElement(MORPH_RECT, Size(9, 9));
        Mat element2 = getStructuringElement(MORPH_RECT, Size(13, 13));

        erode ( bin_img, bin_img, element1 );
        dilate( bin_img, bin_img, element2 );

        vector<vector<Point>>contours;
        vector<Vec4i>hierarchy;
        findContours(bin_img,contours,hierarchy,RETR_TREE,CHAIN_APPROX_SIMPLE,Point(0,0));//查找轮廓

        vector<RotatedRect>minRects(contours.size());
        vector<Rect> boundRect(contours.size());


        for (uint i = 0; i < contours.size(); ++i)
                {
                    boundRect[i] = boundingRect(Mat(contours[i]));
                    minRects[i] = minAreaRect(Mat(contours[i]));
//                    rectangle(result,boundRect[i].tl(),boundRect[i].br(),Scalar(255,0,255),2,8,0);
                        Point2f rectPoints[4];
                        minRects[i].points(rectPoints);

                        double x0 = rectPoints[0].x;
                        double y0 = rectPoints[0].y;
                        double x1 = rectPoints[1].x;
                        double y1 = rectPoints[1].y;
                        double x2 = rectPoints[2].x;
                        double y2 = rectPoints[2].y;

                        double x3 = boundRect[i].tl().x;
                        double y3 = boundRect[i].tl().y;
                        double x4 = boundRect[i].br().x;
                        double y4 = boundRect[i].br().y;

                        double x = fabs(x4-x3);//弹药箱宽
                        double y = fabs(y4-y3);//弹药箱高
                        double all_pixels = x * y;//轮廓所有像素点
                        double slope = x / y ;//宽高比

//                        int effective_pixel;
//                        for(int rows= x3 ; rows< x4 ;rows++)                         //对深度图像二次遍历
//                        {
//                            for(int cols= y3 ; cols< y4 ;cols++)
//                            {
//                                 if( bin_img.at<Vec3b>(rows,cols)[0] >0 )
//                                 {
//                                    effective_pixel = effective_pixel + 1 ;
//                                 }
//                            }
//                        }

                        /*-----轮廓左上角点为 Point１-----*/
                        double rect_x = (x3 + x4)*0.5;           //取轮廓在横轴上的中点
                        double rect_y = y1 + fabs(x2-x1)*0.5 ;   //点在轮廓纵轴上的位置
//                        double fill_ratio = effective_pixel/all_pixels;

                        Point contour_center = Point(rect_x, rect_y);

//+-
                        if(/* fill_ratio > 0.850 && */200 <rect_x && rect_x<400 &&all_pixels >2000 && all_pixels < 30000 && 1.40 < slope && slope <2.50 )
                        {
                            cout << "slope ==" << slope <<endl;
                            cout << "所有像素点: " << all_pixels << endl;
//                            cout << "有效像素点: " << effective_pixel << endl;
//                            cout<<"("<< fill_ratio <<")"<<endl;

                            for (int j = 0; j < 4; j++)
                            {
                                line(result, rectPoints[j], rectPoints[(j + 1) % 4],
                                       Scalar(0,255,0), 4, 8, 0);
                            }
                            circle(result, contour_center,1,Scalar( 0,255, 0),2,8,0);
                        }

        }


//        imshow("depth_image",depth_image_tee);
        imshow("result",result);
//        imshow("bin_img",bin_img);

        t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
        int fps = int(1.0 / t);
        cout << "FPS: " << fps<<endl;

        int key = waitKey(1);
        if(char(key) == 27)break;
    }
    return 0;
}

