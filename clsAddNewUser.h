#pragma once
#include <iostream>
#include "clsScreen.h"
#include"clsInputValidate.h"
#include <vector>
#include "clsUser.h"
#include <iomanip>
using namespace std;
class clsAddUser :protected clsScreen {
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
	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permission: ";
		User.Permissions = _ReadPermissionsToSet();
	}

	static int _ReadPermissionsToSet()
	{

		int Permissions = 0;
		char Answer = 'n';


		cout << "\nDo you want to give full access? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n ";

		cout << "\nShow Client List? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{


			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTranactions;
		}

		cout << "\nManage Users? y/n? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}
		cout << "\nLoginRegister? (y/n)? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'y')
			Permissions += clsUser::enPermissions::pLoginRegister;

		return Permissions;

	}
public:
	static void _AddNewUserScreen() {
		system("cls");
		_DrawScreenHeader("\tAdd New User Screen");
		cout << "Enter user name :";
		string user = clsInputValidate::ReadString();
		while (clsUser::IsUserExist(user)) {
			cout << "This user it exist , Enter anther User :";
			user = clsInputValidate::ReadString();
		}
		clsUser User = clsUser::GetAddNewUserObject(user);
		_ReadUserInfo(User);
		clsUser::enSaveResults Save;
		Save = User.Save();
		switch (Save) {
		case clsUser::svFaildEmptyObject:
		{
			cout << "\nError User was not saved because it's Empty";
			break;
		}
		case clsUser::svSucceeded: {
			cout << "Save succussfuly :-) \n\n";
		_PrintUser(User);
			break;
		}
		case clsUser::svFaildUserExists: {
			cout << "\nError User was not saved because UserName is used!\n";
			break;
		}
		}

	}
};