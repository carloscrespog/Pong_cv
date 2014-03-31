#include <highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;

int main(int argc, char* argv[])
{
    VideoCapture cap(0); // open default camera

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the video cam" << endl;
        return -1;
    }

   double videoWidth = cap.get(CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double videoHeight = cap.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    cout << "Frame size : " << videoWidth << " x " << videoHeight << endl;
    cout << "Press esc to exit the program" << endl;
    namedWindow("Pong_cv",WINDOW_AUTOSIZE); //create a window called "Pong_cv"

    while (1)
    {
        Mat frame;

        bool frameSuccess = cap.read(frame); // read a new frame from video

         if (!frameSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }

        imshow("Pong_cv", frame); //show the frame in "MyVideo" window

        if (waitKey(10) == 27) //If esc key is pressed, break loop
       {
            cout << "esc key is pressed, exiting" << endl;
            break;
       }
    }
    return 0;

}
