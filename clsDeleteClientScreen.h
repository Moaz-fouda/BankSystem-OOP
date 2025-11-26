#pragma once
#include<iostream>
#include"clsBankClient.h"
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsUser.h"
using namespace std;
class clsDeleteClient :protected clsScreen {
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
	static void ShowDeleteClientScreen() {
		if (!CheckAccessRights(clsUser::enPermissions::pDeleteClient)) {
			return;
		}
		_DrawScreenHeader("Delete Client Screen ");
		string Acc="";
		cout << "Please enter account number :";
		Acc = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(Acc)) {
			cout << "this account is  not exist , NEter other account :";
			Acc = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(Acc);
		_PrintClient(Client);
		char ans = 'n';
		cout << "Do you want delete this account ? (Y/y) :";
		cin >> ans;
		if (toupper(ans) == 'Y') {
			if (Client.Delete()) {
				cout << "Client Deleted susussfuly -) ";
				_PrintClient(Client);
			}
			else
			{
				cout << "Error ,Client was not Exist  -(";
			}

		}

 }
};
