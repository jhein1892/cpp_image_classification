#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>



using namespace cv;
using namespace std;

int main(){
    /***********************/
    /*   IMAGE RENDERING   */
    /***********************/
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

    /***********************/
    /*   VIDEO RENDERING   */
    /***********************/
    VideoCapture vid_capture("/Users/jacobhein/Downloads/IMG_0637.mov");
    // VideoCapture vid_capture(0);
    int fps = 20;
    int frame_width = static_cast<int>(vid_capture.get(3));
    int frame_height = static_cast<int>(vid_capture.get(4));
    Size frame_size(frame_width, frame_height);
    VideoWriter output("../TEST.avi", VideoWriter::fourcc('M','J','P','G'), fps, frame_size);

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

        if(isSuccess == false){
            std::cout << "Video camera is disconnected" << std::endl;
            break;
        }

        if(isSuccess == true){
            output.write(frame);
                imshow("Frame", frame);
                int key = waitKey(20);
                if(key == 'q')
                {
                    std::cout << "q key is pressed by the user. Stopped the video" << std::endl;
                    break;
                }

        }
    }

    vid_capture.release();
    destroyAllWindows();
    return 0;

}