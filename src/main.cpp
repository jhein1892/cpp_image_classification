#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;
int main()
{
    string image_path = samples::findFile("starry_night.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);

    std::cout << "Width: " << img.size().width << std::endl;
    std::cout << "Height: " << img.size().height << std::endl;
    std::cout << "Channels: " << img.channels() << std::endl;

    // Mat cropped_img = img(Range(80,280), Range(150,330));

    // imshow("Original Image", img);
    // imshow("Cropped Image", cropped_img);

    // Writes cropped Image
    // imwrite("../Cropped Image.jpg", cropped_img);

    Mat img_copy = img.clone();
    int imgheight = img.rows;
    int imgWidth = img.cols;

    int M = 76;
    int N = 104;

    int x1 = 0;
    int y1 = 0;

    for (int y = 0; y < imgheight; y = y + M) {
        for (int x = 0; x < imgWidth; x = x + N) {
            if ((imgheight - y) < M || (imgWidth - x) < N){
                break;
            }
            y1 = y + M;
            x1 = x + N;
            string a = to_string(x);
            string b = to_string(y);

            if (x1 < imgWidth && y1 >= imgheight)
            {
                x = imgWidth - 1;
                y = imgheight - 1;
                x1 = imgWidth - 1;
                y1 = imgheight - 1;

                Mat tiles = img_copy(Range(y, imgheight), Range(x, imgWidth));
                imwrite("../saved_patches/tile" + a + "_" + b + ".jpg", tiles);
                rectangle(img, Point(x,y), Point(x1, y1), Scalar(0,255,0), 1);
            }
            else if (y1 >= imgheight)
            {
                y = imgheight - 1;
                y1 = imgheight - 1;

                Mat tiles = img_copy(Range(y, imgheight), Range(x, x + N));
                imwrite("../saved_patches/tile" + a + "_" + b + ".jpg", tiles);
                rectangle(img, Point(x,y), Point(x1, y1), Scalar(0,255,0), 1);
            } 
            else if (x1 >= imgWidth)
            {
                x = imgWidth - 1;
                x1 = imgWidth - 1;

                Mat tiles = img_copy(Range(y, y + M), Range(x, imgWidth));
                imwrite("../saved_patches/tile" + a + "_" + b + ".jpg", tiles);
                rectangle(img, Point(x,y), Point(x1, y1), Scalar(0,255,0), 1);
            }
            else
            {
                Mat tiles = img_copy(Range(y, y + M), Range(x, x + N));
                imwrite("../saved_patches/tile" + a + "_" + b + ".jpg", tiles);
                rectangle(img, Point(x,y), Point(x1, y1), Scalar(0,255,0), 1);
            }
        }
    }

    imshow("Patched Image", img);
    

    waitKey(0);
    destroyAllWindows();

    return 0;
}