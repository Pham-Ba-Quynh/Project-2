#pragma once
#include "Setting.h"
regex checkEmail("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
regex checkKey("[0-9]{8}");
extern bool checkInteger(string str);
Setting::Setting()
{
	car_name="";
	personal_key = ""; 	// Chuoi 8 ky tu so
	email = "";			// email format abc@xyz.com
	odo = 0;
	service_remind = 0;
}

Setting::~Setting(){}

string Setting::getCarName(){
	return car_name;
}

string Setting::getPersonalKey(){
	return personal_key;
}

int Setting::getODO (){
	return odo;
}

int Setting::getServiceRemind(){
	return service_remind;
}

string Setting::getEmail() {
	return email;
}

void Setting::nhapThongTinSetting(){

	do
	{
		cout << "Owner name: ";
		getline(cin, car_name);
		if (checkInteger(car_name)) {
			system("cls");
			cout << "Nhap Sai dinh dang ten. Vui long nhap lai!" << endl;
		}
	} while (checkInteger(car_name));

	do
	{
		cout << "Email: ";
		getline(cin, email);
		if (!regex_match(email, checkEmail)) {
			system("cls");
			cout << "Nhap Sai dinh dang email. Vui long nhap lai!" << endl;
		}
	} while (!regex_match(email, checkEmail));
	do
	{
		cout << "Key number: ";
		getline(cin, personal_key);
		if (!regex_match(personal_key, checkKey) || personal_key.size() > 8) {
			system("cls");
			cout << "Nhap Sai dinh dang Key Person. Vui long nhap lai!" << endl;
		}
	} while (!regex_match(personal_key, checkKey) || personal_key.size() > 8);
		string s = "";
	do
	{
		cout << "ODO number: ";
		getline(cin, s);
		if (!checkInteger(s)) {
			cout << "Vui long nhap lai so ODO" << endl;
		}
	} while (!checkInteger(s));
		odo = stoi(s);
		string str = "";
	do
	{
		cout << "Remind Service: ";
		getline(cin, str);
		if (!checkInteger(str)) {
			cout << "Vui long nhap lai so Remind Service" << endl;
		}
	} while (!checkInteger(str));
	service_remind = stoi(str);
}

void Setting::xuatThongTinSetting(){
	cout << "Owner name: " << car_name << endl;
	cout << "Email: " << email << endl;
	cout << "Key number: " << personal_key << endl;
	cout << "ODO number: " << odo << endl;
	cout << "Remind service (km): " << service_remind << endl;
}

