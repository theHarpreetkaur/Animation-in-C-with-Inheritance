/**************************************************************************************************
Filename: AnimationManager.cpp
Version: 1.0
Purpose: Contains methods to edit/delete Animations, and overloads the >> and << operators
**************************************************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <forward_list>
using namespace std;
#include "Frame.h"
#include "AudioFrame.h"
#include "VideoFrame.h"
#include "Animation.h"
#include "AnimationManager.h"


/**************************************************************************************************
Function Name:		EditAnimation
Purpose:			Edits an Animation


**************************************************************************************************/
void AnimationManager::EditAnimation() {
	
	unsigned int index;	// index of Animation  to edit
	char menu;	// selected menu option
	
	// flush cin from previous menu
		if (cin.get() != '\n') {
			
			cout << "Please enter a valid option" << endl;
				while (cin.get() != '\n');
				return;
			
		}

	// check if vector is empty
	if (this->animations.empty()) {
		
		cout << "There are no Animations in the Animation Manager" << endl;
		return;
	
	}

	
	// get index of Animation to edit
	cout << "Which Animation do you wish to edit? Please give the index (from 0 to " << this->animations.size() - 1 << "): ";
	cin >> index;
	// check for non-integers or extra char
	
	if (cin.fail() || cin.get() != '\n') {
		cout << "Invalid index" << endl;
		cin.clear();
		while (cin.get() != '\n');
		return;
		
	}
	// check if index is within range
	if (index < 0 || index >= this->animations.size()) {
		
		cout << "Index out of range" << endl;
		return;
	
	}


	Animation& editAnimation = this->animations.at(index);	// reference to Animation to edit
	
	cout << "Editing Animation #" << index << endl;
	
	
	
	// Frame menu
	while (true) {
		
		cout << "MENU\n";
		cout << "1. Insert a Frame at front\n";
		cout << "2. Delete first Frame\n";
		cout << "3. Edit a Frame\n";
		cout << "4. Quit" << endl;
		

		cin >> menu;
		// loop back to menu if more than 1 character entered
		
		if (cin.get() != '\n') {
			cout << "Please enter a valid option" << endl;
			while (cin.get() != '\n');
			
			continue;
		}

		switch (menu) {
		case '1':	// add new Frame
			cin >> editAnimation;
			break;
			
		case '2':	// delete Frame
			editAnimation.DeleteFrame();
			break;
			
		case '3':	// edit Frame
			editAnimation.EditFrame();
			break;
			
		case '4':	// quit
			cout << "Animation #" << index << " edit complete" << endl;
			return;	// return to previous menu
			
		default:
			cout << "Please enter a valid option" << endl;
		}
}
}

/**************************************************************************************************
Function Name:		DeleteAnimation
Purpose:			Deletes an Animation
**************************************************************************************************/
void AnimationManager::DeleteAnimation() {
	
	unsigned int index;	// index of Animation to delete
	
	// flush cin from previous menu
	if (cin.get() != '\n') {
		
		cout << "Please enter a valid option" << endl;
		 while (cin.get() != '\n');
		
		return;
		
	}

	cout << "Delete an Animation from the Animation Manager" << endl;
	// check if vector is empty
	if (this->animations.empty()) {
		cout << "There are no Animations in the Animation Manager" << endl;
		return;
		
	}

	
	// get index of Animation to delete
	cout << "Which Animation do you wish to delete? Please give the index in the range of 0 to " << this->animations.size() - 1 << ": ";
	cin >> index;
	
	
	// check for non-integers or extra characters
	if (cin.fail() || cin.get() != '\n') {
		cout << "Invalid index" << endl;
		cin.clear();
		while (cin.get() != '\n');
		return;
	}
	
	
	// check if index is within range
	if (index < 0 || index >= this->animations.size()) {
		cout << "Index out of range" << endl;
		return;
	}
	
	
	// delete the Animation
	this->animations.erase(this->animations.begin() + index);
	
	cout << "Animation #" << index << " deleted" << endl;
	
	
}

/**************************************************************************************************
Function Name:		operator>>
Purpose:			Overloads the >> operator to add a new Animation to the back of the vector
**************************************************************************************************/

istream& operator>>(istream& in, AnimationManager& rAnimationManager) {
	// flush cin from previous menu
	
	string animationName;	// name of the new Animation
	
	
	if (in.get() != '\n') {
		cout << "Please enter a valid option" << endl;
		while (in.get() != '\n');
		return in;
	}

	
	cout << "Add an Animation to the Animation Manager" << endl;
	// get the animation name
	cout << "Please enter the Animation Name: ";
	in >> animationName;
	// check for spaces in name
	
	
	if (in.get() != '\n') {
		cout << "Invalid name cannot contain spaces" << endl;
		while (in.get() != '\n');
		return in;
	}

	// add new Animation to the back of the vector
	rAnimationManager.animations.reserve(64);	// reserve capacity for animations
	rAnimationManager.animations.emplace_back(Animation(animationName));
	
	cout << "Animation " << animationName << " added at the back of animations" << endl;
	return in;
	
	
}

/**************************************************************************************************
Function Name:		operator<<
Purpose:			Overloads the << operator to print out all Animations in the vector
**************************************************************************************************/
ostream& operator<<(ostream& out, AnimationManager& rAnimationManager){
	
	
	
	// flush cin from previous menu
	if (cin.get() != '\n') {
		out << "Please enter a valid option" << endl;
		while (cin.get() != '\n');
		return out;
	}
	
	

	out << "AnimationManager: " << rAnimationManager.managerName << endl;

	// check if vector is empty
	if (rAnimationManager.animations.empty()) {
		out << "No Animations in the Animation Manager" << endl;
	}
	
	
	else {
		unsigned int count;;	// counter for animation number
		// iterate through vector
		for (count = 0; count < rAnimationManager.animations.size(); ++count) {
			out << "Animation: " << count << endl;
			out << rAnimationManager.animations.at(count);
	}
	}
	
	
	return out;
	
	
	
	
	
}