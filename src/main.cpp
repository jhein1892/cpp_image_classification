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
    std::cout << "Channels: " << img.channels() << std::endl;

    // Mat cropped_img = img(Range(80,280), Range(150,330));

    // imshow("Original Image", img);
    // imshow("Cropped Image", cropped_img);

    // Writes cropped Image
    // imwrite("../Cropped Image.jpg", cropped_img);

    Mat img_copy = img.clone();
    int imgheight = img.rows;
    imt imgWidth = img.cols;

    waitKey(0);
    destroyAllWindows();

    return 0;
}