#include <windows.h>
#include <iostream>
#include <string>


using namespace std;
DWORD ProcessID;


DWORD WINAPI crosshair()
{
	HWND gamehwnd = FindWindowA("Valve001", 0); 
	GetWindowThreadProcessId(gamehwnd, &ProcessID);
	if (gamehwnd) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
		cout << "\nCSGO is running with the PID (" << ProcessID << ").\n";
	}

	else {

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		cout << "[WARNING] CSGO is not running !";
	}

	HDC gamehdc = GetDC(0);

	RECT rect;
	int wc = 8;
	int hc = 8;
	int xPos = ((GetSystemMetrics(SM_CXSCREEN) / 2) - (wc / 2)); 
	int yPos = ((GetSystemMetrics(SM_CYSCREEN) / 2) - (hc / 2));

	HBRUSH br = CreateSolidBrush(RGB(255, 0, 0)); ;
	while (true) {

		if (GetKeyState(0x57)) {

			SelectObject(gamehdc, br);
			GetWindowRect(gamehwnd, &rect);
			PatBlt(gamehdc, xPos, yPos, 8, 8, PATCOPY);

		}
	}
}

int main()
{

	SetConsoleTitleA("Aimscope by Jootzu/Ulysse"); // le titre de la fenÃªtre 

	HWND hwnd = GetConsoleWindow();// le handle de la console
	MoveWindow(hwnd, 0, 0, 500, 220, TRUE); // redimmensionnement de la console

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12); // (bleu foncÃ©)
	cout << "=========================================================" << endl;
	cout << "//                       Aimscope                      //" << endl;
	cout << "=========================================================\n" << endl;

	cout << "\n";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 16);
	cout << "Press [W] Key to display the crosshair !\n\n" << endl;


	crosshair();

	return 0;

}

