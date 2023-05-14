#include "Display.h"

Display::Display()
{
	light_level = 0;
	screen_light_level = 0;
	taplo_light_level = 0;
}

Display::~Display(){

}

void Display::nhapThongTinDisplay(){
	cout << "Light Level: ";
	cin >> light_level;
	cout << "Screen light level: ";
	cin >> screen_light_level;
	cout << "Taplo light level: ";
	cin >> taplo_light_level;
}

void Display::xuatThongTinDisplay(){
	cout << "Light Level: " << light_level << endl;
	cout << "Screen light level: " << screen_light_level << endl;
	cout << "Taplo light level: " << taplo_light_level << endl;
}

int Display::get_light_level(){
	return light_level;
}

int Display::get_screen_light_level(){
	return screen_light_level;
}

int Display::get_taplo_light_level() {
	return taplo_light_level;
}

void Display::set_light_level(int data){
	light_level = data;
}

void Display::set_screen_light_level(int data){
	screen_light_level = data;
}

void Display::set_taplo_light_level(int data){
	taplo_light_level = data;
}

