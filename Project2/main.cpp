#include <iostream>
#include "General.h"
#include "Display.h"
#include "Sound.h"
#include "CommonInfo.h"
#include"CarSettingInfo.h"
#include <fstream>
#include <regex>

//extern regex checkEmail("^[\w\.]+@([\w-]+\.)+[\w-]{2,4}$");
//extern regex checkKey("[0-9]{8}");
regex checkInput("[1-3]");
regex checkInputSetting("[0-3]");
regex checkPrinSetting("[1-5]");

int carCnt = 0;
CarSettingInfo* listCarSetting = new CarSettingInfo[100];
vector<CommonInfo> timezoneList;
vector<CommonInfo> languageList;

void NhapThongTinCaiDat();
void XuatThongTinCaiDat();

void XuatThongTinCaiDat_Sound();
void XuatThongTinCaiDat_General();
void XuatThongTinCaiDat_Display();
void XuatThongTatCaTinCaiDat();

void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_General();
void NhapThongTinCaiDat_Display();

void downloadTimeZone();
void downloadLanguage();

void selectMenu();
int checkExitsCar(CarSettingInfo* car);
bool checkInteger(string str);
int menu();

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	downloadLanguage();
	downloadTimeZone();
	
	int selection = 0;
	do
	{
		selectMenu();
		selection = menu();

	} while (selection != 3);

	return 0;
}

int checkExitsCar(CarSettingInfo* Car) {
	for (int i = 0; i < carCnt; i++) {
		if (Car->getPersonalKey() == listCarSetting[i].getPersonalKey())
		{
			return i; // tra ve vi tri tim thay xe trong list
		}
	}
	return -1; // khong tim thay xe
}
bool checkInteger(string str)
{
	for (int i = 0; i < str.size(); i++) {
		if (isdigit(str.at(i)) == false) {
			return false;
		}
	}
	return true;
}
int menu(){
	int selection;
	string input = "";
	do
	{
		cout << "--- SELECT MENU ---" << endl;
		cout << "1. Input setting information" << endl;
		cout << "2. Print setting information" << endl;
		cout << "3. Exit" << endl;
		cout << "Your selection: ";

		getline(cin, input);
		if (!checkInteger(input)  || !regex_match(input, checkInput)) {
			cout << "---Vui long nhap lai---" << endl;
		}
	} while (!checkInteger(input) || !regex_match(input,checkInput));
	selection = stoi(input);
	return selection;
}
void selectMenu() {
	int selection;
	do
	{
		int select = menu();
		selection = select;
		system("cls");
		switch (selection)
		{
		case 1:
			NhapThongTinCaiDat();
			break;
		case 2:
			//for (int i = 0; i < carCnt; i++) {
			//	listCarSetting[i].getDisplay()->xuatThongTin();
			//	cout << endl;
			//	listCarSetting[i].getSound()->xuatThongTin();
			//	cout << endl;
			//	listCarSetting[i].getGeneral()->xuatThongTin();
			//	cout << endl;
			//}
			XuatThongTinCaiDat();
			break;
		case 3:
		default:
			cout << "---GOOD BYE---" << endl;
			break;
		}

	} while (selection != 3);
}

void NhapThongTinCaiDat(){
	int selection;
	string str;

	do
	{
		int select;
		do
		{
			cout << "--- SELECT MENU ---" << endl;
			cout << "1. Display setting" << endl;
			cout << "2. Sound setting" << endl;
			cout << "3. General setting" << endl;
			cout << "0. Exit" << endl;
			cout << "Your selection: ";
			getline(cin, str);
			if (!checkInteger(str) || !regex_match(str, checkInputSetting)) {
				cout << "---Vui long nhap lai---" << endl;
			}
		} while (!checkInteger(str) || !regex_match(str, checkInputSetting));
		select = stoi(str);

		system("cls");
		switch (select) {
			case 1: {
				cout << " --- Ban nhap thong tin Display --- " << endl;
				// Your code
				NhapThongTinCaiDat_Display();
				break;
			}
			case 2: {
				cout << " --- Ban nhap thong tin Sound --- " << endl;
				NhapThongTinCaiDat_Sound();
				break;
			}
			case 3: {
				cout << " --- Ban nhap thong tin General --- " << endl;
				// Your code
				NhapThongTinCaiDat_General();
				break;
			}
			case 0:
			default:
			{
				break;
			}
		}
		selection = select;
	} while (selection != 0);
}

