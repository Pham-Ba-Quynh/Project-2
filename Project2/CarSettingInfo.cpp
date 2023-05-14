#include "CarSettingInfo.h"

CarSettingInfo::CarSettingInfo()
{
	//disp = new Display;
	//sound = new Sound;
	//gen = new General;
}

CarSettingInfo::~CarSettingInfo()
{
	//if (disp != nullptr) {
	//	delete disp;
	//	disp = nullptr;
	//}

	//if (sound != nullptr) {
	//	delete sound;
	//	sound = nullptr;
	//}

	//if (gen != nullptr) {
	//	delete gen;
	//	gen = nullptr;
	//}
}

CarSettingInfo::CarSettingInfo(CarSettingInfo& sample) {
	//disp = new Display;
	//sound = new Sound;
	//gen = new General;
	this->set_notification_level(sample.get_notification_level());
	this->set_media_level(sample.get_media_level());
	this->set_navi_level(sample.get_navi_level());
	this->set_call_level(sample.get_call_level());
	this->set_language(sample.get_language());
	this->set_timeZone(sample.get_timeZone());
	this->set_light_level(sample.get_light_level());
	this->set_screen_light_level(sample.get_screen_light_level());
	this->set_taplo_light_level(sample.get_taplo_light_level());
}

/*Display* CarSettingInfo::getDisplay()
{
	return disp;
}

Sound* CarSettingInfo::getSound()
{
	return sound;
}

General* CarSettingInfo::getGeneral()
{
	return gen;
}*/

