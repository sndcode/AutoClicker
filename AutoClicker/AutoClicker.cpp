#include <windows.h>
#include <string>
#include <iostream>
//#include <fstream>
//#include "json.cpp"

using namespace std;
bool clicking = false;
int x = 0;
int y = 0;

int main(){

//ifstream cfg("config.json");

// Intro

system("TITLE Mouse Clicker by sandaasu");
cout << "Mouse Clicker by sandaasu\n";
cout << "======================================================\n";
cout << "[ HOTKEYS ]\n\n";
cout << "Numpad1 = save mouse position\n";
cout << "NumPad2 = activate autoclicker on saved positionn\n";
cout << "NumPad3 = STOP\n";
cout << "Escape  = Close\n\n";
cout << "======================================================\n\n";
cout << "[ LOG ]\n\n";

// Note, needs to refer to config file.
	
// Main Loop

while (true){
	if (GetAsyncKeyState(VK_NUMPAD1)){

		POINT cursorPos;
		GetCursorPos(&cursorPos);
		
		x = cursorPos.x;
		y = cursorPos.y;

		cout << "Mouse X = " << x << endl;
		cout << "Mouse Y = " << y << endl;
		
		Sleep(100);
	}

	//Need to basically be able to have a list for the user to see
	//Location 1 saved: X / Y , location 2, ect.
	//Need an option to turn on specific locations only.
	//Maybe a better location handler... Maybe even named locations.

	//write x AND y to config.json using a name to identify it.
	//OR method of 10 slots, 0-9, and allow user to use them seperately or together.


	if (GetAsyncKeyState(VK_ESCAPE)){
		cout << "Bye Bye <3\n";
		Sleep(500);
		system("exit");}

	if (GetAsyncKeyState(VK_NUMPAD2)) {
		cout << "Clicking !\n";
		clicking = true;
		Sleep(100);}

		while (clicking){

			/*
			for (selected slots) {
			 			
			mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
			}
			*/
			mouse_event(MOUSEEVENTF_ABSOLUTE, x, y, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

			if (GetAsyncKeyState(VK_NUMPAD3)){
				cout << "Stopping the clicker..\n";
				clicking = false;
				break;
				Sleep(100);}
			 
			if (GetAsyncKeyState(VK_ESCAPE)) {
				cout << "Bye Bye <3\n";
				Sleep(500);
				system("exit");}

			Sleep(1); //May not seem to do much, but its not to not lag the computer.
		}
	}
}

