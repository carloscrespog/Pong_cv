/*
 * Runtime_keys.h
 *
 *  Created on: Apr 6, 2014
 *      Author: ccrespo
 */

#ifndef RUNTIME_KEYS_H_
#define RUNTIME_KEYS_H_
#define ESC_KEY 27
#define SPACEBAR_KEY 32
#define U_KEY 117

#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include "Record.h"

using namespace std;
using namespace cv;
class Runtime_keys {
public:
	Runtime_keys();
	virtual ~Runtime_keys();
	void check_key();
	void esc_pressed(bool b);
	void spacebar_pressed(bool b);
	void u_pressed(bool b);
	bool u_pressed();
	bool esc_pressed();
	bool spacebar_pressed();
	void key_pressed(int key);
private:
	bool _esc_pressed;
	bool _spacebar_pressed;
	bool _u_pressed;
	int _key_pressed;
};

#endif /* RUNTIME_KEYS_H_ */
