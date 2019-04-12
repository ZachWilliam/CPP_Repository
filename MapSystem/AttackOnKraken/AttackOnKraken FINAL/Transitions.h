#pragma once
#ifndef TRANSITIONS_H
#define TRANSITIONS_H


#include "Format.h"
#include "Map.h"

void PlayMapTransEffect(const Map &p_map, int rowMove, int rowCol, bool p_close);
void PlayBattleTransEffect();
void PlayBossBattleTransEffect(bool p_isFinalBoss);

#endif // !TRANSITIONS_H