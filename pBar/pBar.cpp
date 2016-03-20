/*
Name: pBar
Description: an easy way to get a progress bar in your program!
Author: ETCG
Note: This project is solely for your benefit, and I do not take any responsibility for anything you use pBar for, or any issues it causes. Use at your own risk. 

Copyright: MIT License

Copyright (c) 2016 ETCG

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

//Includes:
#include <iostream> //For I/O
#include <string> //For strings
#include <ctime> //For demo

//Namespace:
using namespace std;

//Class:
class pBar {
public:
	void update(double newProgress) {
		currentProgress += newProgress;
		amountOfFiller = (int)((currentProgress / neededProgress)*(double)pBarLength);
	}
	void print() {
		currUpdateVal %= pBarUpdater.length();
		cout << "\r" //Bring cursor to start of line
			<< firstPartOfpBar; //Print out first part of pBar
		for (int a = 0; a < amountOfFiller; a++) { //Print out current progress
			cout << pBarFiller;
		}
		cout << pBarUpdater[currUpdateVal];
		for (int b = 0; b < pBarLength - amountOfFiller; b++) { //Print out spaces
			cout << " ";
		}
		cout << lastPartOfpBar //Print out last part of progress bar
			<< " (" << (int)(100*(currentProgress/neededProgress)) << "%)" //This just prints out the percent
			<< flush;
		currUpdateVal += 1;
	}
	std::string firstPartOfpBar = "[", //Change these at will (that is why I made them public)
		lastPartOfpBar = "]",
		pBarFiller = "|",
		pBarUpdater = "/-\\|";
private:
	int amountOfFiller,
		pBarLength = 50, //I would recommend NOT changing this
		currUpdateVal = 0; //Do not change
	double currentProgress = 0, //Do not change
		neededProgress = 100; //I would recommend NOT changing this
};

//What an example of your code could look like:
int main() {
	//Setup:
	pBar bar;
	//Main loop:
	for (int i = 0; i < 100; i++) { //This can be any loop, but I just made this as an example
		//Update pBar:
		bar.update(1); //How much new progress was added (only needed when new progress was added)
		//Print pBar:
		bar.print(); //This should be called more frequently than it is in this demo (you'll have to see what looks best for your program)
		sleep(1);
	}
	cout << endl;
	return 0;
}