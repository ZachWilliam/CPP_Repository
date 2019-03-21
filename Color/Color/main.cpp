#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;

//General color Logic
//If you want a green background with red text
// 2  4
//convert it to binary
// 0010 0100
//add the binarys together
//find the value of both binaries together (the 8 digits instead of the 4 indiviual)
// 00100100 = 36
//Send in 36

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

//Logic for conversion, lets say we use 15
//is 14 % 2 = 1, nope 0000
//divide 14 by 2 = 7
//is 7 % 2 = 1, yup 1000
//divide 7 by 2 = 3
//is 3 % 2 = 1, yup 1100
//devide 3 by 2 = 1;
//is 1 % 2 = 1, yup 1110
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

int main() {

	cout << "hello " << endl;
	cout << "hello " << endl;
	SetColorAndBackground(BLUE, RED);
	cout << "hello " << endl;
	cout << "hello " << endl;
	cout << "hello " << endl;

	_getch();

	return 0;
}



