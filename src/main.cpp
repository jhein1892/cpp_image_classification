#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>



using namespace cv;
using namespace std;

int main(){
    // string image_path = samples::findFile("starry_night.jpg");
    // Mat img = imread(image_path, IMREAD_COLOR);
    // Mat img_greyscale = imread(image_path, IMREAD_GRAYSCALE);
    // Mat image_unchanged = imread(image_path, IMREAD_UNCHANGED);

    // if(img.empty()){
    //     cout << "Could not read the image: " << image_path << endl;
    //     return 1;
    // }

    // namedWindow("Color Image", WINDOW_AUTOSIZE);
    // namedWindow("greyscale image", WINDOW_AUTOSIZE);
    // namedWindow("unchanged image", WINDOW_AUTOSIZE);

    // imshow("Color Image", img);
    // imshow("greyscale image", img_greyscale);
    // imshow("unchanged image", image_unchanged);

    // int k = waitKey(0);
    // imwrite("starry_night.png", img);
    // // if(k == 's'){
    // // }

    // destroyAllWindows();

    // string video_path = samples::findFile("Megamind.avi");
    VideoCapture vid_capture("/Users/jacobhein/Downloads/IMG_0637.mov");

    if(!vid_capture.isOpened()){
        std::cout << "Error opening video stream" << endl;
    } else {
        int fps = vid_capture.get(5);
        std::cout<< "Frames per second: " << fps;

        int frame_count = vid_capture.get(7);

        std::cout << " Frame count: " << frame_count;
    }

    while(vid_capture.isOpened()){
        Mat frame;

        bool isSuccess = vid_capture.read(frame);

        if(isSuccess == true){
            imshow("Frame", frame);
        }

        if(isSuccess == false){
            std::cout << "Video camera is disconnected" << std::endl;
            break;
        }

        int key = waitKey(20);
        if(key == 'q')
        {
            std::cout << "q key is pressed by the user. Stopped the video" << std::endl;
            break;
        }
    }

    vid_capture.release();
    destroyAllWindows();
    return 0;

}