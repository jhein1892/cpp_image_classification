#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>



using namespace cv;
using namespace std;

int main(){
    string image_path = samples::findFile("starry_night.jpg");
    Mat img = imread(image_path, IMREAD_COLOR);

    if(img.empty()){
        cout << "Could not read the image: " << image_path << endl;
        return 1;
    }

    imshow("Display Window", img);
    int k = waitKey(0);
    if(k == 's'){
        imwrite("starry_night.png", img);
    }

    destroyAllWindows();

    return 0;

}