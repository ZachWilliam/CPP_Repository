#pragma once
#ifndef FORMAT_H
#define FORMAT_H
#include <iostream>
#include <string>
#include <vector>
#define _WIN32_WINNT 0x0500//This needs to be here before #include <Windows.h> for GetConsoleWindow to work
#include <Windows.h>
#include <conio.h>
using namespace std;

#define BLACK 0
#define BLUE 1
#define GREEN 2
#define CYAN 3
#define RED 4
#define MAGENTA 5
#define BROWN 6
#define LIGHTGRAY 7
#define DARKGRAY 8
#define LIGHTBLUE 9
#define LIGHTGREEN 10
#define LIGHTCYAN 11
#define LIGHTRED 12
#define LIGHTMAGENTA 13
#define YELLOW 14
#define WHITE 15

string CenterPhrase(string p_phrase, const int p_maxSize);
void ClearBottom(int p_bottomStartRow, int p_screenWidth);
void GoToXY(int line, int column);
void OutputSpeech(vector <string> p_vSpeech, const string &p_npcName, const int p_screenWidth, const int p_drawRow);
void OutputSpeech(string p_speech, const string &p_npcName, const int p_screenWidth, const int p_bottomStartRow);
void SetColorAndBackground(int backC = BLACK, int textC = WHITE);
int GetColorValue(char displayChar);

#endif // !FORMAT_H

