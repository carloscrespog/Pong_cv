/*
 * Ball.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: ccrespo
 */

#include "Ball.h"



Ball::Ball(Point center,int radius, Scalar color,int thickness,int shift) {
	_center=center;
	_radius=radius;
	_color=color;
	_thickness=thickness;
	_shift=shift;

	srand(time(0));
	_v[0]=rand()%MAX_SPEED;
	_v[1]=rand()%MAX_SPEED;

	cout<<"Initial speed: Vx="<< _v[0]<<" Vy="<<_v[1]<<endl;

}

void Ball::paint (Mat& frame){
	circle(frame,_center,_radius,_color,_thickness,_shift);
	//cout<< _color*<<endl;
}



int Ball::_x(){
	return _center.x;
}

void Ball::_x(int x){
	_center.x=x;
}

int Ball::_y(){
	return _center.y;
}

void Ball::_y(int y){
	_center.y=y;
}
void Ball::update_position(){

	_x(_x()+_v[0]);

	_y(_y()+_v[1]);
}
Ball::~Ball() {
	// TODO Auto-generated destructor stub
}
