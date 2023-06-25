#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main()
{
    string image_path = samples::findFile("starry_night.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);

    std::cout << "Width: " << img.size().width << std::endl;
    std::cout << "Height: " << img.size().height << std::endl;

    

    return 0;
}