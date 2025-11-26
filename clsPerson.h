#pragma once
#include<iostream>
#include"clsString.h"
using namespace std;
class clsPerson {
private:
	string _FirstName;
	string _LastName;
	string _Email;
	string _Phone;
public:
	clsPerson(string FirstName, string Lastname, string Email, string Phone) {
		_FirstName = FirstName;
		_LastName = Lastname;
		_Email = Email;
		_Phone = Phone;
	}
	void SetFirst(string x) {
		_FirstName = x;

	}
	string GetFirst() {
		return _FirstName;
	}
	__declspec(property(get = GetFirst, put = SetFirst))string FirstName;
	void SetLast(string y) {
		_LastName = y;

	}
	string GetLast() {
		return _LastName;
	}
	__declspec(property(get = GetLast, put = SetLast))string LastName;
	string GetFullName() {
		return _FirstName + ' ' + _LastName;
	}
	void SetEmail(string E) {
		_Email = E;
	}
	string GetEmail() {
		return _Email;
	}
	__declspec(property(get = GetEmail, put = SetEmail))string Email;
	void SetPhone(string P) {
		_Phone = P;
	}
	string GetPhone() {
		return _Phone;
	}
	__declspec(property(get = GetPhone, put = SetPhone))string Phone;
};


