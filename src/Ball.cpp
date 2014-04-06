/*
 * Ball.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: ccrespo
 */

#include "Ball.h"

Ball::Ball(Point center,int radius, void* color,int thickness,int shift) {
	_center=center;
	_radius=radius;
	_color=&color;
	_thickness=thickness;
	_shift=shift;

}

void Ball::paint (Mat& frame){
	circle(frame,_center,_radius,*_color,_thickness,_shift);
}

Ball::~Ball() {
	// TODO Auto-generated destructor stub
}
