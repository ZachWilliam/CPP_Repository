#pragma once
#include <string>
#include <Windows.h>
using namespace std;
class SoundManager
{
public:
	static SoundManager& Instance() {
		static SoundManager* instance_;
		return *instance_;
	}

	void PlayMusic(string p_name);
private:
	SoundManager() {};
};

