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
void Runtime_keys::esc_pressed(bool b){
	_esc_pressed=b;
}
void Runtime_keys::spacebar_pressed(bool b){
	_spacebar_pressed=b;
}

void Runtime_keys::u_pressed(bool b){
	_u_pressed=b;
}

void Runtime_keys::check_key(){


	if (_key_pressed == ESC_KEY) //If esc key is pressed, break loop
	{
		cout << "esc key is pressed, exiting" << endl;
		esc_pressed(true);

	}else if (_key_pressed== SPACEBAR_KEY) //If space key is pressed, start recording. tap again to finish
	{

		if(_spacebar_pressed)
		{
			cout << "Stopped recording" << endl;
			spacebar_pressed(false);
		} else
		{
			cout << "Started recording" << endl;
			spacebar_pressed(true);
		}

	}else if (_key_pressed== U_KEY){
		if(_u_pressed)
		{
			cout << "Stopped uglifing" << endl;
			u_pressed(false);
		} else
		{
			cout << "Started uglifying" << endl;
			u_pressed(true);
		}
	}

}




bool Runtime_keys::esc_pressed(){
	return _esc_pressed;
}
bool Runtime_keys::spacebar_pressed(){
	return _spacebar_pressed;
}
bool Runtime_keys::u_pressed(){
	return _u_pressed;
}
Runtime_keys::Runtime_keys() {
	_esc_pressed=false;
	_spacebar_pressed=false;
	_u_pressed=false;
	_key_pressed=-1;

}
Runtime_keys::~Runtime_keys() {

}
