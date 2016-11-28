#include <windows.h>
#include <string>
#include <iostream>
using namespace std;
bool clicking;
int x;
int y;

static void startclicker()
{
	while (true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			Sleep(100);
			POINT cursorPos;
			GetCursorPos(&cursorPos);
			//x = 0;
			x = cursorPos.x;
			//y = 0;
			y = cursorPos.y;
			cout << "Mouse X = " << x << endl;
			cout << "Mouse Y = " << y << endl;

		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			cout << "Bye Bye <3 " << endl;
			Sleep(500);
			system("exit");
		}
		if (GetAsyncKeyState(VK_NUMPAD2))
		{
			cout << "Clicking !" << endl;
			Sleep(100);
			clicking = true;

			while (true)
			{

				if(!clicking)
				{
					break;
				}

				//Sleep(100);
				SetCursorPos(x, y);
				mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);

				if (GetAsyncKeyState(VK_NUMPAD3))
				{
					clicking = false;
					cout << "Stopping the clicker.." << endl;
				}

				if (GetAsyncKeyState(VK_ESCAPE))
				{
					cout << "Bye Bye <3 " << endl;
					Sleep(500);
					system("exit");
				}
			}
		}
		
	}
}

static void init()
{
	clicking = false;
	system("TITLE Mouse Clicker by sandaasu");
	cout << "======================================================" << endl;
	cout << "[ HOTKEYS ]" << endl << endl;
	cout << "NumPad1 = save mouse position" << endl;
	cout << "NumPad2 = activate autoclicker on saved position" << endl;
	cout << "NumPad3 = STOP" << endl;
	cout << "Escape  = Close" << endl << endl << endl;
	cout << " " << endl << endl;
	cout << "======================================================" << endl;
	cout << " " << endl << endl;
	cout << "[ LOG ] " << endl << endl;
	startclicker();
}



void main()
{
	init();
}

