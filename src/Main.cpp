#include <highgui.h>

#include <iostream>

using namespace cv;
using namespace std;

#define ESC_KEY 27

int main(int argc, char* argv[])
{
    VideoCapture cap(0); // open default camera

    if (!cap.isOpened())  // if not success, exit program
    {
        cout << "Cannot open the video cam" << endl;
        return -1;
    }

   double videoWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double videoHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
//   int fourcc=static_cast<int>(cap.get(CV_CAP_PROP_FOURCC));
//   double fps=static_cast<double>(cap.get(CV_CAP_PROP_FPS)); //don't work anymore, I give up, I think is my macbook's problem, fuck apple
    cout << "Frame size : " << videoWidth << " x " << videoHeight << endl;
    cout << "Press esc to exit the program" << endl;
    namedWindow("Pong_cv",WINDOW_AUTOSIZE); //create a window called "Pong_cv"

    Size frameSize(static_cast<int>(videoWidth), static_cast<int>(videoHeight)); //set size for each frame



    VideoWriter oVideoWriter ("recording.avi", CV_FOURCC('P','I','M','1'), 20, frameSize, true);


    //For simplicity, recording in mpeg-1

    while (1)
    {
        Mat frame;

        bool frameSuccess = cap.read(frame); // read a new frame from video
        //
         if (!frameSuccess) //if not success, break loop
        {
             cout << "Cannot read a frame from video stream" << endl;
             break;
        }
         oVideoWriter.write(frame);
        imshow("Pong_cv", frame); //show the frame in "MyVideo" window

        if (waitKey(10) == ESC_KEY) //If esc key is pressed, break loop
       {
            cout << "esc key is pressed, exiting" << endl;
            break;
       }
    }
    return 0;

}
