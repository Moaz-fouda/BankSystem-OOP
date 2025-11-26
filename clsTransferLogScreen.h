#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include<iomanip>
using namespace std;
class clsTransferLog : protected clsScreen {
private:
	static void _PrintTransferRecordLine(clsBankClient::stTransfer TransferRecord)
	{
		cout << setw(8) << left << "" << "| " << left << setw(20) << TransferRecord.DateTime;
		cout << "| " << left << setw(15) << TransferRecord.FromAccount;
		cout << "| " << left << setw(15) << TransferRecord.ToAccount;
		cout << "| " << left << setw(10) << fixed << setprecision(2) << TransferRecord.Amount;
		cout << "| " << left << setw(15) << fixed << setprecision(2) << TransferRecord.FromAccountBalance;
		cout << "| " << left << setw(15) << fixed << setprecision(2) << TransferRecord.ToAccountBalance;
		cout << "| " << left << setw(15) << TransferRecord.DoneBy;
	}
public:
	static void _ShowTransferLogScreen() {
		vector <clsBankClient::stTransfer> vTransferLog;
		vTransferLog = clsBankClient::GetTransferLog();
		string Title = "\tTransfer Log Screen";
		string SubTitle = "\t\t(" + to_string(vTransferLog.size()) + ") Record(s).";
		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n" << endl;
		cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";					 
		cout << "| " << left << setw(15) << "From Account";											 
		cout << "| " << left << setw(15) << "To Account";											 
		cout << "| " << left << setw(10) << "Amount";												 
		cout << "| " << left << setw(15) << "From Balance";											 
		cout << "| " << left << setw(15) << "To Balance";											 
		cout << "| " << left << setw(15) << "Done By";												 
		cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n" << endl;
		if(vTransferLog.size()==0)
			cout << "\t\t\t\tNo Transfer Log Available In the System!";
		else
			for (clsBankClient::stTransfer Record : vTransferLog)
			{
				_PrintTransferRecordLine(Record);
				cout << endl;
			
			}
		cout << setw(8) << left << "" << "\n\t____________________________________________________________________________________________________________\n" << endl;

	}
};
