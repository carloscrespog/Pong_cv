/*
 * Runtime_keys.cpp
 *
 *  Created on: Apr 6, 2014
 *      Author: ccrespo
 */

#include "Runtime_keys.h"

void Runtime_keys::key_pressed(int key){
	_key_pressed=key;
}


void Runtime_keys::check_esc(){
	while(1){
		usleep(100000);
		cout << "esc? "<< _key_pressed << endl;
		if (_key_pressed == ESC_KEY) //If esc key is pressed, break loop
		{
			cout << "esc key is pressed, exiting" << endl;
			_esc_pressed=true;
			//key_pressed(0);
		}

	}
}

void Runtime_keys::check_spacebar(){
	while(1){
		usleep(100000);
		if (_key_pressed== SPACEBAR_KEY) //If esc key is pressed, break loop
		{
			cout << "spacebar key is pressed, recording" << endl;
			_spacebar_pressed=true;
			//key_pressed(0);
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
	_key_pressed=69;

}
Runtime_keys::~Runtime_keys() {
	// TODO Auto-generated destructor stub
}
