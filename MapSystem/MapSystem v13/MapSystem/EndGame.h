#pragma once
#include <vector>
#include <string>
#include "Format.h"
using namespace std;

class EndGame
{
public:
	EndGame();

	vector<string>gameOver{
		 "  _____   ___  ___  ___ _____  ",
		 " |  __ \ / _ \ |  \/  ||  ___| ",
		 " | |  \// /_\ \| .  . || |__   ",
		 " | | __ |  _  || |\/| ||  __|  ",
		 " | |_\ \| | | || |  | || |___  ",
		 "  \____/\_| |_/\_|  |_/\____/  ",
		 "                               ",
		 "   _____  _   _ ___________    ",
		 "  |  _  || | | |  ___| ___ \   ",
		 "  | | | || | | | |__ | |_/ /   ",
		 "  | | | || | | |  __||    /    ",
		 "  \ \_/ /\ \_/ / |___| |\ \    ",
		 "   \___/  \___/\____/\_| \_|   "
	};

	vector<string>theEnd{
		"  _____ _   _  _____  ",
		" |_   _| | | ||  ___| ",
		"   | | | |_| || |__   ",
		"   | | |  _  ||  __|  ",
		"   | | | | | || |___  ",
		"   \_/ \_| |_/\____/  ",
		"                      ",
		"   _____ _   _______  ",
		"  |  ___| \ | |  _  \ ",
		"  | |__ |  \| | | | | ",
		"  |  __|| . ` | | | | ",
		"  | |___| |\  | |/ /  ",
		"  \____/\_| \_/___/   "
	};
	string endingText = "This is where we wrap up the story";

	void AnimateBigText(vector<string>p_vtext);
	void GameOver();
	void PlayEnding();
	void DrawRight();
};