void NhapThongTinCaiDat_Sound()
{
	char continues = 'n';
	do{
		cout << " NHAP THONG TIN SOUND, XE SO " << carCnt+1 << endl;
		CarSettingInfo newCar;
		newCar.nhapThongTinSetting();

		int index = checkExitsCar(&newCar);
		if (index != -1) {
			cout << "\t-> This car already exits, data weill be overriding " << endl;
		}
		else {
			cout << "\t-> this is car, data will be appended to your list" << endl;
		}

		newCar.nhapThongTinSound();


		if (index != -1) // Xe da ton tai
		{
			//code ghi de thong tin...(co the su dung deep copy)
			listCarSetting[index].set_call_level(newCar.get_call_level());
			listCarSetting[index].set_media_level(newCar.get_media_level());
			listCarSetting[index].set_navi_level(newCar.get_navi_level());
			listCarSetting[index].set_notification_level(newCar.get_notification_level());


		}
		else { // xe moi
			listCarSetting[carCnt] = newCar;
			carCnt++;
		}
		//listCarSetting[carCnt].getSound()->xuatThongTin();
		cout << "TIEP TUC XE SO " << carCnt +1 << " ? (y/n): ";
		cin >> continues;
		cout << endl;
		cin.ignore();
		system("cls");
	}while(continues == 'y');
}

void NhapThongTinCaiDat_General()
{
	char continues = 'n';
	do{
		cout << " NHAP THONG TIN GENERAL, XE SO " << carCnt +1 << endl;
		
		CarSettingInfo newCar;
		newCar.nhapThongTinSetting();

		int index = checkExitsCar(&newCar);
		if (index != -1) {
			cout << "\t-> This car already exits, data weill be overriding " << endl;
		}
		else {
			cout << "\t-> this is car, data will be appended to your list" << endl;
		}
		system("pause");
		newCar.nhapThongTinGeneral();
		if (index != -1) // Xe da ton tai
		{
			//code ghi de thong tin...(co the su dung deep copy)
			listCarSetting[index].set_timeZone(newCar.get_timeZone());
			listCarSetting[index].set_language(newCar.get_language());
			//listCarSetting[index].getGeneral()->xuatThongTin();
		}
		else { // xe moi
			listCarSetting[carCnt] = newCar;
			carCnt++;
		}

		cout << "TIEP TUC XE SO " << carCnt + 1 << " ? (y/n): ";
		cin >> continues;
		cout << endl;
		cin.ignore();
		system("cls");
	}while(continues == 'y');
}

void NhapThongTinCaiDat_Display()
{
	char continues = 'n';
	do{
		cout << " NHAP THONG TIN DISPLAY, XE SO " << carCnt +1 << endl;
		
		CarSettingInfo newCar;
		newCar.nhapThongTinSetting();


		int index = checkExitsCar(&newCar);
		if (index != -1) {
			cout << "\t-> This car already exits, data weill be overriding " << endl;
		}
		else {
			cout << "\t-> this is car, data will be appended to your list" << endl;
		}
		newCar.nhapThongTinDisplay();
		if (index != -1) // Xe da ton tai
		{
			//code ghi de thong tin...(co the su dung deep copy hoac shallow )
			listCarSetting[index].set_light_level(newCar.get_light_level());
			listCarSetting[index].set_screen_light_level(newCar.get_screen_light_level());
			listCarSetting[index].set_taplo_light_level(newCar.get_taplo_light_level());
			//listCarSetting[index] = newCar;
		}
		else { // xe moi
			//listCarSetting[carCnt].getDisplay()->set_light_level(newCar.getDisplay()->get_light_level());
			//listCarSetting[carCnt].getDisplay()->set_screen_light_level(newCar.getDisplay()->get_screen_light_level());
			//listCarSetting[carCnt].getDisplay()->set_taplo_light_level(newCar.getDisplay()->get_taplo_light_level());
			listCarSetting[carCnt] = newCar;
			//listCarSetting[carCnt].getDisplay()->xuatThongTin();
			carCnt++;
		}

		cout << "TIEP TUC XE SO " << carCnt +1 << " ? (y/n): ";
		cin >> continues;
		cin.ignore();
		cout << endl;
		system("cls");
	}while(continues == 'y');
	//NhapThongTinCaiDat();
}

void XuatThongTinCaiDat(){
	int selection;
	string str;
	do
	{
		int select;
		do
		{
			cout << "--- SELECT MENU ---" << endl;
			cout << "1. Print Display setting information" << endl;
			cout << "2. Print Sound setting information" << endl;
			cout << "3. Print General setting information" << endl;
			cout << "4. Print all setting inforation" << endl;
			cout << "5. Exit" << endl;
			cout << "Your selection: ";
			getline(cin, str);
			if (!checkInteger(str) || !regex_match(str, checkPrinSetting)) {
				cout << "---Vui long nhap lai---" << endl;
			}
		} while (!checkInteger(str) || !regex_match(str, checkPrinSetting));
		select = stoi(str);

		system("cls");
		switch (select) {
		case 1:
			XuatThongTinCaiDat_Display();
			break;
		case 2:
			XuatThongTinCaiDat_Sound();
			break;
		case 3:
			XuatThongTinCaiDat_General();
			break;
		case 4:
			XuatThongTatCaTinCaiDat();
			break;
		case 5:
		default:
			break;
		}
		selection = select;
	} while (selection != 5);

}

