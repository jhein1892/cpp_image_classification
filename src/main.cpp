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

    auto model = readNet("/Users/jacobhein/Desktop/OpenCV/opencv/samples/data/dnn/frozen_inference_graph.pb", "/Users/jacobhein/Desktop/OpenCV/opencv/samples/data/dnn/ssd_mobilenet_v2_coco_2018_03_29.pbtxt", "TensorFlow");
    return 0;
}