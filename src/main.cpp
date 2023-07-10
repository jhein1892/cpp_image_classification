#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(){
    std::string image_path = samples::findFile("ellipses.jpg");
    Mat image = imread(image_path);

    imshow("Ellipses", image);
    waitKey();
}