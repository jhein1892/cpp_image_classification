#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

int main(){
    std::string image_path = samples::findFile("detect_blob.jpg");
    Mat image = imread(image_path);

    SimpleBlobDetector::Params params;

    params.minThreshold = 10;
    params.maxThreshold = 255;

    params.filterByColor = 1;
    params.blobColor = 255;

    params.filterByArea = 1;
    params.minArea = 100;

    params.filterByCircularity = 1;
    params.minCircularity = 0.4;

    params.filterByConvexity = false;
    // params.minConvexity = 0.87;

    params.filterByInertia = 1;
    params.minInertiaRatio = 0.01;

    Ptr<SimpleBlobDetector> detector = SimpleBlobDetector::create(params);

    std::vector<KeyPoint> keypoints;
    detector->detect(image, keypoints);

    Mat im_with_keypoints;
    drawKeypoints(image, keypoints, im_with_keypoints, Scalar(0,0,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);


    imshow("Keypoints", im_with_keypoints);
    waitKey();

    return 0;
}