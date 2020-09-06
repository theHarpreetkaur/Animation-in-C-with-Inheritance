/**************************************************************************************************
Filename: AudioFrame.cpp
Version: 1.0

Purpose: Calculates Frame resources and overloads the << operator to print out Frame information

**************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
#include "Frame.h"
#include "AudioFrame.h"

/**************************************************************************************************
Function Name:		CalculateFrameResource
Purpose:			Prints a table of file sizes  for different  bitrates

**************************************************************************************************/

void AudioFrame::CalculateFrameResource() {
	
	cout << *this << endl;
	cout << "MP3 Lossy Compression" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << setw(25) << left << "bitrate (kbits/s):";
	cout << setprecision(0) << fixed;	// no decimals in header
	for (int i = 0; i < this->RATES; ++i) {
		cout << " | " << setw(6) << left << this->BITRATE[i];
	}
	
	
	
	cout << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << setw(25) << left << "file size (MB):";
	cout << setprecision(3);	// set precision to 3 
	cout.unsetf(ios_base::floatfield);	// reset flag to default float
		
		
		for (int i = 0; i < this->RATES; ++i) {
			cout << " | " << setw(6) << this->size / this->COMPRESSION_RATIO[i];
			
		}
		
		
		cout << endl;
		cout << "---------------------------------------------------------" << endl;
		
		
	}

/**************************************************************************************************

Function Name:		operator<<
Purpose:			Overloads the << operator to print out the AudioFrame name

**************************************************************************************************/


ostream& operator<<(ostream& out, AudioFrame& rAudioFrame) {
	
	out << "AudioFrame: " << static_cast<Frame&>(rAudioFrame);
	return out;
	
}