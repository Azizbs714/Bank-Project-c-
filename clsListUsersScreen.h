#pragma once
#include <iostream>
#include "clsuser.h"
#include "clsScreen.h"
#include <iomanip>


class clsListUserScreen : protected clsScreen
{
   private:
    static void _PrintUserRecordLine(clsUser User)
    {

        cout << setw(8) << left << "" << "| " << setw(12) << left << User.GetUserName();
        cout << "| " << setw(25) << left << User.FullName();
        cout << "| " << setw(12) << left << User.getPhone();
        cout << "| " << setw(27) << left << User.getEamil();
        cout << "| " << setw(12) << left << User.GetPassword();
        cout << "| " << setw(12) << left << User.GetPermissions();

    }
    public:

    static void ShowUsersList()
    {
        vector <clsUser> vUsers = clsUser::GetUsersList();

        string Title = "\t  User List Screen";
        string SubTitle = "\t    (" + to_string(vUsers.size()) + ") User(s).";

        drawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(27) << "Email";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________________\n" << endl;

        if (vUsers.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else

            for (clsUser User : vUsers)
            {

                _PrintUserRecordLine(User);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_______________________________________________________\n" << endl;
    }
};
