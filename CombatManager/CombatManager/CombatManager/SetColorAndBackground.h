#include <iostream>
#include <conio.h>
#include <Windows.h>
#pragma once

using namespace std;


void SetColorAndBackground(int backC, int textC) {
	//Make sure color choice isnt above 15
	if (backC > 15 || textC > 15 || backC < 0 || textC < 0) {
		cout << "Invalid choice(s)" << endl;
		return;
	}

	//Convert backC to binary and back (as a byte) so 15 = 11110000, not 00001111
	int remainder = 0, newBackC = 0, multiplier = 1;
	while (backC > 0)
	{
		remainder = backC % 2;
		if (remainder % 2 != 0) newBackC += 16 * multiplier;
		multiplier *= 2;
		backC /= 2;
	}

	//Change colors
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), newBackC + textC);
}
