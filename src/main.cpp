#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(){
    std::string image_path = samples::findFile("starry_night.jpg");
    Mat img = imread(image_path);
    imshow("Originam Image", img);
    waitKey(0);

    if (img.empty()){
        std::cout << "Could not read image" << std::endl;
    }

    // Draw line on image
    Mat imageLine = img.clone();
    Point pointA(200,80);
    Point pointB(450,80);
    line(imageLine, pointA, pointB, Scalar(255,255,0), 3, 8, 0);
    imshow("lined Image", imageLine);
    waitKey(0);

    // Draw Circle on image
    Mat circleImage = img.clone();
    Point circle_center(415, 190);
    int radius = 100;
    circle(circleImage, circle_center, radius, Scalar(0, 0, 255), 3, 8, 0);

    imshow("Circle on Image", circleImage);

    return 0;
}