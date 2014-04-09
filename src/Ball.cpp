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
	_points={0,0};
	_scored=false;
	srand(time(0));
	_v[0]=rand()%(MAX_SPEED)-(MAX_SPEED-MIN_SPEED);
	_v[1]=rand()%(MAX_SPEED)-(MAX_SPEED-MIN_SPEED);
	check_speed();
	cout<<"Initial speed: Vx="<< _v[0]<<" Vy="<<_v[1]<<endl;

}

void Ball::paint (Mat& frame){
	circle(frame,_center,_radius,_color,_thickness,_shift);

}

void Ball::check_roi (Mat& roi_frame,bool side){

	int rows = roi_frame.rows;
	int cols = roi_frame.cols;


	for( size_t i = 0; i < rows; i++ ) {
		for( size_t j = 0; j < cols; j++ ) {
			// Detect interaction between ball and edge and change speed

			if(roi_frame.at<uchar>(i,j)!=0){
				//cout<<"Bouncing on racket "<<endl;
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

int Ball::x(){
	return _center.x;
}

void Ball::x(int x){
	_center.x=x;
}

int Ball::y(){
	return _center.y;
}

void Ball::y(int y){
	_center.y=y;
}
void Ball::update_position(){

	if((y()-_radius<=0)||(y()+_radius>=_frame_size.height))//if bounce with y, invert speed
	{
		_v[1]=-_v[1];

	}else if(x()-_radius<=0)
	{
		_scored=true;
		_points[1]++;
		cout<<"Player right scores!"<<endl;
	}else if(x()+_radius>=_frame_size.width)
	{
		_scored=true;
		_points[0]++;
		cout<<"Player left scores!"<<endl;
	}


	x(x()+_v[0]);

	y(y()+_v[1]);
}

void Ball::v(int vx, int vy){
	_v[0]=vx;
	_v[1]=vy;
}

void Ball::center(Point center){
	_center=center;
}

bool Ball::scored(){
	return _scored;
}

vector<int> Ball::points(){
	return _points;
}

void Ball::scored(bool scored){
	_scored=scored;
}

void Ball::check_speed(){

	// check that either positive and negative are outside the min speed range: abs(speed)>min_speed
	if(_v[0]<MIN_SPEED&&_v[0]>=0){
		_v[0]+=MIN_SPEED;
	}
	if(_v[0]>-MIN_SPEED&&_v[0]<=0){
		_v[0]-=MIN_SPEED;
	}
	if(_v[1]<MIN_SPEED&&_v[1]>=0){
		_v[1]+=MIN_SPEED;
	}
	if(_v[1]>-MIN_SPEED&&_v[1]<=0){
		_v[1]-=MIN_SPEED;
	}
}

Ball::~Ball() {

}
