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

    for(int i = 0; i < detectionMat.rows; i++){
        int class_id = detectionMat.at<float>(i, 1);
        float confidence = detectionMat.at<float>(i, 2);

        if (confidence > 0.4){
             int box_x = static_cast<int>(detectionMat.at<float>(i, 3) * image.cols);
           int box_y = static_cast<int>(detectionMat.at<float>(i, 4) * image.rows);
           int box_width = static_cast<int>(detectionMat.at<float>(i, 5) * image.cols - box_x);
           int box_height = static_cast<int>(detectionMat.at<float>(i, 6) * image.rows - box_y);
           rectangle(image, Point(box_x, box_y), Point(box_x+box_width, box_y+box_height), Scalar(255,255,255), 2);
           putText(image, class_names[class_id-1].c_str(), Point(box_x, box_y-5), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0,255,255), 1);
       }
   }

   imshow("image", image);
   waitKey(0);
   destroyAllWindows();
    return 0;
}