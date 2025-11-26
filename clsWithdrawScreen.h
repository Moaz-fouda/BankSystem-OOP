#pragma once
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsBankClient.h"
#include"clsMainScreen.h"
#include<iostream>
#include<iomanip>
using namespace std;
class clsWithdraw :protected clsScreen {
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
	static void ShowWithdrawScree() {
		system("cls");
		_DrawScreenHeader("\t\t Withdraw Screen ");
		string Acc = "";
		cout << "Please enter account number :";
		Acc = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(Acc)) {
			cout << "this account is  not exist , NEter other account :";
			Acc = clsInputValidate::ReadString();
		}
		clsBankClient Client = clsBankClient::Find(Acc);
		_PrintClient(Client);
		cout << "Enter Amount you want Subtraction :";
		double x = clsInputValidate::ReadDblNumber();
		char ans = 'n';
		cout << "Do you want to Subtraction this mount " << x << " ? (Y/N) :" << endl;
		cin >> ans;
		if (toupper(ans) == 'Y') {
			Client.Withdraw(x);
			cout << "\nAmount withdraw Successfully.\n";
			cout << "\nNew Balance Is: " << Client.AccountBalance;
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}
	}
};