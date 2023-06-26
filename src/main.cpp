#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(int, char**) {
    std::string image_path = samples::findFile("starry_night.jpg");
    Mat image = imread(image_path);
    imshow("Image", image);
    waitKey(0);
    double angle = 45;

    // Get the center coordinates of the image to create the 2D rotation matrix
    Point2f center((image.cols - 1)/2.0, (image.rows - 1)/2.0);
    // Using getRotationMatrix2D() to get the rotation matrix
    Mat rotation_matrix = getRotationMatrix2D(center, angle, 1.0);
    
    // we will save the resulting image in roatated_image matrix
    Mat rotated_image;
    // rotate the image using warpAffine
    warpAffine(image, rotated_image, rotation_matrix, image.size());
    imshow("Rotated image", rotated_image);

    waitKey(0);

    imwrite("../rotated_img.jpg", rotated_image);

    return 0;
}