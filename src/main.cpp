// Image classification
#include <iostream>
#include <fstream>
#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/all_layers.hpp>

using namespace cv;
using namespace dnn;

int main()
{
    std::vector<std::string> class_names;
    std::ifstream ifs(std::string("/Users/jacobhein/Desktop/OpenCV/opencv/samples/data/dnn/classification_classes_ILSVRC2012.txt").c_str());
    std::string line;
    while(std::getline(ifs, line))
    {
        class_names.push_back(line);
    }

    // Load the neural network model
    auto model = readNet("/Users/jacobhein/Desktop/OpenCV/opencv/samples/data/dnn/DenseNet_121.prototxt", "/Users/jacobhein/Desktop/OpenCV/opencv/samples/data/dnn/DenseNet_121.caffemodel", "Caffe");


    std::string image_path = samples::findFile("tiger.jpg");
    Mat image = imread(image_path);
    Mat blob = blobFromImage(image, 0.01, Size(224, 224), Scalar(104, 117, 123));
    return 0;
}