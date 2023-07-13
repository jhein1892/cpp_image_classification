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

    // Mat channels[3];
    // split(img, channels);
 
    // // detect contours using blue channel and without thresholding
    // std::vector<std::vector<Point>> contours1;
    // std::vector<Vec4i> hierarchy1;
    // findContours(channels[0], contours1, hierarchy1, RETR_TREE, CHAIN_APPROX_NONE);
    // // draw contours on the original image
    // Mat image_contour_blue = img.clone();
    // drawContours(image_contour_blue, contours1, -1, Scalar(0, 255, 0), 2);
    // imshow("Contour detection using blue channels only", image_contour_blue);
    // waitKey(0);
    // imwrite("blue_channel.jpg", image_contour_blue);
    // destroyAllWindows();
    
    // detect contours using green channel and without thresholding
    // std::vector<std::vector<Point>> contours2;
    // std::vector<Vec4i> hierarchy2;
    // findContours(channels[1], contours2, hierarchy2, RETR_TREE, CHAIN_APPROX_NONE);
    // // draw contours on the original image
    // Mat image_contour_green = img.clone();
    // drawContours(image_contour_green, contours2, -1, Scalar(0, 255, 0), 2);
    // imshow("Contour detection using green channels only", image_contour_green);
    // waitKey(0);
    // imwrite("green_channel.jpg", image_contour_green);
    // destroyAllWindows();
    
    // // detect contours using red channel and without thresholding
    // std::vector<std::vector<Point>> contours3;
    // std::vector<Vec4i> hierarchy3;
    // findContours(channels[2], contours3, hierarchy3, RETR_TREE, CHAIN_APPROX_NONE);
    // // draw contours on the original image
    // Mat image_contour_red = img.clone();
    // drawContours(image_contour_red, contours3, -1, Scalar(0, 255, 0), 2);
    // imshow("Contour detection using red channels only", image_contour_red);
    // waitKey(0);
    // imwrite("red_channel.jpg", image_contour_red);
    // destroyAllWindows();

    // Now let us try with CHAIN_APPROX_SIMPLE`
    // detect the contours on the binary image using cv2.CHAIN_APPROX_NONE
    std::vector<std::vector<Point>> contours1;
    std::vector<Vec4i> hierarchy1;
    findContours(thresh, contours1, hierarchy1, RETR_TREE, CHAIN_APPROX_SIMPLE);
    // draw contours on the original image
    Mat image_copy1 = img.clone();
    drawContours(image_copy1, contours1, -1, Scalar(0, 255, 0), 2);
    imshow("Simple approximation", image_copy1);
    waitKey(0);
    imwrite("contours_simple_image1.jpg", image_copy1);
    destroyAllWindows();


    return 0;
}