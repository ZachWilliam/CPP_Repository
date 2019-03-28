#pragma once
#include "Monster.h"
#include "Dialogue.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <conio.h>


class Database
{
public:
	Database();
	void DisplayBeastiary();
	void DisplayText();
	vector<Monster>Beastiary;
	vector<Dialogue>Scenes;
	void LoadMonsters();//loads all data from CSV and puts information into Beastiary/Item/Diaglogue vector
	void LoadText();
	
};

