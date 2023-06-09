#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(){
    std::string image_path = samples::findFile("butterfly.jpg");
    Mat image = imread(image_path);

    imshow("Ellipses", image);
    waitKey();

    // Convert to grayscale
    Mat img_gray;
    cvtColor(image, img_gray, COLOR_BGR2GRAY);

    // Blur the image for better edge detection
    Mat img_blur;
    GaussianBlur(img_gray, img_blur, Size(3,3), 0);

    // Sobel edge detection
    Mat sobelx, sobely, sobelxy;
    Sobel(img_blur, sobelx, CV_64F, 1, 0, 5);
    Sobel(img_blur, sobely, CV_64F, 0, 1, 5);
    Sobel(img_blur, sobelxy, CV_64F, 1, 1, 5);

    // Display Sobel edge edtection images
    imshow("Sobel X", sobelx);
    waitKey(0);
    imshow("Sobel Y", sobely);
    waitKey(0);
    imshow("Sobel XY using Sobel() function", sobelxy);
    waitKey(0);

    // Canny edge detection
    Mat edges;
    Canny(img_blur, edges, 100, 200, 3, false);

    // Display canny edge detected image
    imshow("Canny edge detection", edges);
    waitKey(0);
    destroyAllWindows();
    return 0;

    


}