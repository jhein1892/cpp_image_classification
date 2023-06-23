#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>



using namespace cv;
using namespace std;

int main(){
    string image_path = samples::findFile("starry_night.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);
    Mat img_greyscale = imread(image_path, IMREAD_GRAYSCALE);
    Mat image_unchanged = imread(image_path, IMREAD_UNCHANGED);

    if(img.empty()){
        cout << "Could not read the image: " << image_path << endl;
        return 1;
    }

    namedWindow("Color Image", WINDOW_AUTOSIZE);
    namedWindow("greyscale image", WINDOW_AUTOSIZE);
    namedWindow("unchanged image", WINDOW_AUTOSIZE);

    imshow("Color Image", img);
    imshow("greyscale image", img_greyscale);
    imshow("unchanged image", image_unchanged);

    int k = waitKey(0);
    imwrite("starry_night.png", img);
    // if(k == 's'){
    // }

    destroyAllWindows();


    VideoCapture vid_capture("Resources/Cars.mp4");

    if(!vid_capture.isOpened()){
        std::cout << "Error opening video stream" << endl;
    } else {
        int fps = vid_capture.get(5);
        std::cout<< "Frames per second: " << fps;

        int frame_count = vid_capture.get(7);

        std::cout << " Frame count: " << frame_count;
    }



    return 0;

}