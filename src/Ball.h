/*
 * Ball.h
 *
 *  Created on: Apr 6, 2014
 *      Author: ccrespo
 */

#ifndef BALL_H_
#define BALL_H_
#define MAX_SPEED 10
#define MIN_SPEED 5

#include <highgui.h>
#include <iostream>
#include <time.h>

using namespace std;
using namespace cv;

class Ball {
public:
	Ball(Point center,int radius, Scalar color,int thickness,int shift,Size frame_size);
	virtual ~Ball();
	void paint (Mat& frame);
	void check_roi (Mat& roi_frame,bool side);
	void update_position();
	int x();
	void x(int x);
	int y();
	void y(int y);
	int radius();
	bool scored();
	vector<int> points();
private:
	Point _center;
	int _radius;
	Scalar _color;
	int _thickness;
	int _shift;
	Size _frame_size;
	int _v [2];
	vector<int> _points;
	bool _scored;
};

#endif /* BALL_H_ */
