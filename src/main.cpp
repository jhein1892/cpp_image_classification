#include <opencv2/opencv.hpp>

using namespace cv;

int main( int argc, char** argv) 
{
    std::string image_path = samples::findFile("gradient.jpg");
    Mat src = imread(image_path, IMREAD_GRAYSCALE);
    Mat dst;

    // Binary Threshold
    double thresh = 0;
    double maxValue = 255;
    threshold(src, dst, thresh, maxValue, THRESH_BINARY);
    imshow("Original", src);
    imshow("Binary", dst);
    waitKey();
    destroyAllWindows();

    // Inverse Binary
    thresh = 127;
    maxValue = 0;
    threshold(src, dst, thresh, maxValue, THRESH_BINARY_INV);
    imshow("Original", src);
    imshow("Binary Inverse", dst);
    waitKey();
    destroyAllWindows();

    
    // // Basic threashold example
    // threshold(src, dst, 0, 255, THRESH_BINARY);
    // imwrite("../opencv-threshold-example.jpg", dst);

    // // Thresholding with maxval set to 128
    // threshold(src, dst, 0, 128, THRESH_BINARY);
    // imwrite("../opencv-thresh-binary-maxval.jpg", dst);

    // // Thresholding with threshold value set 127
    // threshold(src, dst, 127, 255, THRESH_BINARY);
    // imwrite("../opencv-thresh-binary.jpg", dst);

    // // Thresholding using THRESH_BINARY_INV
    // threshold(src, dst, 127, 255, THRESH_BINARY_INV);
    // imwrite("../opencv-thresh-binary-inv.jpg", dst);

    // // Thresholding using THRESH_TRUNC
    // threshold(src, dst, 127, 255, THRESH_TRUNC);
    // imwrite("../opencv-thresh-trunc.jpg", dst);

    // // Thresholding using THRESH_TOZERO
    // threshold(src, dst, 127, 255, THRESH_TOZERO);
    // imwrite("../opencv-thresh-tozero.jpg", dst);
    // // Basic threashold example
    // threshold(src, dst, 127, 255, THRESH_TOZERO_INV);
    // imwrite("../opencv-thresh-to-zero-inv.jpg", dst);
    waitKey();




    return 0;
}