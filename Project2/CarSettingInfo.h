#pragma once
#include "Setting.h"
#include "Display.h"
#include "Sound.h"
#include "General.h"

class CarSettingInfo : public Setting, public Display, public Sound, public General
{
//private:
//	Display* disp;
//	Sound* sound;
//	General* gen;
public:
	CarSettingInfo();
	~CarSettingInfo();
	//Display* getDisplay();
	//Sound* getSound();
	//General* getGeneral();
	CarSettingInfo(CarSettingInfo& sample);
};

