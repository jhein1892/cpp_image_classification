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
    return medianImg;
}

int main(int argc, char const *argv[]){
    std::string video_file;

    if(argc > 1)
    {
        video_file = argv[1];
    }
    else 
    {
        video_file = "/Users/jacobhein/Downloads/IMG_0619.mov";
    }
    VideoCapture cap(video_file);
    if(!cap.isOpened())
        std::cerr << "Error opening video file\n";
    
    // Randomly select 25 frames
    std::default_random_engine generator;
    std::uniform_int_distribution<int>distribution(0,cap.get(CAP_PROP_FRAME_COUNT));

    std::vector<Mat> frames;
    Mat frame;

    for(int i = 0; i< 25; i++)
    {
        int fid = distribution(generator);
        cap.set(CAP_PROP_POS_FRAMES, fid);
        Mat frame;
        cap >> frame;
        if(frame.empty())
            continue;
        frames.push_back(frame);
    }
    // Calculate the median along the time axis
    Mat medianFrame = compute_median(frames);


    cap.set(CAP_PROP_POS_FRAMES, 0);

    Mat grayMedianFrame;
    cvtColor(medianFrame, grayMedianFrame, COLOR_BGR2GRAY);

    while(1)
    {
        cap >> frame;
        if(frame.empty())
            break;
        
        cvtColor(frame, frame, COLOR_BGR2GRAY);

        Mat dframe;
        absdiff(frame, grayMedianFrame, dframe);

        threshold(dframe, dframe, 30, 255, THRESH_BINARY);

        imshow("Frame", dframe);
        waitKey(20);
    }

    cap.release();

    return 0;
}