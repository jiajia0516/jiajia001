#include <iostream>
#include <sstream>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<librealsense2/rs.hpp>
#include<librealsense2/rsutil.h>

using namespace cv;
using namespace std;


//获取深度像素对应长度单位（米）的换算比例
float get_depth_scale(rs2::device dev)
{
    // Go over the device's sensors
    for (rs2::sensor& sensor : dev.query_sensors())
    {
        // Check if the sensor if a depth sensor
        if (rs2::depth_sensor dpt = sensor.as<rs2::depth_sensor>())
        {
            return dpt.get_depth_scale();
        }
    }
    throw std::runtime_error("Device does not have a depth sensor");
}
//深度图对齐到彩色图函数
Mat align_Depth2Color(Mat depth,Mat color,rs2::pipeline_profile profile){
    //声明数据流
    auto depth_stream=profile.get_stream(RS2_STREAM_DEPTH).as<rs2::video_stream_profile>();
    auto color_stream=profile.get_stream(RS2_STREAM_COLOR).as<rs2::video_stream_profile>();

    //获取内参
    const auto intrinDepth=depth_stream.get_intrinsics();
    const auto intrinColor=color_stream.get_intrinsics();

    //直接获取从深度摄像头坐标系到彩色摄像头坐标系的欧式变换矩阵
    //auto  extrinDepth2Color=depth_stream.get_extrinsics_to(color_stream);
    rs2_extrinsics  extrinDepth2Color;
    rs2_error *error;
    rs2_get_extrinsics(depth_stream,color_stream,&extrinDepth2Color,&error);

    //平面点定义
    float pd_uv[2],pc_uv[2];
    //空间点定义
    float Pdc3[3],Pcc3[3];

    //获取深度像素与现实单位比例（D435默认1毫米）
    float depth_scale = get_depth_scale(profile.get_device());
    int y=0,x=0;
    //初始化结果
    //Mat result=Mat(color.rows,color.cols,CV_8UC3,Scalar(0,0,0));
    Mat result=Mat(color.rows,color.cols,CV_16U,Scalar(0));
    //对深度图像遍历
    for(int row=0;row<depth.rows;row++){
        for(int col=0;col<depth.cols;col++){
            //将当前的(x,y)放入数组pd_uv，表示当前深度图的点
            pd_uv[0]=col;
            pd_uv[1]=row;
            //取当前点对应的深度值
            uint16_t depth_value=depth.at<uint16_t>(row,col);
            //换算到米
            float depth_m=depth_value*depth_scale;
            //将深度图的像素点根据内参转换到深度摄像头坐标系下的三维点
            rs2_deproject_pixel_to_point(Pdc3,&intrinDepth,pd_uv,depth_m);
            //将深度摄像头坐标系的三维点转化到彩色摄像头坐标系下
            rs2_transform_point_to_point(Pcc3,&extrinDepth2Color,Pdc3);
            //将彩色摄像头坐标系下的深度三维点映射到二维平面上
            rs2_project_point_to_pixel(pc_uv,&intrinColor,Pcc3);

            //取得映射后的（u,v)
            x=(int)pc_uv[0];
            y=(int)pc_uv[1];
//            if(x<0||x>color.cols)
//                continue;
//            if(y<0||y>color.rows)
//                continue;
            //最值限定
            x=x<0? 0:x;
            x=x>depth.cols-1 ? depth.cols-1:x;
            y=y<0? 0:y;
            y=y>depth.rows-1 ? depth.rows-1:y;

            result.at<uint16_t>(y,x)=depth_value;
        }
    }
    //返回一个与彩色图对齐了的深度信息图像
    return result;
}

