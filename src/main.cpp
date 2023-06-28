#include <opencv2/opencv.hpp>

using namespace cv;

int main( int argc, char** argv) 
{
    Mat src = imread("threashold.png", IMREAD_GRAYSCALE);
    Mat dst;

    imshow("Original", src);
    waitKey();
    return 0;
}