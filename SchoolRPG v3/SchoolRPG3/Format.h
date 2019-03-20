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

string CenterPhrase(string p_phrase, const int p_maxSize);
void ClearBottom(int p_bottomStartRow, int p_screenWidth);
void GoToXY(int line, int column);
void OutputSpeech(vector <string> p_vSpeech, const string &p_npcName, const int p_screenWidth, const int p_drawRow);
void OutputSpeech(string p_speech, const string &p_npcName, const int p_screenWidth, const int p_bottomStartRow);

#endif // !FORMAT_H

