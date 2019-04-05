#include "SoundManager.h"



void SoundManager::PlayMusic(string p_name) {
	if (p_name == "Sound/overworld_music.wav") PlaySound("Sound/overworld_music.wav", NULL, SND_LOOP | SND_ASYNC);
	else if (p_name == "Sound/cave_music.wav") PlaySound("Sound/cave_music.wav", NULL, SND_LOOP | SND_ASYNC);
	else if (p_name == "Sound/town_music.wav") PlaySound("Sound/town_music.wav", NULL, SND_LOOP | SND_ASYNC);
	else if (p_name == "Sound/prelude_theme.wav") PlaySound("Sound/prelude_theme.wav", NULL, SND_LOOP | SND_ASYNC);
	else if (p_name == "Sound/battle_theme.wav") PlaySound("Sound/battle_theme.wav", NULL, SND_LOOP | SND_ASYNC);
	else if (p_name == "Sound/boss_theme.wav") PlaySound("Sound/boss_theme.wav", NULL, SND_LOOP | SND_ASYNC);
	else if (p_name == "Sound/final_area_theme.wav") PlaySound("Sound/final_area_theme.wav", NULL, SND_LOOP | SND_ASYNC);
	else if (p_name == "Sound/last_battle.wav") PlaySound("Sound/last_battle.wav", NULL, SND_LOOP | SND_ASYNC);
}