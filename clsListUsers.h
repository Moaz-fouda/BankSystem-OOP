#pragma once
#include <iostream>
#include "clsScreen.h"
#include <vector>
#include "clsUser.h"
#include <iomanip>
using namespace std;

class clsListUser : protected clsScreen {

private:

    static void _PrintUser(clsUser c) {

        cout << setw(8) << left << "";
        cout << "| " << setw(20) << left << c.GetFullName();
        cout << "| " << setw(15) << left << c.Phone;
        cout << "| " << setw(15) << left << c.UserName;
        cout << "| " << setw(15) << left << c.Password;
        cout << "| " << setw(12) << left << c.Permissions;
    }

public:

    static void _ShowUserListScreen() {

        vector<clsUser> cUsers = clsUser::GetUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(cUsers.size()) + ") User(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_____________________________________________________________________________________________\n\n";

       
        cout << setw(8) << left << ""
            << "| " << setw(20) << left << "Full Name"
            << "| " << setw(15) << left << "Phone"
            << "| " << setw(15) << left << "User Name"
            << "| " << setw(15) << left << "Password"
            << "| " << setw(12) << left << "Permissions";

        cout << setw(8) << left << ""
            << "\n\t_____________________________________________________________________________________________\n" << endl;

        
        if (cUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else {
            for (clsUser& u : cUsers) {
                _PrintUser(u);
                cout << endl;
            }
        }

        cout << setw(8) << left << ""
            << "\n\t_____________________________________________________________________________________________\n" << endl;
    }
};
