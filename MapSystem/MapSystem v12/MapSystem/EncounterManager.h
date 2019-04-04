#pragma once
#include "Encounter.h"
#include "Database.h"

class EncounterManager
{
	EncounterManager(Database it)
	{
		Beasts = it;
		GenerateRegions();
	}
	void GenerateRegions()
	{
		CaveRands.push_back(Encounter(1, Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(1, Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(1, Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(2, Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(2, Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0)));
		CaveRands.push_back(Encounter(2, Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(3, Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(3, Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(3, Beasts.GetMonster(0), Beasts.GetMonster(0), Beasts.GetMonster(0), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0)));
		CaveRands.push_back(Encounter(4, Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(4, Beasts.GetMonster(0), Beasts.GetMonster(1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(4, Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(0), Beasts.GetMonster(0), Beasts.GetMonster(0)));
		CaveRands.push_back(Encounter(5, Beasts.GetMonster(-1), Beasts.GetMonster(2), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(5, Beasts.GetMonster(0), Beasts.GetMonster(1), Beasts.GetMonster(0), Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(1)));
		CaveRands.push_back(Encounter(5, Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(1), Beasts.GetMonster(1), Beasts.GetMonster(1)));
		CaveRands.push_back(Encounter(6, Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(6, Beasts.GetMonster(-1), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(14), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(6, Beasts.GetMonster(0), Beasts.GetMonster(13), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(7, Beasts.GetMonster(1), Beasts.GetMonster(13), Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(7, Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(14), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(7, Beasts.GetMonster(0), Beasts.GetMonster(13), Beasts.GetMonster(0), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
		CaveRands.push_back(Encounter(8, Beasts.GetMonster(13), Beasts.GetMonster(13), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(8, Beasts.GetMonster(1), Beasts.GetMonster(13), Beasts.GetMonster(1), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
		CaveRands.push_back(Encounter(8, Beasts.GetMonster(13), Beasts.GetMonster(2), Beasts.GetMonster(13), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
		CaveRands.push_back(Encounter(9, Beasts.GetMonster(13), Beasts.GetMonster(2), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(14), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(9, Beasts.GetMonster(1), Beasts.GetMonster(13), Beasts.GetMonster(1), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
		CaveRands.push_back(Encounter(9, Beasts.GetMonster(-1), Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(10, Beasts.GetMonster(-1), Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
		CaveRands.push_back(Encounter(10, Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(17), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(10, Beasts.GetMonster(15), Beasts.GetMonster(14), Beasts.GetMonster(15), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(13)));
		CaveRands.push_back(Encounter(11, Beasts.GetMonster(-1), Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(17)));
		CaveRands.push_back(Encounter(11, Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(17), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(11, Beasts.GetMonster(15), Beasts.GetMonster(15), Beasts.GetMonster(15), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
		CaveRands.push_back(Encounter(12, Beasts.GetMonster(16), Beasts.GetMonster(13), Beasts.GetMonster(16), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
		CaveRands.push_back(Encounter(12, Beasts.GetMonster(-1), Beasts.GetMonster(3), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(12, Beasts.GetMonster(0), Beasts.GetMonster(18), Beasts.GetMonster(0), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(15)));
		CaveRands.push_back(Encounter(13, Beasts.GetMonster(15), Beasts.GetMonster(18), Beasts.GetMonster(15), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(17)));
		CaveRands.push_back(Encounter(13, Beasts.GetMonster(16), Beasts.GetMonster(19), Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(17), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(13, Beasts.GetMonster(19), Beasts.GetMonster(3), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
		CaveRands.push_back(Encounter(14, Beasts.GetMonster(15), Beasts.GetMonster(18), Beasts.GetMonster(15), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(17)));
		CaveRands.push_back(Encounter(14, Beasts.GetMonster(16), Beasts.GetMonster(19), Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(17), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(14, Beasts.GetMonster(19), Beasts.GetMonster(3), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
		CaveRands.push_back(Encounter(15, Beasts.GetMonster(4), Beasts.GetMonster(3), Beasts.GetMonster(4), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(15, Beasts.GetMonster(18), Beasts.GetMonster(-1), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(14), Beasts.GetMonster(17)));
		CaveRands.push_back(Encounter(15, Beasts.GetMonster(19), Beasts.GetMonster(18), Beasts.GetMonster(19), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
		CaveRands.push_back(Encounter(16, Beasts.GetMonster(4), Beasts.GetMonster(3), Beasts.GetMonster(4), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(16, Beasts.GetMonster(18), Beasts.GetMonster(-1), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(14), Beasts.GetMonster(17)));
		CaveRands.push_back(Encounter(16, Beasts.GetMonster(19), Beasts.GetMonster(18), Beasts.GetMonster(19), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
		CaveRands.push_back(Encounter(17, Beasts.GetMonster(4), Beasts.GetMonster(3), Beasts.GetMonster(4), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(17, Beasts.GetMonster(18), Beasts.GetMonster(-1), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(14), Beasts.GetMonster(17)));
		CaveRands.push_back(Encounter(17, Beasts.GetMonster(19), Beasts.GetMonster(18), Beasts.GetMonster(19), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
		CaveRands.push_back(Encounter(18, Beasts.GetMonster(-1), Beasts.GetMonster(20), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(18, Beasts.GetMonster(19), Beasts.GetMonster(18), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(17)));
		CaveRands.push_back(Encounter(18, Beasts.GetMonster(4), Beasts.GetMonster(3), Beasts.GetMonster(4), Beasts.GetMonster(5), Beasts.GetMonster(-1), Beasts.GetMonster(5)));
		CaveRands.push_back(Encounter(19, Beasts.GetMonster(-1), Beasts.GetMonster(20), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(19, Beasts.GetMonster(19), Beasts.GetMonster(18), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(17)));
		CaveRands.push_back(Encounter(19, Beasts.GetMonster(4), Beasts.GetMonster(3), Beasts.GetMonster(4), Beasts.GetMonster(5), Beasts.GetMonster(-1), Beasts.GetMonster(5)));
		CaveRands.push_back(Encounter(20, Beasts.GetMonster(-1), Beasts.GetMonster(20), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(20, Beasts.GetMonster(19), Beasts.GetMonster(18), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(17)));
		CaveRands.push_back(Encounter(20, Beasts.GetMonster(4), Beasts.GetMonster(3), Beasts.GetMonster(4), Beasts.GetMonster(5), Beasts.GetMonster(-1), Beasts.GetMonster(5)));
		CaveRands.push_back(Encounter(20, Beasts.GetMonster(-1), Beasts.GetMonster(65), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		CaveRands.push_back(Encounter(20, Beasts.GetMonster(-1), Beasts.GetMonster(69), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));



	}
	vector<Encounter> CaveRands;
	vector<Encounter> MazeRand;
	Database Beasts;
};