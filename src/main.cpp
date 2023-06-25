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

    Mat cropped_img = img(Range(80,280), Range(150,330));

    imshow("Original Image", img);
    imshow("Cropped Image", cropped_img);

    imwrite("./Cropped Image.jpg", cropped_img);

    waitKey(0);

    return 0;
}