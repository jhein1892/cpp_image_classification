// Object Detection
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/all_layers.hpp>

using namespace cv;
using namespace dnn;

int main(){
    std::vector<std::string> class_names;
    std::ifstream ifs(std::string("/Users/jacobhein/Desktop/OpenCV/opencv/samples/data/dnn/object_detection_classes_coco.txt").c_str());
    std::string line;
    while(std::getline(ifs, line))
    {
       class_names.push_back(line);
    }
    std::string image_path = samples::findFile("object_detection.jpg");
    Mat image = imread(image_path);
    int image_height = image.cols;
    int image_width = image.rows;

    Mat blob = blobFromImage(image, 1.0, Size(300, 300), Scalar(127.5, 127.5, 127.5), true, false);

    auto model = readNet("/Users/jacobhein/Desktop/OpenCV/opencv/samples/data/dnn/frozen_inference_graph.pb", "/Users/jacobhein/Desktop/OpenCV/opencv/samples/data/dnn/ssd_mobilenet_v2_coco_2018_03_29.pbtxt", "TensorFlow");

    model.setInput(blob);

    Mat output = model.forward();
    Mat detectionMat(output.size[2], output.size[3], CV_32F, output.ptr<float>());

    for
    return 0;
}