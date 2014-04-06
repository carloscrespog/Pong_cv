/*
 * Record.cpp
 *
 *  Created on: Apr 5, 2014
 *      Author: ccrespo
 */

#include "Record.h"
#define RECORD_FILE "recording.avi"


Record::Record(int fps, Size frameSize) {
	// TODO Auto-generated constructor stub
	_oVideoWriter=VideoWriter("recording.avi", CV_FOURCC('P','I','M','1'), fps, frameSize, true);
	//For simplicity, recording in mpeg-1

}
void Record::write_frame(Mat frame){
	_oVideoWriter.write(frame);
}

Record::~Record() {
	// TODO Auto-generated destructor stub
}
