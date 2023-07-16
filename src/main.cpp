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
    auto model = readNet("../../input/DenseNet_121.prototxt", "../../input/DenseNet+121.caffemodel", "Caffe");
    return 0;
}