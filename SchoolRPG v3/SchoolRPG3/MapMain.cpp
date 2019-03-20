#include "MapMain.h"



MapMain::MapMain()
{

}

void MapMain::DrawGUI() {
	system("CLS");
	GoToXY(0, 0);
	//Draw screen border
	cout << string(SCREEN_WIDTH + BORDER, '#') << endl;
	for (size_t i = 0; i < SCREEN_HEIGHT; i++)
		cout << "#" << string(SCREEN_WIDTH, ' ') << "#" << endl;
	cout << string(SCREEN_WIDTH + BORDER, '#') << endl;

	//Draw right border
	GoToXY(0, RIGHT_START_COL); cout << string(SIDE_WIDTH, '#') << endl;
	for (size_t i = 0; i < SCREEN_HEIGHT; i++) {
		GoToXY(i + 1, RIGHT_START_COL);
		cout << "#" << string(SIDE_WIDTH - BORDER, ' ') << "#" << endl;
	}
	GoToXY(SCREEN_HEIGHT + 1, RIGHT_START_COL); cout << string(SIDE_WIDTH, '#') << endl;
}

void MapMain::DrawScreen() {

}

void MapMain::DrawRight() {
//	GoToXY(3, p_rightStartCol + 1); cout << CenterPhrase("Legend", p_sideWidth - 2);
//	GoToXY(4, p_rightStartCol + 1); cout << CenterPhrase("------------", p_sideWidth - 2);
//	GoToXY(5, p_rightStartCol + 1); cout << CenterPhrase("Something", p_sideWidth - 2);
//	GoToXY(6, p_rightStartCol + 1); cout << CenterPhrase("Another", p_sideWidth - 2);
//	GoToXY(7, p_rightStartCol + 1); cout << CenterPhrase("Thing", p_sideWidth - 2);
}