void measure_distance(Mat &color,Mat depth,cv::Size range,rs2::pipeline_profile profile)
{
    //获取深度像素与现实单位比例（D435默认1毫米）
    float depth_scale = get_depth_scale(profile.get_device());
    //定义图像中心点
    cv::Point center(color.cols/2,color.rows/2);
    //定义计算距离的范围
    cv::Rect RectRange(center.x-range.width/2,center.y-range.height/2,range.width,range.height);
    //遍历该范围
    float distance_sum=0;
    int effective_pixel=0;
    for(int y=RectRange.y;y<RectRange.y+RectRange.height;y++){
        for(int x=RectRange.x;x<RectRange.x+RectRange.width;x++){
            //如果深度图下该点像素不为0，表示有距离信息
            if(depth.at<uint16_t>(y,x)){
                distance_sum+=depth_scale*depth.at<uint16_t>(y,x);
                effective_pixel++;
            }
        }
    }
    cout<<"遍历完成，有效像素点:"<<effective_pixel<<endl;
    float effective_distance=distance_sum/effective_pixel;
    cout<<"目标距离："<<effective_distance<<" m"<<endl;
    char distance_str[30];
    sprintf(distance_str,"the distance is:%f m",effective_distance);
    cv::rectangle(color,RectRange,Scalar(0,0,255),2,8);
    cv::putText(color,(string)distance_str,cv::Point(color.cols*0.02,color.rows*0.05),
                cv::FONT_HERSHEY_PLAIN,2,Scalar(0,255,0),2,8);
}

int main()
{
    const char* depth_win="depth_Image";
    namedWindow(depth_win,WINDOW_AUTOSIZE);
    const char* color_win="color_Image";
    namedWindow(color_win,WINDOW_AUTOSIZE);

    //深度图像颜色map
    rs2::colorizer c;                          // Helper to colorize depth images

    //创建数据管道
    rs2::pipeline pipe;
    rs2::config pipe_config;
    pipe_config.enable_stream(RS2_STREAM_DEPTH,640,480,RS2_FORMAT_Z16,30);
    pipe_config.enable_stream(RS2_STREAM_COLOR,640,480,RS2_FORMAT_BGR8,30);

    //start()函数返回数据管道的profile
    rs2::pipeline_profile profile = pipe.start(pipe_config);

    //定义一个变量去转换深度到距离
    float depth_clipping_distance = 1.f;

    //声明数据流
    auto depth_stream=profile.get_stream(RS2_STREAM_DEPTH).as<rs2::video_stream_profile>();
    auto color_stream=profile.get_stream(RS2_STREAM_COLOR).as<rs2::video_stream_profile>();

    //获取内参
    auto intrinDepth=depth_stream.get_intrinsics();
    auto intrinColor=color_stream.get_intrinsics();

    //直接获取从深度摄像头坐标系到彩色摄像头坐标系的欧式变换矩阵
    auto  extrinDepth2Color=depth_stream.get_extrinsics_to(color_stream);

    while (1) // Application still alive?
    {
        //堵塞程序直到新的一帧捕获
        rs2::frameset frameset = pipe.wait_for_frames();
        //取深度图和彩色图
        rs2::frame color_frame = frameset.get_color_frame();//processed.first(align_to);
        rs2::frame depth_frame = frameset.get_depth_frame();
        rs2::frame depth_frame_4_show = frameset.get_depth_frame().apply_filter(c);
        //获取宽高
        const int depth_w=depth_frame.as<rs2::video_frame>().get_width();
        const int depth_h=depth_frame.as<rs2::video_frame>().get_height();
        const int color_w=color_frame.as<rs2::video_frame>().get_width();
        const int color_h=color_frame.as<rs2::video_frame>().get_height();

        //创建OPENCV类型 并传入数据
        Mat depth_image(Size(depth_w,depth_h),
                                CV_16U,(void*)depth_frame.get_data(),Mat::AUTO_STEP);
        Mat depth_image_4_show(Size(depth_w,depth_h),
                                CV_8UC3,(void*)depth_frame_4_show.get_data(),Mat::AUTO_STEP);
        Mat color_image(Size(color_w,color_h),
                                CV_8UC3,(void*)color_frame.get_data(),Mat::AUTO_STEP);
        //实现深度图对齐到彩色图
        Mat result=align_Depth2Color(depth_image,color_image,profile);
        measure_distance(color_image,result,cv::Size(30,30),profile);
        //显示
        imshow(depth_win,depth_image_4_show);
        imshow(color_win,color_image);
        //imshow("result",result);
        int key = waitKey(1);
        if(char(key) == 27)break;
    }
    return 0;
}

