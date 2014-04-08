/*
 * Ball.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: ccrespo
 */

#include "Ball.h"



Ball::Ball(Point center,int radius, Scalar color,int thickness,int shift,Size frame_size) {
	_center=center;
	_radius=radius;
	_color=color;
	_thickness=thickness;
	_shift=shift;
	_frame_size=frame_size;

	srand(time(0));
	_v[0]=rand()%(MAX_SPEED-MIN_SPEED)+MIN_SPEED;
	_v[1]=rand()%(MAX_SPEED-MIN_SPEED)+MIN_SPEED;

	cout<<"Initial speed: Vx="<< _v[0]<<" Vy="<<_v[1]<<endl;

}

void Ball::paint (Mat& frame){
	circle(frame,_center,_radius,_color,_thickness,_shift);

}

void Ball::check_roi (Mat& roi_frame,bool side){
	//cout<<"Checking racket "<<side<<"    " <<_v[0]<<endl;
	int rows = roi_frame.rows;
	int cols = roi_frame.cols;


	for( size_t i = 0; i < rows; i++ ) {
		for( size_t j = 0; j < cols; j++ ) {
			// Detect interaction between ball and edge and change speed
			//printf("%d" ,roi_frame.at<uchar>(i,j));
			if(roi_frame.at<uchar>(i,j)!=0){
				cout<<"Bouncing on racket "<<endl;
				if(side&&_v[0]<0)
				{
					_v[0]=-_v[0];
				}else if (!side&&_v[0]>0)
				{
					_v[0]=-_v[0];
				}

				break;
				if(j!=cols){
					break;
				}
			}

		}

	}


}

int Ball::radius(){
	return _radius;
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
	if((_x()-_radius<=0)||(_x()+_radius>=_frame_size.width)) //if bounce with x, invert speed
	{
		_v[0]=-_v[0];

	}
	if((_y()-_radius<=0)||(_y()+_radius>=_frame_size.height))//if bounce with y, invert speed
	{
		_v[1]=-_v[1];

	}
	_x(_x()+_v[0]);

	_y(_y()+_v[1]);
}
Ball::~Ball() {

}
