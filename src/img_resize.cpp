#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
    string image_path = samples::findFile("starry_night.jpg");
    Mat img = imread(image_path);
    if(img.empty()){
        std::cout << "Could not read Image" << std::endl;
    }   
    std::cout << "Original Height and Width: "<< img.rows << "x" << img.cols << std::endl;
    imshow("Original Image", img);
    waitKey();

    // int down_width = 300;
    // int down_height = 200;
    // Mat resized_down;
    // resize(img, resized_down, Size(down_width, down_height), INTER_LINEAR);

    // int up_width = 1200;
    // int up_height = 800;
    // Mat resized_up;
    // resize(img, resized_up, Size(up_width, up_height), INTER_LINEAR);

    // imshow("Resized Down by defining height and width", resized_down);
    // waitKey();
    // imshow("Resized Up by defining height and width", resized_up);
    // waitKey();

    // double scale_up_x = 1.2;
    // double scale_up_y = 1.2;

    double scale_down = 0.6;

    Mat scaled_f_up, scaled_f_down;

    resize(img, scaled_f_down, Size(), scale_down, scale_down, INTER_LINEAR);
    // resize(img, scaled_f_up, Size(), scale_up_x, scale_up_y, INTER_LINEAR);

    imshow("Resized Down using scaling", scaled_f_down);
    waitKey();
    // imshow("Resized Up using scaling", scaled_f_up);
    // waitKey();

    Mat res_inter_linear, res_inter_nearest, res_inter_area;
    resize(img, res_inter_linear, Size(), scale_down, scale_down, INTER_LINEAR);
    resize(img, res_inter_nearest, Size(), scale_down, scale_down, INTER_NEAREST);
    resize(img, res_inter_area, Size(), scale_down, scale_down, INTER_AREA);

    Mat a,b,c;
    vconcat(res_inter_linear, res_inter_nearest,a);
    vconcat(res_inter_area, res_inter_area, b);
    vconcat(a,b,c);

    imshow("Inter Linear :: Inter Nearest :: Inter Area :: Inter Area", c);
    waitKey();
    
    // imshow("Resized using Linear", res_inter_linear);
    // waitKey();
    // imshow("Resized using Nearest", res_inter_nearest);
    // waitKey();
    // imshow("Resized using Area", res_inter_area);
    // waitKey();

    destroyAllWindows();

    return 0;
}