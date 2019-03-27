#pragma once
class Chest
{
public:
	Chest(int p_row, int p_col, bool p_opened, int p_id1, int p_id2, int p_id3, int p_itemID);

	int row, col;
	bool opened = false;
	int id1, id2, id3;
	int itemID;
};

