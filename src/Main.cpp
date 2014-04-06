


#include "Record.h"
#include "Runtime_keys.h"
#include "Ball.h"

#define w 400

using namespace cv;
using namespace std;



void MyFilledCircle( Mat img, Point center );

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
	cout << "Press spacebar to start/stop recording" << endl;
	namedWindow("Pong_cv",WINDOW_AUTOSIZE); //create a window called "Pong_cv"

	Size frameSize(static_cast<int>(videoWidth), static_cast<int>(videoHeight)); //set size for each frame


	Record recorder ( 20, frameSize);
	Runtime_keys runtime_keys;
	Ball myBall(Point(videoWidth/2,videoHeight/2),videoWidth/30,Scalar( 192, 189, 91 ),-1,8);
	Mat frame;
	Mat fram2;
	while (1)
	{


		bool frameSuccess = cap.read(frame); // read a new frame from video
		myBall.update_position();
		//cout<<myBall._x()<<endl;
		myBall.paint(frame);


		if (!frameSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		if(runtime_keys.spacebar_pressed()){
			recorder.write_frame(frame);
		}

		flip(frame, fram2,1);

		imshow("Pong_cv", fram2); //show the frame in the  window
		int kp=waitKey(10);

		runtime_keys.key_pressed(kp);
		runtime_keys.check_key();

		if (runtime_keys.esc_pressed()) //If esc key is pressed, break loop
		{
			break;
		}
	}

	return 0;

}

void MyFilledCircle( Mat img, Point center )
{
	int thickness = -1;
	int lineType = 8;

	circle( img,
			center,
			w/32,
			Scalar( 0, 0, 255 ),
			thickness,
			lineType );
}
