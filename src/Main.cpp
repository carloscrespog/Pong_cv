


#include "Record.h"
#include "Runtime_keys.h"

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

	double videoWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double videoHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
	//   int fourcc=static_cast<int>(cap.get(CV_CAP_PROP_FOURCC));
	//   double fps=static_cast<double>(cap.get(CV_CAP_PROP_FPS)); //don't work anymore, I give up, I think is my macbook's problem, fuck apple
	cout << "Frame size : " << videoWidth << " x " << videoHeight << endl;
	cout << "Press esc to exit the program" << endl;
	namedWindow("Pong_cv",WINDOW_AUTOSIZE); //create a window called "Pong_cv"

	Size frameSize(static_cast<int>(videoWidth), static_cast<int>(videoHeight)); //set size for each frame



	Record recorder ( 20, frameSize);
	Runtime_keys runtime_keys;

	thread key_esc_checker(&Runtime_keys::check_esc,runtime_keys);

	thread key_spacebar_checker(&Runtime_keys::check_spacebar,runtime_keys);

	int key_pressed;

	while (1)
	{

		Mat frame;

		bool frameSuccess = cap.read(frame); // read a new frame from video

		if (!frameSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}

		if(runtime_keys.spacebar_pressed()){
			recorder.write_frame(frame);
		}

		//oVideoWriter.write(frame);

		imshow("Pong_cv", frame); //show the frame in the  window
		 key_pressed=waitKey(10);
		cout<<key_pressed<<endl;
		runtime_keys.key_pressed(key_pressed);
		if (runtime_keys.esc_pressed()) //If esc key is pressed, break loop
		{
			break;
		}
	}
	key_esc_checker.join();
	key_spacebar_checker.join();
	return 0;

}
