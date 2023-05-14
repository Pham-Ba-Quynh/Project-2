#include "Sound.h"

Sound::Sound(){
	// Your code
	media_level = 0;
	call_level = 0;
	navi_level = 0;
	notification_level = 0;
}

Sound::~Sound(){}

void Sound::nhapThongTinSound(){
	cout << "Media level: ";
	cin >> media_level;
	cout << "Call level: ";
	cin >> call_level;
	cout << "Navi level: ";
	cin >> navi_level;
	cout << "Notification level: ";
	cin >> notification_level;
}

void Sound::xuatThongTinSound(){
	cout << "Media level: " << media_level << endl;
	cout << "Call level: " << call_level << endl;
	cout << "Navi level: " << navi_level << endl;
	cout << "Notification level: " << notification_level << endl;
}

int Sound::get_media_level(){
	// Your code
	return media_level;
}

int Sound::get_call_level(){
	// Your code
	return call_level;
}

int Sound::get_navi_level(){
	// Your code
	return navi_level;
}

int Sound::get_notification_level(){
	// Your code
	return notification_level;
}

void Sound::set_media_level(int data){
	// Your code
	this->media_level = data;
}

void Sound::set_call_level(int data){
	// Your code
	this->call_level = data;
}

void Sound::set_navi_level(int data){
	// Your code
	this->navi_level = data;
}

void Sound::set_notification_level(int data){
	// Your code
	this->notification_level = data;
}

