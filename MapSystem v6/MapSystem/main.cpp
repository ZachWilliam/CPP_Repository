#pragma comment(lib, "winmm.lib")
#include <iostream>
#define _WIN32_WINNT 0x0500//This needs to be here before #include <Windows.h> for GetConsoleWindow to work
#include <Windows.h>
#include <vector>
#include <conio.h>
#include "Format.h"
#include "MapMain.h"

using namespace std;






void Setup() {
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 845, 790, TRUE);
}

int main() {
	Setup();
	MapMain map;
	map.main();

	return 0;
}