#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(){
    std::string image_path = samples::findFile("starry_night.jpg");
    Mat img = imread(image_path);
    imshow("Originam Image", img);
    waitKey(0);

    // if (img.empty()){
    //     std::cout << "Could not read image" << std::endl;
    // }

    // // Draw line on image
    // Mat imageLine = img.clone();
    // Point pointA(200,80);
    // Point pointB(450,80);
    // line(imageLine, pointA, pointB, Scalar(255,255,0), 3, 8, 0);
    // imshow("lined Image", imageLine);
    // waitKey(0);

    // // Draw outlined Circle on image
    // Mat circleImage = img.clone();
    // Point circle_center(415, 190);
    // int radius = 100;
    // // For outlined circle
    // circle(circleImage, circle_center, radius, Scalar(0, 0, 255), 3, 8, 0);
    // imshow("Circle on Image", circleImage);
    // waitKey(0);

    // // Draw filled circle on Image
    // Mat filledImage = img.clone();
    // circle(filledImage, circle_center, radius, Scalar(0,0,255), -1, 8, 0);

    // imshow("Filled Circle", filledImage);
    // waitKey(0);

    // // Draw a rectangle on Image
    // Mat rectImage = img.clone();
    // Point start_point(100, 200);
    // Point end_point(300, 550);

    // rectangle(rectImage, start_point, end_point, Scalar(0, 255, 0), 3, 8, 0);
    // imshow("Rectangle Image", rectImage);
    // waitKey(0);

    // // Draw an Ellipse
    // Mat ellipseImage = img.clone();
    // Point ellipse_center(415, 190);
    // Point axis1(100,50);
    // Point axis2(125,50);

    // ellipse(ellipseImage, ellipse_center, axis1, 0, 0, 360, Scalar(0,255, 0), 3, 8, 0);
    // ellipse(ellipseImage, ellipse_center, axis2, 90, 0, 360, Scalar(255,0, 0), 3, 8, 0);

    // imshow("Ellipse Image", ellipseImage);
    // waitKey(0);

    // // Draw Half an Ellipse
    // Mat halfEllipse = img.clone();

    // ellipse(halfEllipse, ellipse_center, axis1, 0, 180, 360, Scalar(255, 0, 0), 3, 8, 0);
    // // Filled
    // ellipse(halfEllipse, ellipse_center, axis1, 0, 0, 180, Scalar(255, 0, 0), -2, 8, 0);
    // imshow("Half Ellipse", halfEllipse);
    // waitKey(0);

    // Adding Text
    Mat imageText = img.clone();

    putText(imageText, "Starry Night", Point(399, 51), 4, 1.5, Scalar(0, 0, 0));
    putText(imageText, "Starry Night", Point(400, 50), 4, 1.5, Scalar(250, 225, 100));
    imshow("Text on Image", imageText);
    waitKey(0);

    return 0;
}