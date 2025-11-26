#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsUser.h"
#include"clsInputValidate.h"
using namespace std;
class clsUpdateClient :protected clsScreen {
private:
	static void _PrintClient(clsBankClient c) {
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFirstName   : " << c.FirstName;
		cout << "\nLastName    : " << c.LastName;
		cout << "\nFull Name   : " << c.GetFullName();
		cout << "\nEmail       : " << c.Email;
		cout << "\nPhone       : " << c.Phone;
		cout << "\nAcc. Number : " << c.GetAccountNumber();
		cout << "\nPassword    : " << c.PinCode;
		cout << "\nBalance     : " << c.AccountBalance;
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
	static void ShowUpdateClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pUpdateClients)) {
			return;
		}
		_DrawScreenHeader("Update Client Screen ");
		string Acc = "";
		cout << "Please enter account number :";
		Acc = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(Acc)) {
			cout << "this account is not exist , NEter other account :";
			Acc = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(Acc);
		_PrintClient(Client);
	

		cout << "\nAre you sure you want to update this client y/n? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{

			cout << "\n\nUpdate Client Info:";
			cout << "\n____________________\n";
			_ReadClientInfo(Client);
			clsBankClient::enSaveResults SaveResult;

			SaveResult = Client.Save();

			switch (SaveResult)
			{
			case  clsBankClient::enSaveResults::svSucceeded:
			{
				cout << "\nAccount Updated Successfully :-)\n";

				_PrintClient(Client);
				break;
			}
			case clsBankClient::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError account was not saved because it's Empty";
				break;

			}

			}

		}

		}
	
};