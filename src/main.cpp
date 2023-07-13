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
    

    return 0;
}