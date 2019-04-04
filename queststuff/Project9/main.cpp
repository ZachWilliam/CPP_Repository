#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<windows.h>
#include"QuestManager.h"
#include"Quest.h"
#define _WIN32_WINNT 0x0500//This needs to be here before #include <Windows.h> for GetConsoleWindow to work

using namespace std;

void Setup()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 930, 790, TRUE);
}







int main()
{
	Setup();
	
}