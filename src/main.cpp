#include <opencv2/opencv.hpp>
#include <iostream>
#include <random>

using namespace cv;

int computeMedian(std::vector<int> elements)
{
    nth_element(elements.begin(), elements.begin()+elements.size()/2, elements.end());
    return elements[elements.size()/2];
}

Mat compute_median(std::vector<Mat> vec)
{
    Mat medianImg(vec[0].rows, vec[0].cols, CV_8UC3, Scalar(0,0,0));
    
    for(int row = 0; row<vec[0].rows; row++)
    {
        for(int col = 0; col<vec[0].cols; col++){
            std::vector<int> elements_B;
            std::vector<int> elements_G;
            std::vector<int> elements_R;

            for(int imgNumber=0; imgNumber<vec.size(); imgNumber++)
            {
                int B = vec[imgNumber].at<Vec3b>(row, col)[0];
                int G = vec[imgNumber].at<Vec3b>(row, col)[1];
                int R = vec[imgNumber].at<Vec3b>(row, col)[2];

                elements_B.push_back(B);
                elements_G.push_back(G);
                elements_R.push_back(R);
            }

            medianImg.at<Vec3b>(row, col)[0] = computeMedian(elements_B);
            medianImg.at<Vec3b>(row, col)[1] = computeMedian(elements_G);
            medianImg.at<Vec3b>(row, col)[2] = computeMedian(elements_R);
        }
    }
    return medianImg
}

int main(){
    return 0;
}