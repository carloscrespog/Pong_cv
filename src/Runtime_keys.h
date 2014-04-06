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

#include <iostream>
#include <thread>
#include "Record.h"

using namespace std;
using namespace cv;
class Runtime_keys {
public:
	Runtime_keys();
	virtual ~Runtime_keys();
	void check_esc();
	void check_spacebar();
	bool esc_pressed();
	bool spacebar_pressed();
private:
	bool _esc_pressed;
	bool _spacebar_pressed;
};

#endif /* RUNTIME_KEYS_H_ */
