#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

// Points to store the bounding box coordinates



int main() {
    std::string image_path = samples::findFile("starry_night.jpg");
    Mat image = imread(image_path);
}