const vector<string> explode(const string& s, const char& c) 
{
	string buff{ "" };
	vector<string> v;

	for (auto n : s) 
	{
		if (n != c)
			buff += n;
		else if (n == c && buff != "") 
		{
			v.push_back(buff);
			buff = "";
		}
	}
	if (buff != "")
		v.push_back(buff);

	return v;
}

void downloadTimeZone(){
	ifstream f;
	f.open("timezones.txt");
	if (f.good()) {
		while (f.eof() == false)
		{
			string str = "";
			getline(f, str); // doc 1 dong va luu vao string str
			vector<string> data = explode(str, '/'); // ["(GMT-12:00)", "International Date Line West"]
			CommonInfo common;
			if (data.size() >= 2) {
				common.setNumber(data[0]);
				common.setName(data[1]);
			}
			timezoneList.push_back(common); //Add vao list time zone
		}
	}
	else {
		cout << "Khong the doc file" << endl;
	}
	f.close();
}

void downloadLanguage(){
	ifstream f;
	f.open("languages.txt");
	if (f.good()) {
		while (f.eof() == false)
		{
			string str = "";
			getline(f, str); // doc 1 dong va luu vao string str
			vector<string> data = explode(str, '/'); // ["(GMT-12:00)", "International Date Line West"]
			CommonInfo common;
			if (data.size() >= 2) {
				common.setNumber(data[0]);
				common.setName(data[1]);
			}
			languageList.push_back(common); //Add vao list language
		}
	}
	else {
		cout << "Khong the doc file" << endl;
	}
	f.close();	
}

void XuatThongTinCaiDat_Sound(){
	cout << setw(20) << "TEN CHU XE" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify"<< endl;
	for (int i = 0; i < carCnt; i++) {
		cout << setw(20) << listCarSetting[i].getCarName() << setw(25) << listCarSetting[i].getEmail() << setw(10) << listCarSetting[i].getPersonalKey()
			<< setw(10) << listCarSetting[i].getODO() << setw(10) << listCarSetting[i].getServiceRemind() 
			<< setw(10) << listCarSetting[i].get_media_level() << setw(10) << listCarSetting[i].get_call_level() 
			<< setw(10) << listCarSetting[i].get_navi_level() << setw(10) << listCarSetting[i].get_notification_level() << endl;
	}
}

void XuatThongTinCaiDat_General(){
	cout << setw(20) << "TEN CHU XE" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(30) << "Language" << setw(20) << "Timezone" << endl;
	for (int i = 0; i < carCnt; i++) {
		cout << setw(20) << listCarSetting[i].getCarName() << setw(25) << listCarSetting[i].getEmail() << setw(10) << listCarSetting[i].getPersonalKey()
			<< setw(10) << listCarSetting[i].getODO() << setw(10) << listCarSetting[i].getServiceRemind()
			<< setw(30) << listCarSetting[i].get_language() << setw(20) << listCarSetting[i].get_timeZone() << endl;
	}
}

void XuatThongTinCaiDat_Display(){
	cout << setw(20) << "TEN CHU XE" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES" << setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;
	for (int i = 0; i < carCnt; i++) {
		cout << setw(20) << listCarSetting[i].getCarName() << setw(25) << listCarSetting[i].getEmail() << setw(10) << listCarSetting[i].getPersonalKey()
			<< setw(10) << listCarSetting[i].getODO() << setw(10) << listCarSetting[i].getServiceRemind()
			<< setw(10) << listCarSetting[i].get_light_level() << setw(10) << listCarSetting[i].get_screen_light_level()
			<< setw(10) << listCarSetting[i].get_taplo_light_level() << endl;
	}
}

void XuatThongTatCaTinCaiDat(){
	cout << setw(20) << "TEN CHU XE" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO" << setw(10) << "SEVICES"
		<< setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen"
		<< setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify"
		<< setw(30) << "Language" << setw(20) << "Timezone" << endl;
	for (int i = 0; i < carCnt; i++) {
		cout << setw(20) << listCarSetting[i].getCarName() << setw(25) << listCarSetting[i].getEmail() << setw(10) << listCarSetting[i].getPersonalKey()
			<< setw(10) << listCarSetting[i].getODO() << setw(10) << listCarSetting[i].getServiceRemind()
				<< setw(10) << listCarSetting[i].get_light_level() << setw(10) << listCarSetting[i].get_screen_light_level()
				<< setw(10) << listCarSetting[i].get_taplo_light_level()
				<< setw(10) << listCarSetting[i].get_media_level() << setw(10) << listCarSetting[i].get_call_level()
				<< setw(10) << listCarSetting[i].get_navi_level() << setw(10) << listCarSetting[i].get_notification_level()
				<< setw(30) << listCarSetting[i].get_language() << setw(20) << listCarSetting[i].get_timeZone() << endl;
	}

}

