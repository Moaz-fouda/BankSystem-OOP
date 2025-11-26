#pragma once
#include<iostream>
#include<string>
#include"clsGlobal.h"
#include<fstream>
#include"clsString.h"
#include"clsPerson.h"
#include<vector>
using namespace std;
class clsBankClient :public clsPerson {
private:
	enum enMode{Empty=0,enUpdate1=1,enAdd=2};
	enMode _Mode;
	string _AccountNumber;
	string _Pincode;
	double _Ballanced;
	bool MarkForDelete = false;
	struct stTransfer;
	static stTransfer _ConvertLineToTransferRecord(string Line, string sep = "#//#") {
		stTransfer TransferRecord;
		vector<string> v = clsString::Split(Line, sep);
		TransferRecord.DateTime = v[0];
		TransferRecord.FromAccount = v[1];
		TransferRecord.ToAccount = v[2];
		TransferRecord.Amount = stod(v[3]);
		TransferRecord.FromAccountBalance = stod(v[4]);
		TransferRecord.ToAccountBalance = stod(v[5]);
		TransferRecord.DoneBy = v[6];
		return TransferRecord;
	}
	
	static clsBankClient _ConvertLineToObject(string Line, string sep = "#//#") {
		vector<string> v = clsString::Split(Line, sep);
		return clsBankClient(enMode::enUpdate1, v[0], v[1], v[2], v[3], v[4], v[5],stod(v[6]));
	}
	string _PrepareTransferRecord(clsBankClient C,double am, string Sep = "#//#") {
		string LoginRecord = "";
		LoginRecord += clsDate::GetSystemDateTimeString() + Sep;
		LoginRecord += _AccountNumber + Sep;
		LoginRecord += C.GetAccountNumber() + Sep;
		LoginRecord += to_string(am) + Sep;
		LoginRecord += to_string(AccountBalance) + Sep;
		LoginRecord += to_string(C.AccountBalance) + Sep;
		LoginRecord += CurrentUser.GetUserName();
		return LoginRecord;

	}
	void _RegisterTransferLog(clsBankClient C, double am) {
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);
		string stDate = _PrepareTransferRecord(C, am);
		if (MyFile.is_open())
		{
			MyFile << stDate << endl;
			MyFile.close();
		}
	}
	static string _ConvertObjectToLine(clsBankClient Client, string sep = "#//#") {
		string stClientRecord = "";
		stClientRecord += Client.FirstName + sep;
		stClientRecord += Client.LastName + sep;
		stClientRecord += Client.Email + sep;
		stClientRecord += Client.Phone + sep;
		stClientRecord += Client.GetAccountNumber() + sep;
		stClientRecord += Client.PinCode + sep;
		stClientRecord += to_string(Client._Ballanced);
		return stClientRecord;
	}
	static clsBankClient _GetEmptyObject() {
		return clsBankClient(enMode::Empty, "", "", "", "", "", "", 0);
	}
	 static vector<clsBankClient> _LoadDateFromFile() {
		 vector<clsBankClient> vClient;
		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::in);
		 if (MyFile.is_open()) {
			 string line;
			 while (getline(MyFile, line)) {
				 clsBankClient c = _ConvertLineToObject(line);
				 vClient.push_back(c);
			 }
			 MyFile.close();
		 }
		 return vClient;

	}
	 static void _SaveDateToFile(vector<clsBankClient>v) {
		 fstream myFile;
		 myFile.open("Clients.txt", ios::out);
		 if (myFile.is_open()) {
			 string line;
			 for (clsBankClient& c : v) {
				 if (c.MarkForDelete==false) {
					 line = _ConvertObjectToLine(c);
					 myFile << line << endl;
				 }
			 }
			 myFile.close();
		 }

		
	 }
	 void _Update() {

		 vector<clsBankClient> vClients;
		 vClients = _LoadDateFromFile();

		 for (clsBankClient& C : vClients) {

			 if (C.GetAccountNumber()==GetAccountNumber())
			 {
				 C = *this;
				 break;
			 }

		 }

		_SaveDateToFile (vClients);

	 }
	
	 void _AddDataLineToFile(string  stDataLine)
	 {
		 fstream MyFile;
		 MyFile.open("Clients.txt", ios::out | ios::app);

		 if (MyFile.is_open())
		 {

			 MyFile << stDataLine << endl;

			 MyFile.close();
		 }

	 }
	 void _Add() {
		 _AddDataLineToFile(_ConvertObjectToLine(*this));
			 
		 }

	
