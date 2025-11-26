#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
using namespace std;
class clsAddNewClient :protected clsScreen {
private:
	static void _PrintClient(clsBankClient c) {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << c.FirstName;
		cout << "\nLastName    : " << c.LastName;
		cout << "\nFull Name   : " <<c. GetFullName();
		cout << "\nEmail       : " <<c. Email;
		cout << "\nPhone       : " <<c. Phone;
		cout << "\nAcc. Number : " <<c.GetAccountNumber();
		cout << "\nPassword    : " <<c.PinCode;
		cout << "\nBalance     : " <<c.AccountBalance;
		cout << "\n___________________\n";
	}
	static void _ReadClientInfo(clsBankClient& c) {
		cout << "Enter first name :";
		c.FirstName = clsInputValidate::ReadString();
		cout << "Enter Last name : ";
		c.LastName = clsInputValidate::ReadString();
		cout << "Enter email :";
		c.Email = clsInputValidate::ReadString();
		cout << "Enter you PHONE :";
		c.Phone = clsInputValidate::ReadString();
		cout << "Enter you Password :";
		c.PinCode = clsInputValidate::ReadString();
		cout << "Enter you Ballanced :";
		c.AccountBalance = clsInputValidate::ReadFloatNumber();

	}
public:
	static void AddNewClient() {
		if (!CheckAccessRights(clsUser::enPermissions::pAddNewClient)) {
			return;
		}
		_DrawScreenHeader("Add New Client Screen ");
		string Acc = "";
		cout<<"Please enter account number :";
		Acc = clsInputValidate::ReadString();
		while (clsBankClient::IsClientExist(Acc)) {
			cout << "this account is exist , NEter other account :";
			Acc = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::GetNewClient(Acc);
		_ReadClientInfo(Client);
		clsBankClient::enSaveResults Save;
		Save = Client.Save();
		switch (Save) {
		case clsBankClient::svSucceeded:
		{
			cout << "Account Add susess -)\n";
			_PrintClient(Client);
			break;

		}
		case clsBankClient::svFaildEmptyObject:
		{
			cout << "error acounat was not save because it is Empty  \n";
			break;
		}
		case clsBankClient::svFaildAccountNumberExists:
		{
			cout << "error acounat was not save because it is not Exist   \n";
			break;

		}
		}
	}
};
