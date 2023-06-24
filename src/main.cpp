#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    string image_path = samples::findFile("starry_night.jpg");
    Mat img = imread(image_path);
    if(img.empty()){
        std::cout << "Could not read Image" << std::endl;
    }   
    std::cout << "Original Height and Width: "<< img.rows << "x" << img.cols << std::endl;
    imshow("Original Image", img);
    waitKey();

    int down_width = 300;
    int down_height = 200;
    Mat resized_down;
    resize(img, resized_down, Size(down_width, down_height), INTER_LINEAR);

    int up_width = 1200;
    int up_height = 800;
    Mat resized_up;
    resize(img, resized_up, Size(up_width, up_height), INTER_LINEAR);

    imshow("Resized Down by defining height and width", resized_down);
    waitKey();
    imshow("Resized Up by defining height and width", resized_up);
    waitKey();

    return 0;
}