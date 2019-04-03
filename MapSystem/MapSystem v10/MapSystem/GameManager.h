#pragma once
class GameManager
{
public:
	static GameManager& instance() {
		static GameManager instance;
		return instance;
	}
	const int BORDER = 2;
	const int SCREEN_WIDTH = 69;
	const int SCREEN_HEIGHT = 27;
	const int DIST_FROM_MID_C = SCREEN_WIDTH / 2 + SCREEN_WIDTH % 2;
	const int DIST_FROM_MID_R = SCREEN_HEIGHT / 2 + SCREEN_HEIGHT % 2;
	const int BOT_START_ROW = SCREEN_HEIGHT + BORDER;
	const int RIGHT_START_COL = SCREEN_WIDTH + BORDER;
	const int SIDE_WIDTH = 30;
private:
	GameManager() {}
};

