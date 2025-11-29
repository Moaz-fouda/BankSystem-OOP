#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include<iostream>
#include<iomanip>
#include"clsCurrency.h"
using namespace std;
class clsUpdateCurrencyScreen : protected clsScreen
{
private:
    static void _PrintCurrency(clsCurrency Currency)
    {
        cout << "\nCurrency Card:\n";
        cout << "_____________________________\n";
        cout << "\nCountry    : " << Currency.Country();
        cout << "\nCode       : " << Currency.CurrencyCode();
        cout << "\nName       : " << Currency.CurrencyName();
        cout << "\nRate(1$) = : " << Currency.Rate();

        cout << "\n_____________________________\n";

    }
public:
    static void ShowUpdateCurrencyScreen()
    {
		system("cls");
        _DrawScreenHeader("\t  Update Currency Rate Screen");
        string CurrencyCode;
        cout << "\nPlease Enter CurrencyCode: ";
        CurrencyCode = clsInputValidate::ReadString();
        while (!clsCurrency::IsCurrencyExist(CurrencyCode))
        {
            cout << "\nCurrency Code is not found, Enter again: ";
			CurrencyCode = clsInputValidate::ReadString();

        }
		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
        _PrintCurrency(Currency);
        cout << "Are you sure you want Update this rate(Y/N)? ";
		char Answer;
        cin >> Answer;
        if (toupper(Answer) == 'Y')
        {
            cout << "\nEnter New Rate for " << Currency.CurrencyName() << " : ";
            float NewRate = clsInputValidate::ReadFloatNumber();
            Currency.UpdateRate(NewRate);
            cout << "\nCurrency Rate Updated Successfully :-)\n";
            _PrintCurrency(Currency);
        }
        else
        {
            cout << "\nOperation Cancelled :-)\n";
		}
	}
};
