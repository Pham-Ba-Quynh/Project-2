#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <iomanip>
#include <string>
#include<regex>
using namespace std;

class Setting {
public:
	Setting();
	virtual ~Setting();
	void nhapThongTinSetting();
	void xuatThongTinSetting();


	string getCarName();
	string getEmail();
	string getPersonalKey();
	int getODO ();
	int getServiceRemind();
	
protected:

	string car_name;
	string personal_key; 	// Chuoi 8 ky tu so
	string email;			// email format abc@xyz.com
	int odo;
	int service_remind;
};
#endif /* SETTING_H_ */

