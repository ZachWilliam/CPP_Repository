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
	MoveWindow(console, r.left, r.top, 930, 790, TRUE);
}

int main() {
	Setup();
	string phrase = "And one day I went on a adventure. It wasn't a exciting adventure it was more me sitting in my room typing random stuff to test my OutPut speech function. It seems to be working so far so I moved on to stage two, EVEN MORE TEXT!. No one knows how much i'm going to have to type to test this but my god I will type until its done. hings are once again working fine but now I must test having multiple panes of messages so heres even more nonsense stuff to read.";
	vector<string> testVec;
	testVec.push_back("Hello this is me typing yet more random gibberish to test whether or not the overloaded versino of my output speech function works");
	testVec.push_back("Overloaded version just takes a vector of strings instead of one giant string, but then converts it to one giant string so it can continue");
	testVec.push_back("to use the same formula as if just a giant string was sent in. PS i dont care about typos");
	testVec.push_back("more words more words and even more bloody words blah blah blah blah make this 6 lines please");

	MapMain map;

	map.DrawGUI();

	//DrawGUI(81, 30, 28, 79);

	//Format FormatManager(79, 28, 31, 81, 30);
	//FormatManager.DrawGUI();
	//DrawRight(81, 30);


	OutputSpeech(phrase, "Merchant", 79, 31);
	OutputSpeech(testVec, "Towns Person", 79, 31);

	//GoToXY(43, 0);
	//cout << "hello";



	_getch();
	return 0;
}