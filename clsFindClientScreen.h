#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
using namespace std;
class clsFindClient :protected clsScreen {
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
public:
	static void ShowFindClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pFindClient)) {
			return;
		}
		_DrawScreenHeader("\tFind Client Screen");

		string AccountNumber;
		cout << "\nPlease Enter Account Number: ";
		AccountNumber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		if (!Client1.IsEmpty()) {
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\n Client Not Found :-(\n";
		}
		_PrintClient(Client1);
	}
};