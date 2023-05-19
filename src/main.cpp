#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
    string path = "Your_image_dir";
    Mat img = imread(path);
    imshow("image", img);
    waitKey(0);
    return 0;
}