#pragma once
#include "Encounter.h"
#include "Database.h"

class EncounterManager
{
public:
	EncounterManager()
	{}
	void GenerateRegions(Database &Beasts, int which)
	{
		if (which == 1)
		{
			gotoxy(30, 20);
			cout << " _______________________________";
			gotoxy(30, 21);
			cout << "/                               \\";
			gotoxy(30, 22);
			cout << "[ Loading |                   | ]";
			gotoxy(30, 23);
			cout << "\\_______________________________/";
			gotoxy(41, 22);
			SetColorAndBackground(15, 0);
			CaveRands.push_back(Encounter(1, Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			cout << "    ";
			CaveRands.push_back(Encounter(1, Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			cout << "   ";
			CaveRands.push_back(Encounter(1, Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1)));
			cout << "    ";
			MazeRand.push_back(Encounter(1, Beasts.GetMonster(-1), Beasts.GetMonster(55), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			cout << "   ";
			MazeRand.push_back(Encounter(1, Beasts.GetMonster(55), Beasts.GetMonster(-1), Beasts.GetMonster(55), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			cout << "    ";
			MazeRand.push_back(Encounter(1, Beasts.GetMonster(-1), Beasts.GetMonster(21), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		}
		if (which == 2)
		{
			CaveRands.push_back(Encounter(2, Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(2, Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0)));
			CaveRands.push_back(Encounter(2, Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(2, Beasts.GetMonster(21), Beasts.GetMonster(-1), Beasts.GetMonster(21), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(2, Beasts.GetMonster(55), Beasts.GetMonster(-1), Beasts.GetMonster(55), Beasts.GetMonster(-1), Beasts.GetMonster(21), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(2, Beasts.GetMonster(-1), Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		}
		if (which == 3)
		{
			CaveRands.push_back(Encounter(3, Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(3, Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(3, Beasts.GetMonster(0), Beasts.GetMonster(0), Beasts.GetMonster(0), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0)));
			MazeRand.push_back(Encounter(3, Beasts.GetMonster(21), Beasts.GetMonster(-1), Beasts.GetMonster(21), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(3, Beasts.GetMonster(55), Beasts.GetMonster(-1), Beasts.GetMonster(55), Beasts.GetMonster(-1), Beasts.GetMonster(21), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(3, Beasts.GetMonster(-1), Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		}
		if (which == 4)
		{
			CaveRands.push_back(Encounter(4, Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(4, Beasts.GetMonster(0), Beasts.GetMonster(1), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(0), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(4, Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(0), Beasts.GetMonster(0), Beasts.GetMonster(0)));
			MazeRand.push_back(Encounter(4, Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(4, Beasts.GetMonster(-1), Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(21), Beasts.GetMonster(-1), Beasts.GetMonster(21)));
			MazeRand.push_back(Encounter(4, Beasts.GetMonster(-1), Beasts.GetMonster(55), Beasts.GetMonster(-1), Beasts.GetMonster(55), Beasts.GetMonster(-1), Beasts.GetMonster(55)));
		}
		if (which == 5)
		{
			CaveRands.push_back(Encounter(5, Beasts.GetMonster(-1), Beasts.GetMonster(2), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(5, Beasts.GetMonster(0), Beasts.GetMonster(1), Beasts.GetMonster(0), Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(1)));
			CaveRands.push_back(Encounter(5, Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(1), Beasts.GetMonster(1), Beasts.GetMonster(1), Beasts.GetMonster(1)));
			MazeRand.push_back(Encounter(5, Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(5, Beasts.GetMonster(6), Beasts.GetMonster(6), Beasts.GetMonster(6), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(5, Beasts.GetMonster(-1), Beasts.GetMonster(55), Beasts.GetMonster(-1), Beasts.GetMonster(55), Beasts.GetMonster(-1), Beasts.GetMonster(55)));
		}
		if (which == 6)
		{
			CaveRands.push_back(Encounter(6, Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(6, Beasts.GetMonster(-1), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(14), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(6, Beasts.GetMonster(0), Beasts.GetMonster(13), Beasts.GetMonster(0), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(6, Beasts.GetMonster(6), Beasts.GetMonster(7), Beasts.GetMonster(6), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(6, Beasts.GetMonster(-1), Beasts.GetMonster(28), Beasts.GetMonster(-1), Beasts.GetMonster(28), Beasts.GetMonster(-1), Beasts.GetMonster(28)));
			MazeRand.push_back(Encounter(6, Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(21), Beasts.GetMonster(-1)));
		}
		if (which == 7)
		{
			CaveRands.push_back(Encounter(7, Beasts.GetMonster(1), Beasts.GetMonster(13), Beasts.GetMonster(1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(7, Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(14), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(7, Beasts.GetMonster(0), Beasts.GetMonster(13), Beasts.GetMonster(0), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
			MazeRand.push_back(Encounter(7, Beasts.GetMonster(7), Beasts.GetMonster(-1), Beasts.GetMonster(7), Beasts.GetMonster(-1), Beasts.GetMonster(7), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(7, Beasts.GetMonster(-1), Beasts.GetMonster(30), Beasts.GetMonster(-1), Beasts.GetMonster(28), Beasts.GetMonster(-1), Beasts.GetMonster(28)));
			MazeRand.push_back(Encounter(7, Beasts.GetMonster(23), Beasts.GetMonster(29), Beasts.GetMonster(23), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		}
		if (which == 8)
		{
			CaveRands.push_back(Encounter(8, Beasts.GetMonster(13), Beasts.GetMonster(13), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(8, Beasts.GetMonster(1), Beasts.GetMonster(13), Beasts.GetMonster(1), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
			CaveRands.push_back(Encounter(8, Beasts.GetMonster(13), Beasts.GetMonster(2), Beasts.GetMonster(13), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
			MazeRand.push_back(Encounter(8, Beasts.GetMonster(-1), Beasts.GetMonster(8), Beasts.GetMonster(-1), Beasts.GetMonster(7), Beasts.GetMonster(-1), Beasts.GetMonster(7)));
			MazeRand.push_back(Encounter(8, Beasts.GetMonster(28), Beasts.GetMonster(31), Beasts.GetMonster(28), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(8, Beasts.GetMonster(-1), Beasts.GetMonster(23), Beasts.GetMonster(-1), Beasts.GetMonster(22), Beasts.GetMonster(29), Beasts.GetMonster(22)));
		}
		if (which == 9)
		{
			CaveRands.push_back(Encounter(9, Beasts.GetMonster(13), Beasts.GetMonster(2), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(14), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(9, Beasts.GetMonster(1), Beasts.GetMonster(13), Beasts.GetMonster(1), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
			CaveRands.push_back(Encounter(9, Beasts.GetMonster(-1), Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(9, Beasts.GetMonster(8), Beasts.GetMonster(-1), Beasts.GetMonster(8), Beasts.GetMonster(-1), Beasts.GetMonster(9), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(9, Beasts.GetMonster(-1), Beasts.GetMonster(56), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(9, Beasts.GetMonster(22), Beasts.GetMonster(15), Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(22), Beasts.GetMonster(-1)));
		}
		if (which == 10)
		{
			CaveRands.push_back(Encounter(10, Beasts.GetMonster(-1), Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
			CaveRands.push_back(Encounter(10, Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(17), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(10, Beasts.GetMonster(15), Beasts.GetMonster(14), Beasts.GetMonster(15), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(13)));
			MazeRand.push_back(Encounter(10, Beasts.GetMonster(7), Beasts.GetMonster(9), Beasts.GetMonster(7), Beasts.GetMonster(8), Beasts.GetMonster(-1), Beasts.GetMonster(8)));
			MazeRand.push_back(Encounter(10, Beasts.GetMonster(24), Beasts.GetMonster(-1), Beasts.GetMonster(24), Beasts.GetMonster(-1), Beasts.GetMonster(24), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(10, Beasts.GetMonster(11), Beasts.GetMonster(-1), Beasts.GetMonster(32), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		}
		if (which == 11)
		{
			CaveRands.push_back(Encounter(11, Beasts.GetMonster(-1), Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(17)));
			CaveRands.push_back(Encounter(11, Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(17), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(11, Beasts.GetMonster(15), Beasts.GetMonster(15), Beasts.GetMonster(15), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
			MazeRand.push_back(Encounter(11, Beasts.GetMonster(57), Beasts.GetMonster(32), Beasts.GetMonster(57), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(11, Beasts.GetMonster(7), Beasts.GetMonster(-1), Beasts.GetMonster(7), Beasts.GetMonster(-1), Beasts.GetMonster(10), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(11, Beasts.GetMonster(29), Beasts.GetMonster(-1), Beasts.GetMonster(29), Beasts.GetMonster(-1), Beasts.GetMonster(38), Beasts.GetMonster(-1)));
		}
		if (which == 12)
		{
			CaveRands.push_back(Encounter(12, Beasts.GetMonster(16), Beasts.GetMonster(13), Beasts.GetMonster(16), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
			CaveRands.push_back(Encounter(12, Beasts.GetMonster(-1), Beasts.GetMonster(3), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(12, Beasts.GetMonster(0), Beasts.GetMonster(18), Beasts.GetMonster(0), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(15)));
			MazeRand.push_back(Encounter(12, Beasts.GetMonster(-1), Beasts.GetMonster(33), Beasts.GetMonster(-1), Beasts.GetMonster(31), Beasts.GetMonster(-1), Beasts.GetMonster(31)));
			MazeRand.push_back(Encounter(12, Beasts.GetMonster(24), Beasts.GetMonster(-1), Beasts.GetMonster(24), Beasts.GetMonster(15), Beasts.GetMonster(24), Beasts.GetMonster(15)));
			MazeRand.push_back(Encounter(12, Beasts.GetMonster(7), Beasts.GetMonster(11), Beasts.GetMonster(7), Beasts.GetMonster(7), Beasts.GetMonster(-1), Beasts.GetMonster(7)));
		}
		if (which == 13)
		{
			CaveRands.push_back(Encounter(13, Beasts.GetMonster(15), Beasts.GetMonster(18), Beasts.GetMonster(15), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(17)));
			CaveRands.push_back(Encounter(13, Beasts.GetMonster(16), Beasts.GetMonster(19), Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(17), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(13, Beasts.GetMonster(19), Beasts.GetMonster(3), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
			MazeRand.push_back(Encounter(13, Beasts.GetMonster(-1), Beasts.GetMonster(58), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(13, Beasts.GetMonster(35), Beasts.GetMonster(-1), Beasts.GetMonster(36), Beasts.GetMonster(-1), Beasts.GetMonster(34), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(13, Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(44), Beasts.GetMonster(-1)));
		}
		if (which == 14)
		{
			CaveRands.push_back(Encounter(14, Beasts.GetMonster(15), Beasts.GetMonster(18), Beasts.GetMonster(15), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(17)));
			CaveRands.push_back(Encounter(14, Beasts.GetMonster(16), Beasts.GetMonster(19), Beasts.GetMonster(16), Beasts.GetMonster(-1), Beasts.GetMonster(17), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(14, Beasts.GetMonster(19), Beasts.GetMonster(3), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
			MazeRand.push_back(Encounter(14, Beasts.GetMonster(33), Beasts.GetMonster(-1), Beasts.GetMonster(33), Beasts.GetMonster(-1), Beasts.GetMonster(38), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(14, Beasts.GetMonster(35), Beasts.GetMonster(-1), Beasts.GetMonster(36), Beasts.GetMonster(-1), Beasts.GetMonster(34), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(14, Beasts.GetMonster(25), Beasts.GetMonster(-1), Beasts.GetMonster(25), Beasts.GetMonster(-1), Beasts.GetMonster(25), Beasts.GetMonster(-1)));
		}
		if (which == 15)
		{
			CaveRands.push_back(Encounter(15, Beasts.GetMonster(4), Beasts.GetMonster(3), Beasts.GetMonster(4), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(15, Beasts.GetMonster(18), Beasts.GetMonster(-1), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(14), Beasts.GetMonster(17)));
			CaveRands.push_back(Encounter(15, Beasts.GetMonster(19), Beasts.GetMonster(18), Beasts.GetMonster(19), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
			MazeRand.push_back(Encounter(15, Beasts.GetMonster(-1), Beasts.GetMonster(59), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(15, Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(13), Beasts.GetMonster(-1), Beasts.GetMonster(12), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(15, Beasts.GetMonster(22), Beasts.GetMonster(25), Beasts.GetMonster(22), Beasts.GetMonster(24), Beasts.GetMonster(-1), Beasts.GetMonster(24)));
		}
		if (which == 16)
		{
			CaveRands.push_back(Encounter(16, Beasts.GetMonster(4), Beasts.GetMonster(3), Beasts.GetMonster(4), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(16, Beasts.GetMonster(18), Beasts.GetMonster(-1), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(14), Beasts.GetMonster(17)));
			CaveRands.push_back(Encounter(16, Beasts.GetMonster(19), Beasts.GetMonster(18), Beasts.GetMonster(19), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
			MazeRand.push_back(Encounter(16, Beasts.GetMonster(22), Beasts.GetMonster(26), Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(16, Beasts.GetMonster(29), Beasts.GetMonster(38), Beasts.GetMonster(34), Beasts.GetMonster(3), Beasts.GetMonster(-1), Beasts.GetMonster(3)));
			MazeRand.push_back(Encounter(16, Beasts.GetMonster(7), Beasts.GetMonster(9), Beasts.GetMonster(7), Beasts.GetMonster(11), Beasts.GetMonster(-1), Beasts.GetMonster(12)));
		}
		if (which == 17)
		{
			CaveRands.push_back(Encounter(17, Beasts.GetMonster(4), Beasts.GetMonster(3), Beasts.GetMonster(4), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(17, Beasts.GetMonster(18), Beasts.GetMonster(-1), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(14), Beasts.GetMonster(17)));
			CaveRands.push_back(Encounter(17, Beasts.GetMonster(19), Beasts.GetMonster(18), Beasts.GetMonster(19), Beasts.GetMonster(14), Beasts.GetMonster(-1), Beasts.GetMonster(14)));
			MazeRand.push_back(Encounter(17, Beasts.GetMonster(22), Beasts.GetMonster(26), Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(17, Beasts.GetMonster(29), Beasts.GetMonster(38), Beasts.GetMonster(35), Beasts.GetMonster(-1), Beasts.GetMonster(54), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(17, Beasts.GetMonster(7), Beasts.GetMonster(9), Beasts.GetMonster(7), Beasts.GetMonster(11), Beasts.GetMonster(-1), Beasts.GetMonster(12)));
		}
		if (which == 18)
		{
			CaveRands.push_back(Encounter(18, Beasts.GetMonster(-1), Beasts.GetMonster(20), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(18, Beasts.GetMonster(19), Beasts.GetMonster(18), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(17)));
			CaveRands.push_back(Encounter(18, Beasts.GetMonster(4), Beasts.GetMonster(3), Beasts.GetMonster(4), Beasts.GetMonster(5), Beasts.GetMonster(-1), Beasts.GetMonster(5)));
			MazeRand.push_back(Encounter(18, Beasts.GetMonster(-1), Beasts.GetMonster(27), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(18, Beasts.GetMonster(29), Beasts.GetMonster(38), Beasts.GetMonster(36), Beasts.GetMonster(-1), Beasts.GetMonster(42), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(18, Beasts.GetMonster(7), Beasts.GetMonster(9), Beasts.GetMonster(7), Beasts.GetMonster(-1), Beasts.GetMonster(11), Beasts.GetMonster(12)));
		}
		if (which == 19)
		{
			CaveRands.push_back(Encounter(19, Beasts.GetMonster(-1), Beasts.GetMonster(20), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(19, Beasts.GetMonster(19), Beasts.GetMonster(18), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(17)));
			CaveRands.push_back(Encounter(19, Beasts.GetMonster(4), Beasts.GetMonster(3), Beasts.GetMonster(4), Beasts.GetMonster(5), Beasts.GetMonster(-1), Beasts.GetMonster(5)));
			MazeRand.push_back(Encounter(19, Beasts.GetMonster(25), Beasts.GetMonster(27), Beasts.GetMonster(25), Beasts.GetMonster(22), Beasts.GetMonster(-1), Beasts.GetMonster(22)));
			MazeRand.push_back(Encounter(19, Beasts.GetMonster(29), Beasts.GetMonster(38), Beasts.GetMonster(29), Beasts.GetMonster(36), Beasts.GetMonster(35), Beasts.GetMonster(34)));
			MazeRand.push_back(Encounter(19, Beasts.GetMonster(56), Beasts.GetMonster(58), Beasts.GetMonster(56), Beasts.GetMonster(33), Beasts.GetMonster(-1), Beasts.GetMonster(33)));
		}
		if (which == 20)
		{
			CaveRands.push_back(Encounter(20, Beasts.GetMonster(-1), Beasts.GetMonster(20), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(20, Beasts.GetMonster(19), Beasts.GetMonster(18), Beasts.GetMonster(19), Beasts.GetMonster(17), Beasts.GetMonster(-1), Beasts.GetMonster(17)));
			CaveRands.push_back(Encounter(20, Beasts.GetMonster(4), Beasts.GetMonster(3), Beasts.GetMonster(4), Beasts.GetMonster(5), Beasts.GetMonster(-1), Beasts.GetMonster(5)));
			CaveRands.push_back(Encounter(20, Beasts.GetMonster(-1), Beasts.GetMonster(65), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			CaveRands.push_back(Encounter(20, Beasts.GetMonster(-1), Beasts.GetMonster(69), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(20, Beasts.GetMonster(11), Beasts.GetMonster(66), Beasts.GetMonster(11), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(20, Beasts.GetMonster(-1), Beasts.GetMonster(72), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(20, Beasts.GetMonster(-1), Beasts.GetMonster(68), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
			MazeRand.push_back(Encounter(20, Beasts.GetMonster(-1), Beasts.GetMonster(37), Beasts.GetMonster(-1), Beasts.GetMonster(37), Beasts.GetMonster(-1), Beasts.GetMonster(37)));
			MazeRand.push_back(Encounter(20, Beasts.GetMonster(-1), Beasts.GetMonster(67), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1), Beasts.GetMonster(-1)));
		}


	}
	Encounter GenerateEncounter(int lvl, int r)
	{
		if (r == 7)
		{
			int temp = rand() % 3 + ((lvl - 1) * 3);
			if (lvl == 20)
			{
				temp = rand() % 6 + ((lvl - 1) * 3);
			}
			return MazeRand[temp];
		}
		else
		{
			int temp = rand() % 3 + ((lvl - 1) * 3);
			if (lvl == 20)
			{
				temp = rand() % 6 + ((lvl - 1) * 3);
			}
			return CaveRands[temp];
		}


	}
	vector<Encounter> CaveRands;
	vector<Encounter> MazeRand;
	//Database Beasts;
	
};