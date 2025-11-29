#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"
#include"clsUpdateCurrancy.h"
#include"clsFindCurrancy.h"
#include"clsCurrencyCalScreen.h"
#include"clsListCurrancyScreen.h"
#include<iostream>
#include<iomanip>
using namespace std;
class clsCurrencyMenue : protected clsScreen {
private:
	enum enCurrencyOptions{eListCurrency=1,eFindCurrency,eUpdateRate,eCurrencyCal,eMainMenue};
	static short _ReadCurrencyMenueOption() {
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}
	static void _ListCurrency() {
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
		
	}
	static void _FindCurrency() {
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _UpdateRate() {
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}
	static void _CurrencyCal() {
		clsCurrencyCalculatorScreen::ShowCurrencyCalculatorScreen();
	}
	static  void _GoCurrencyMenue() {
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";
		system("pause>0");
		ShowCurrencyExchangeScreen();
	}
	static void _performCurrencyMenue(enCurrencyOptions ch) {
		switch (ch) {
		case enCurrencyOptions::eListCurrency:
		{
			system("cls");
			_ListCurrency();
			_GoCurrencyMenue();
			break;
		}
		case enCurrencyOptions::eFindCurrency:
		{
			system("cls");
			_FindCurrency();
			_GoCurrencyMenue();
			break;
		}
		case enCurrencyOptions::eUpdateRate:
		{
			system("cls");
			_UpdateRate();
			_GoCurrencyMenue();
			break;
		}
		case enCurrencyOptions::eCurrencyCal:
		{
			system("cls");
			_CurrencyCal();
			_GoCurrencyMenue();
			break;
		}
		case enCurrencyOptions::eMainMenue:
		{
			system("cls");
			//Go back to main menue
			break;
		}
		}
	}
public:
	static void ShowCurrencyExchangeScreen()
	{
		system("cls");
		_DrawScreenHeader("\tCurrency Exchange Screen");
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exchange Menue\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Currency Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Go Back to Main Menue.\n";
		cout << setw(37) << left << "" << "===========================================\n";
		short Choice = _ReadCurrencyMenueOption();
		_performCurrencyMenue((enCurrencyOptions)Choice);
	}
};
