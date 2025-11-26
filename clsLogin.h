#pragma once
#include"clsScreen.h"
#include<iostream>
#include<iomanip>
#include"clsMainScreen.h"
#include"clsUser.h"
#include"clsGlobal.h"
using namespace std;
class clsLogin :protected clsScreen {
private :
	static bool _Login() {
		bool LoginFaild = false;
		string user, Pass;
		short counter = 3;
		do {
			if (LoginFaild) {
				counter--;
				cout << "Invalid Username/Passord!";
				cout << "You have " << counter<< " Trials to login.\n";
			}
			if (counter == 0) {
				cout << "you are locked after 3 \n";
				return false;
			}

			cout << "\nEnter Username :";
			cin >> user;
			cout << "\nEnter Password :";
			cin >> Pass;
			CurrentUser = clsUser::Find(user, Pass);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);
		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();
		return true;
	}
public:

	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t  Login Screen");
		return _Login();
		

	}
};
