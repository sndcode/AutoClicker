#include <windows.h>
#include <string>
#include <iostream>
#include <Endpointvolume.h> 
#include <Mmdeviceapi.h>

using namespace std;

#define RELEASE(__p) {if(__p != nullptr){__p->Release();__p = nullptr;}}

bool IsWindowsPlayingAudio()
{
	bool playing = false;
	bool loopmode = false;
	float epsilon = 1E-07;
	float value = 0;
	HRESULT hr = S_OK;
	IMMDeviceEnumerator* pEnumerator = NULL;
	IMMDevice *pDevice = NULL;
	IAudioMeterInformation *pMeter = NULL;

	CoInitialize(NULL);
	CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_ALL, __uuidof(IMMDeviceEnumerator), (void**)&pEnumerator);
	pEnumerator->GetDefaultAudioEndpoint(EDataFlow::eRender, ERole::eMultimedia, &pDevice);
	pDevice->Activate(__uuidof(IAudioMeterInformation), CLSCTX_ALL, NULL, (void**)&pMeter);
	pMeter->GetPeakValue(&value);
	playing = value > epsilon;

	RELEASE(pMeter);
	RELEASE(pDevice);
	RELEASE(pEnumerator);
	CoUninitialize();
	if (FAILED(hr))
	{
		cout << "An error occurred: 0x%08X\n" << hr << endl;
		return false;
	}

	if (playing)
	{
		cout << "Windows is playing a sound.\n" << endl;
		return true;
	}
	else
	{
		cout << "Windows is not playing a sound.\n" << endl;
		return false;
	}
}

static void startclicker()
{
	bool clicking = true;
	int x = 0;
	int y = 0;
	while (true)
	{
		if (GetAsyncKeyState(VK_NUMPAD1))
		{
			Sleep(100);
			POINT cursorPos;
			GetCursorPos(&cursorPos);
			x = cursorPos.x;
			y = cursorPos.y;
			cout << "Mouse X = " << x << endl;
			cout << "Mouse Y = " << y << endl;
			Sleep(1000);
		}
		if (GetAsyncKeyState(VK_ESCAPE))
		{
			cout << "Bye Bye <3 " << endl;
			Sleep(2000);
			break;
		}

		if (GetAsyncKeyState(VK_NUMPAD2))
		{
			cout << "Clicking !" << endl;
			Sleep(2000);
			clicking = true;

			while (true)
			{
				if (!clicking)
				{
					break;
				}

				if (IsWindowsPlayingAudio() == false)
				{
					Sleep(2000);
					SetCursorPos(x, y);
					mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
					mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
				}				

				if (GetAsyncKeyState(VK_NUMPAD3))
				{
					clicking = false;
					cout << "Stopping the clicker.." << endl;
				}

				if (GetAsyncKeyState(VK_ESCAPE))
				{
					cout << "Bye Bye <3 " << endl;
					Sleep(2000);
					break;
				}
			}
		}

	}
}

static void init()
{
	cout << "Mouse Clicker by sandaasu, Modified by zaas[20220803]" << endl;
	cout << "======================================================" << endl;
	cout << "[ HOTKEYS ]" << endl;
	cout << "NumPad1 = save mouse position" << endl;
	cout << "NumPad2 = activate autoclicker on saved position" << endl;
	cout << "NumPad3 = STOP" << endl;
	cout << "Escape  = Close" << endl;
	cout << "======================================================" << endl;
	cout << " " << endl;
	cout << "[ LOG ] " << endl;
	startclicker();
}

int main()
{
	init();
	return 0;
}

