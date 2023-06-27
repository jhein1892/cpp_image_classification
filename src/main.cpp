#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(){

    std::string image_path = samples::findFile("starry_night.jpg");
    Mat image = imread(image_path);

    if(image.empty()){
        std::cout << "Empty Image" << std::endl;
    }

    // Apply identity filter using kernal
    Mat kernal1 = (Mat_<double>(3,3) <<0,0,0,0,1,0,0,0,0);
    Mat identity;
    filter2D(image, identity, -1, kernal1, Point(-1, 1), 0, 4);
    imshow("Original", image);
    imshow("Identity", identity);
    waitKey();
    destroyAllWindows();

    // Blurred using kernal
    // Initialize matrix with all ones
    Mat kernal2 = Mat::ones(5,5, CV_64F);
    // Normalize the elements
    kernal2 = kernal2 / 25;

    Mat img;
    filter2D(image, img, -1, kernal2, Point(-1, 1), 0, 4);
    imshow("Original", image);
    imshow("Identity", identity);
    imshow("Kernel blur", img);
    waitKey();
    destroyAllWindows();

    return 0;
}