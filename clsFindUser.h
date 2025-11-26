#pragma once
#include <iostream>
#include"clsInputValidate.h"
#include "clsScreen.h"
#include <vector>
#include "clsUser.h"
#include <iomanip>
using namespace std;
class clsFindUser :protected clsScreen {
private:
	static void _PrintUser(clsUser User)
	{
		cout << "\nUser Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << User.FirstName;
		cout << "\nLastName    : " << User.LastName;
		cout << "\nFull Name   : " << User.GetFullName();
		cout << "\nEmail       : " << User.Email;
		cout << "\nPhone       : " << User.Phone;
		cout << "\nUser Name   : " << User.UserName;
		cout << "\nPassword    : " << User.Password;
		cout << "\nPermissions : " << User.Permissions;
		cout << "\n___________________\n";

	}
public:
	static void FindUserScreen() {
		system("cls");
		_DrawScreenHeader("Find User Screen ");
		cout << "Enter User Name :";
		string User = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(User)) {
			cout << "\nThis user it not exist , Please Enter onther User :";
			User = clsInputValidate::ReadString();

		}
		clsUser U = clsUser::Find(User);
		if (!U.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}
		else
		{
			cout << "\nUser Was not Found :-(\n";
		}
		_PrintUser(U);
	}
};