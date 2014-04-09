

#include "opencv2/imgproc/imgproc.hpp"
#include "Record.h"
#include "Runtime_keys.h"
#include "Ball.h"


using namespace cv;
using namespace std;

void set_text(Mat& frame, const std::string label,Point p,double scale, int thickness);
void init_sequence(Mat& frame,int countFrame, int countdown);

Mat src, src_gray;
Mat dst, detected_edges;

int edgeThresh = 1;
int lowThreshold;
int const max_lowThreshold = 100;
int lratio = 3;
int kernel_size = 3;

static void CannyThreshold(int, void*)
{
	/// Reduce noise with a kernel 3x3
	blur( src_gray, detected_edges, Size(3,3) );

	/// Canny detector
	Canny( detected_edges, detected_edges, lowThreshold, lowThreshold*lratio, kernel_size );

	/// Using Canny's output as a mask, we display our result
	dst = Scalar::all(0);

	src.copyTo( dst, detected_edges);
	//imshow( window_name, dst );
}

int main(int argc, char* argv[])
{

	static int countdown=100;	//initial countdown in frames
	int win_countdown=countdown/2;
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
	cout << "Press u to uglify (see Canny edge detector)" << endl;
	namedWindow("Pong_cv",WINDOW_AUTOSIZE); //create a window called "Pong_cv"

	Size frameSize(static_cast<int>(videoWidth), static_cast<int>(videoHeight)); //set size for each frame


	Record recorder ( 20, frameSize);
	Runtime_keys runtime_keys;

	Ball myBall(Point(videoWidth/2,videoHeight/2),videoWidth/30,Scalar( 192, 189, 91 ),-1,8,frameSize);

	Mat frame;
	Mat fram2;
	bool running=true;
	int countFrame=0;
	createTrackbar( "Min Canny Threshold:", "Pong_cv", &lowThreshold, max_lowThreshold, CannyThreshold );
	setTrackbarPos("Min Canny Threshold:","Pong_cv",10);

	while (running)
	{
		bool frameSuccess = cap.read(frame); // read a new frame from video

		if (!frameSuccess) //if not success, break loop
		{
			cout << "Cannot read a frame from video stream" << endl;
			break;
		}
		if(myBall.scored()){

			stringstream strm;
			strm<<myBall.points()[0]<<"-"<<myBall.points()[1];

			myBall.center(Point(videoWidth/2,videoHeight/2));
			srand(time(0));
			myBall.v(rand()%(MAX_SPEED)-(MAX_SPEED-MIN_SPEED),rand()%(MAX_SPEED)-(MAX_SPEED-MIN_SPEED));
			myBall.check_speed();
			myBall.paint(frame);
			flip(frame, fram2,1);
			set_text(fram2,strm.str(),Point(frame.cols/2,frame.rows/2),6,10);

			if(myBall.points()[0]==10||myBall.points()[1]==10)
			{
				set_text(fram2,"Game finished",Point(frame.cols/2,frame.rows/2 + 100),2,7);
				win_countdown++; //never reach 0
				//runtime_keys.u_pressed(true);
			}


			if(win_countdown>=0)
			{
				win_countdown--;

			}else
			{
				myBall.scored(false);
				countFrame=countdown/2;
				win_countdown=countdown/2;
			}


		}else if(countFrame>=countdown)
		{
			myBall.update_position();
			myBall.paint(frame);
			flip(frame, fram2,1);

			//check if rectangle is outside frame & if ball is in racket's area
			if(((myBall.x()<=dst.cols/6)||(myBall.x()>=dst.cols*5/6))&&(myBall.x()-myBall.radius()>=0)&&(myBall.x()+myBall.radius()<=dst.cols)
					&&(myBall.y()-myBall.radius()>=0)&&(myBall.y()+myBall.radius()<=dst.rows))
			{

				Rect region_of_interest=Rect(dst.cols-myBall.x(),dst.rows-myBall.y(),myBall.radius(),myBall.radius());
				Mat image_roi=dst(region_of_interest);

				myBall.check_roi(image_roi,(myBall.x()<=dst.cols/6));
			}

		} else
		{
			countFrame++;
			flip(frame, fram2,1);
			init_sequence(fram2,countFrame,countdown);

		}


		if(runtime_keys.spacebar_pressed())
		{
			recorder.write_frame(frame);
		}
		src = fram2;
		cvtColor( src, src_gray, COLOR_BGR2GRAY );
		CannyThreshold(0,0);

		line(fram2,Point(fram2.cols/6,0),Point(fram2.cols/6,fram2.rows),Scalar( 192, 189, 91 ),3,8,0);	// draw two lines that delimit the racket areas
		line(fram2,Point(fram2.cols*5/6,0),Point(fram2.cols*5/6,fram2.rows),Scalar( 192, 189, 91 ),3,8,0);


		if(runtime_keys.u_pressed())
		{
			imshow("Pong_cv", dst); //show the ugly frame in the  window
		}else
		{
			imshow("Pong_cv", fram2); //show the frame in the  window
		}


		int kp=waitKey(10);

		runtime_keys.key_pressed(kp);
		runtime_keys.check_key();

		if (runtime_keys.esc_pressed()) //If esc key is pressed, break loop
		{
			//cout << "M = "<< endl << " "  << dst << endl << endl;
			running=false;;
		}
	}

	return 0;

}

void set_text(Mat& frame,  const string label,Point p,double scale, int thickness){
	int fontface = FONT_HERSHEY_SIMPLEX;
	int baseline=0;

	Size text = cv::getTextSize(label, fontface, scale, thickness, &baseline);

	Point pt(p.x-(text.width/2),p.y+(text.height/2));

	putText(frame, label, pt, fontface, scale, CV_RGB(255,255,255), thickness, 8);
}

void init_sequence(Mat& frame,int countFrame, int countdown){
	int current_countdown=(countdown-countFrame)/(countdown/10);
	set_text(frame,to_string(current_countdown),Point(frame.cols/2,frame.rows/2),20,30);

}
