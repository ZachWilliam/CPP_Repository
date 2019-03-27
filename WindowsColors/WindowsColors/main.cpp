#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
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

void SetColorAndBackground(int backC = BLACK, int textC = WHITE) {
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


int main() {
	SetColorAndBackground(0);
	cout << "     ";
	SetColorAndBackground(1);
	cout << "     ";
	SetColorAndBackground(2);
	cout << "     ";
	SetColorAndBackground(3);
	cout << "     ";
	SetColorAndBackground(4);
	cout << "     ";
	SetColorAndBackground(5);
	cout << "     ";
	SetColorAndBackground(6);
	cout << "     ";
	SetColorAndBackground(7);
	cout << "     ";
	SetColorAndBackground(8);
	cout << "     ";
	SetColorAndBackground(9);
	cout << "     ";
	SetColorAndBackground(10);
	cout << "     ";
	SetColorAndBackground(11);
	cout << "     ";
	SetColorAndBackground(12);
	cout << "     ";
	SetColorAndBackground(13);
	cout << "     ";
	SetColorAndBackground(14);
	cout << "     ";
	SetColorAndBackground(15);
	cout << "     " << endl;

	SetColorAndBackground(1);
	cout << "     " << endl;
	SetColorAndBackground(2);
	cout << "     " << endl;
	SetColorAndBackground(3);
	cout << "     " << endl;
	SetColorAndBackground(4);
	cout << "     " << endl;
	SetColorAndBackground(5);
	cout << "     " << endl;
	SetColorAndBackground(6);
	cout << "     " << endl;
	SetColorAndBackground(7);
	cout << "     " << endl;
	SetColorAndBackground(8);
	cout << "     " << endl;
	SetColorAndBackground(9);
	cout << "     " << endl;
	SetColorAndBackground(10);
	cout << "     " << endl;
	SetColorAndBackground(11);
	cout << "     " << endl;
	SetColorAndBackground(12);
	cout << "     " << endl;
	SetColorAndBackground(13);
	cout << "     " << endl;
	SetColorAndBackground(14);
	cout << "     " << endl;
	SetColorAndBackground(15);
	cout << "     " << endl;

	_getch();

	return 0;
}