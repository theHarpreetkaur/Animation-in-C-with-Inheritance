/**************************************************************************************************
Filename: VideoFrame.cpp
Version: 1.0

Purpose: Calculates Frame resources and overloads the << operator to print out Frame information
**************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "Frame.h"
#include "VideoFrame.h"


/**************************************************************************************************

Function Name:		CalculateFrameResource
Purpose:			Prints a table of file sizes for different number 

**************************************************************************************************/


void VideoFrame::CalculateFrameResource() {
	
	cout << *this << endl;
	cout << "Lempel-Ziv-Welch Lossless Compression" << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	cout << setw(15) << left << "colours:";
	
	int numBits = 1;	// numbers of bits in the table 
	
	for (int i = 0 ; i < this->BITS ; ++i) {
		
		numBits *= 2;
		cout << " | " << setw(6) << left << numBits;
		
	}
	
	
	cout << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	
	cout << setw(15) << left << "file size (MB):";
	
	cout << setprecision(4);	// set the precision to the 4 
	
	for (int i = 0; i < this->BITS; ++i) {
	
		cout << " | " << setw(6) << this->size / (this->COMPRESSION_RATIO
		
		* this->BITDEPTH_FACTOR[i]);
	
	}
	
	cout << endl;
	cout << "----------------------------------------------------------------------------------------" << endl;
	
}




ostream& operator<<(ostream& out, VideoFrame& rVideoFrame) {
	out << "VideoFrame: " << static_cast<Frame&>(rVideoFrame);
	return out;
}