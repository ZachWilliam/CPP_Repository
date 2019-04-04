#pragma once
#ifndef TRANSITIONS_H
#define TRANSITIONS_H


#include "Format.h"
#include "Map.h"

void PlayMapTransEffect(int p_sWidth, int p_sHeight, const Map &p_map, int rowMove, int rowCol, bool p_close);
void PlayBattleTransEffect(int p_sWidth, int p_sHeight);
void PlayBossBattleTransEffect(int p_sWidth, int p_sHeight, bool p_isFinalBoss);

#endif // !TRANSITIONS_H