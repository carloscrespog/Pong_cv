/*
 * Runtime_keys.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: ccrespo
 */

#include "Runtime_keys.h"


void Runtime_keys::check_esc(){
	while(1){
	if (waitKey(10) == ESC_KEY) //If esc key is pressed, break loop
	{
		cout << "esc key is pressed, exiting" << endl;
		_esc_pressed=true;
	}
	}
}

void Runtime_keys::check_spacebar(){
	while(1){
	if (waitKey(10) == SPACEBAR_KEY) //If esc key is pressed, break loop
	{
		cout << "spacebar key is pressed, recording" << endl;
		_spacebar_pressed=true;
	}
	}
}

bool Runtime_keys::esc_pressed(){
	return _esc_pressed;
}
bool Runtime_keys::spacebar_pressed(){
	return _spacebar_pressed;
}
Runtime_keys::Runtime_keys() {
	_esc_pressed=false;
	_spacebar_pressed=true;

}
Runtime_keys::~Runtime_keys() {
	// TODO Auto-generated destructor stub
}
