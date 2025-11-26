#pragma once
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsUser.h"
#include"clsTransferLogScreen.h"
#include"clsTransferScreen.h"
#include"clsDepositeScreen.h"
#include"clsMainScreen.h"
#include"clsTotalBalanceScreen.h"
#include"clsWithdrawScreen.h"
#include<iostream>
#include<iomanip>
using namespace std;
class clsTransctionScreen :protected clsScreen {
private:
	enum enTrancationOption{Deposit=1,withdraw=2,TotalBalances=3,Transfer=4,TransferLog=5,MainMenue=6};
    static short _ReadTranscationMenueOption() {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadIntNumberBetween(1, 5, "Enter Number between 1 to 6? ");
        return Choice;
    }
    static void _Deposite() {
        clsDeposite::ShowDepsiteScreen();
    }
    static void _Withdraw() {
        clsWithdraw::ShowWithdrawScree();

    }
    static void _TotalBalanced() {
        clsTotalBalance::ShowTotalBalanceScreen();
    }
    static  void _GoTranscationMenue() {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

        system("pause>0");
        ShowTransctionMenue();
    }
    static void _Transfer() {
        clsTransfer::_ShowTransferScreen();

    }
    static void _TransferLog() {
		clsTransferLog::_ShowTransferLogScreen();
	}
    static void _performTranscation(enTrancationOption ch) {
        switch (ch) {
        case enTrancationOption::Deposit:
        {
            system("cls");
            _Deposite();
            _GoTranscationMenue();
            break;
        }
        case enTrancationOption::withdraw:
        {
            system("cls");
            _Withdraw();
            _GoTranscationMenue();
            break;

        }
        case enTrancationOption::TotalBalances:
        {
            system("cls");
            _TotalBalanced();
            _GoTranscationMenue();
            break;
        }
        case enTrancationOption::Transfer:
        {
            system("cls");
            _Transfer();
            _GoTranscationMenue();
            break;

        }
        case enTrancationOption::TransferLog:
        {
            system("cls");
            _TransferLog();
            _GoTranscationMenue();
            break;
		}
        case enTrancationOption::MainMenue:
        {
           

        }
        }
    }
public:
    static void ShowTransctionMenue() {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t\tTranscation Menue ");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransction Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposite.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] TotalBalances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
		cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] MainMenue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        _performTranscation((enTrancationOption)_ReadTranscationMenueOption());
    }
};

