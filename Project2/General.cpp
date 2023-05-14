#include "General.h"
#include "CommonInfo.h"

extern vector<CommonInfo> timezoneList;
extern vector<CommonInfo> languageList;

General::General()
{
	timeZone = "";
	language = "";
}

General::~General(){}

void General::nhapThongTinGeneral(){
	cout << "--- SELECT TIMEZONE DATA ---" << endl;
	for (int i = 0; i < timezoneList.size(); i++) {
		cout << i+1 << ": " << timezoneList[i].getNumber() << " " << timezoneList[i].getName() << endl;
	}
	cout << "YOUR SELECTION: ";
	getline(cin, timeZone);
	system("cls");

	cout << "---SELECT LANGUAGE DATA--- " << endl;
	for (int i = 0; i < languageList.size(); i++) {
		cout << languageList[i].getNumber() << " " << languageList[i].getName() << endl;
	}
	cout << "YOUR SELECTION: ";
	getline(cin, language);
}


void General::xuatThongTinGeneral(){
	cout << "TimeZone: " << timeZone << endl;
	cout << "Language: " << language << endl;
}

string General::get_language(){
	return language;
}

string General::get_timeZone(){
	return timeZone;
}

void General::set_timeZone(string data){
	timeZone = data;
}

void General::set_language(string data){
	language = data;
}
