#include <opencv2/opencv.hpp>
#include <iostream> 

using namespace cv;

int main () {
    std::string image_path = samples::findFile("right.jpg");
    Mat img = imread(image_path);
    Mat img_grey;
    cvtColor(img, img_grey, COLOR_BGR2GRAY);

    Mat thresh; 
    threshold(img_grey, thresh, 150, 255, THRESH_BINARY);
    imshow("Binary Image", thresh);
    waitKey(0);
    destroyAllWindows();

    // detect the contours on the binary image using cv2.CHAIN_APPROX_NONE
    std::vector<std::vector<Point>> contours;
    std::vector<Vec4i> hierarchy;
    findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
    // draw contours on the original image
    Mat image_copy = img.clone();
    drawContours(image_copy, contours, -1, Scalar(0, 255, 0), 2);
    imshow("None approximation", image_copy);
    waitKey(0);
    imwrite("contours_none_image1.jpg", image_copy);
    destroyAllWindows();


    return 0;
}