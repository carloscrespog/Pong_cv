/*
 * Ball.h
 *
 *  Created on: Apr 6, 2014
 *      Author: ccrespo
 */

#ifndef BALL_H_
#define BALL_H_

#include <highgui.h>
using namespace cv;
using namespace std;
class Ball {
public:
	Ball(Point center,int radius, Scalar color,int thickness,int shift);
	virtual ~Ball();
	void paint (Mat& frame);
private:
	Point _center;
	int _radius;
	Scalar _color;
	int _thickness;
	int _shift;
};

#endif /* BALL_H_ */
