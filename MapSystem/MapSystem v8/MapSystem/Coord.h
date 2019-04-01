#pragma once
#ifndef COORD_H
#define COORD_H
class Coord
{
public:
	Coord(int p_thisMapR = 0, int p_thisMapC = 0, int p_nextMapR = 0, int p_nextMapC = 0, int p_nextMapID = 0);
	int thisMapR, thisMapC;
	int nextMapR, nextMapC, nextMapID;
};

#endif