public:
	clsBankClient(enMode Mode, string FirstName, string Lastname, string Email, string Phone, string Acc, string Pin, double x) :clsPerson(FirstName, Lastname, Email, Phone) {
		_Mode = Mode;
		_AccountNumber = Acc;
		_Pincode = Pin;
		_Ballanced = x;
	}
	string GetAccountNumber() {
		return _AccountNumber;
	}
	struct stTransfer
	{
		string DateTime;
		string FromAccount;
		string ToAccount;
		double Amount;
		double FromAccountBalance;
		double ToAccountBalance;
		string DoneBy;

	};
	void SetPinCode(string Pin) {
		_Pincode = Pin;
	}
	string GetPinCode() {
		return _Pincode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;
	void SetBallanced(double x) {
		_Ballanced = x;
	}
	double GetBallanced() {
		return _Ballanced;
	}
	__declspec(property(get = GetBallanced, put = SetBallanced)) double AccountBalance;
	bool IsEmpty() {
		return (_Mode==enMode::Empty);
	}

	//void Print()
	//{
	//	cout << "\nClient Card:";
	//	cout << "\n___________________";
	//	cout << "\nFirstName   : " << FirstName;
	//	cout << "\nLastName    : " << LastName;
	//	cout << "\nFull Name   : " << GetFullName();
	//	cout << "\nEmail       : " << Email;
	//	cout << "\nPhone       : " << Phone;
	//	cout << "\nAcc. Number : " << _AccountNumber;
	//	cout << "\nPassword    : " << _Pincode;
	//	cout << "\nBalance     : " << _Ballanced;
	//	cout << "\n___________________\n";

	//}
	static clsBankClient GetNewClient(string Acc) {
		return clsBankClient(enMode::enAdd, "", "", "", "", Acc, "", 0);
	}
	static clsBankClient Find(string Acc) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsBankClient c = _ConvertLineToObject(line);
				if (c.GetAccountNumber() == Acc) {
					MyFile.close();
					return c;
				}
				
			}
			MyFile.close();
		}
		return _GetEmptyObject();

	}
	static clsBankClient Find(string Acc, string Pin) {
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				clsBankClient c = _ConvertLineToObject(line);
				if (c.GetAccountNumber() == Acc&&c.PinCode==Pin) {
					MyFile.close();
					return c;
				}

			}
			MyFile.close();
		}
		return _GetEmptyObject();

	}
	
	static bool IsClientExist(string Acc) {
		clsBankClient c = Find(Acc);
		return(!c.IsEmpty());
	}
	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded, svFaildAccountNumberExists = 2};
	enSaveResults Save() {
		switch (_Mode) {
		case enMode::Empty: {
			return svFaildEmptyObject;
			break;
		}
		case enMode::enUpdate1: {
			_Update();
			return svSucceeded;
			break;
		}
		case enMode::enAdd:
		{
			if (clsBankClient::IsClientExist(_AccountNumber)) {
				return enSaveResults::svFaildAccountNumberExists;
			}
			else {
				_Mode = enUpdate1;
				_Add();
				return enSaveResults::svSucceeded;
			
			}
			break;   

		}

				

		}
	}
	bool Delete()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadDateFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.GetAccountNumber() == _AccountNumber)
			{
				C.MarkForDelete = true;
				break;
			}

		}

	_SaveDateToFile(_vClients);

		*this =_GetEmptyObject();

		return true;

	}
	static vector<clsBankClient>GetClientList() {
		return _LoadDateFromFile();
	}
	static double GetTotalBalanced() {
		vector <clsBankClient> _vClients = clsBankClient::GetClientList();
	
		double x = 0;
		for (clsBankClient& C : _vClients)
		{
			x += C.AccountBalance;

		}
		return x;
	}
	void Deposite(double a) {
		AccountBalance += a;
		Save();

	}
	void Withdraw(double a) {
		AccountBalance -= a;
		Save();
	}
	bool Transfer(clsBankClient& ToClient, double a) {
		if (a > AccountBalance) {
			return false;
		}
		Withdraw(a);
		ToClient.Deposite(a);
		_RegisterTransferLog(ToClient, a);
		return true;
	}
	static vector<stTransfer> GetTransferLog() {
		vector<stTransfer> v;
		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);
		if (MyFile.is_open()) {
			string line;
			while (getline(MyFile, line)) {
				stTransfer t = _ConvertLineToTransferRecord(line);
				v.push_back(t);
			}
			MyFile.close();
		}
		return v;
	}
	

};
