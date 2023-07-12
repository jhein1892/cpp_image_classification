#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;

// Points to store the bounding box coordinates
Point top_left_corner, bottom_right_corner;
// image image
Mat image;
// Used to draw a rectangle on the image
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

// Resizing an image
int maxScaleUp = 100;
int scaleFactor = 1;

std::string windowName = "Resize Image";
std::string trackbarValue = "Scale";

void scaleImage(int, void*)
{
    // Read Image
    std::string image_path = samples::findFile("starry_night.jpg");
    image = imread(image_path);

    double scaleFactorDouble = 1 + scaleFactor/100.0;

    if(scaleFactorDouble == 0)
    {
        scaleFactorDouble = 1;
    }

    Mat scaledImage;
    // Resize the image
    resize(image, scaledImage, Size(), scaleFactorDouble, scaleFactorDouble, INTER_LINEAR);
    // Display the image
    imshow(windowName, scaledImage);
    
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

    // Create a window to display results and set the flag to Autosize
    namedWindow(windowName, WINDOW_AUTOSIZE);

    // Create Trackbards and associate a callback function
    createTrackbar(trackbarValue, windowName, &scaleFactor, maxScaleUp, scaleImage);
    scaleImage(25,0);

    imshow(windowName, image);
    waitKey(0);
    destroyAllWindows();
    return 0;






    return 0;
}