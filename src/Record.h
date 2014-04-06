/*
 * Record.h
 *
 *  Created on: Apr 5, 2014
 *      Author: ccrespo
 */
#include <highgui.h>
#ifndef RECORD_H_
#define RECORD_H_
using namespace cv;

class Record {
public:
	Record(int fps, Size frameSize);
	virtual ~Record();
	void write_frame(Mat frame);
	bool recording();
private:
	VideoWriter _oVideoWriter;

};

#endif /* RECORD_H_ */
