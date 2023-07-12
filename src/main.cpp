#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

// Points to store the bounding box coordinates
Point top_left_corner, bottom_right_corner;
// image image
Mat image;

void drawRectangle(int action, int x, int y, int flags, void *userdata)
{
    if (action == EVENT_LBUTTONDOWN)
    {
        top_left_corner = Point(x,y);
    }
    else if (action == EVENT_LBUTTONUP)
    {
        bottom_right_corner = Point(x,y);
        // Draw rectangle
        rectangle(image, top_left_corner, bottom_right_corner, Scalar(0, 255, 0), 2, 8);

        imshow("Window", image);
    }
}


int main() {
    std::string image_path = samples::findFile("starry_night.jpg");
    image = imread(image_path);

    // Make temporary image, which will be used to clear the image  
    Mat temp = image.clone();
    // Create a named window
    namedWindow("Window");
    //highgui function called when mouse events occur
    setMouseCallback("Window", drawRectangle);

    int k = 0;
    // loop until q character is pressed
    while(k != 113)
    {
        imshow("Window", image);
        k = waitKey(0);
        // If c is pressed, clear the window, using the dummy image
        if(k == 99)
        {
            temp.copyTo(image);
        }
    }
    destroyAllWindows();
    return 0;
}