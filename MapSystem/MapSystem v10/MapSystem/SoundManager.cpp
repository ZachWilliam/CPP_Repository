#include "SoundManager.h"



void SoundManager::PlayMusic(string p_name) {
		if (p_name == "Sound/overworld_music.wav") PlaySound("Sound/overworld_music.wav", NULL, SND_LOOP | SND_ASYNC);
		else if (p_name == "Sound/cave_music.wav") PlaySound("Sound/cave_music.wav", NULL, SND_LOOP | SND_ASYNC);
		else if (p_name == "Sound/town_music.wav") PlaySound("Sound/town_music.wav", NULL, SND_LOOP | SND_ASYNC);
}