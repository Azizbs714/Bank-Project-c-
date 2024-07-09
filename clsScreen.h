#pragma once
#include <iostream>
#include "global.h"
#include "clsDate.h"
using namespace std ;
class clsScreen
{
    protected:
    static void drawScreenHeader(string Title, string SubTitle ="")
    {
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << Title;
        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";
        cout << "\n\n\t\t\t\t\t  " << "User:  " << cureentUser.GetUserName() << endl ;
        cout << "\t\t\t\t\t  " << "Date:  " << clsDate::DateToString(clsDate()) << "\n\n" ;
    }

    static bool CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!cureentUser.CheckAccessPermission(Permission))
            {
                cout << "\t\t\t\t\t______________________________________";
                cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";   
                cout << "\n\t\t\t\t\t______________________________________\n\n";
                return false;
            }
        else
            {
                return true;
            }
    }
};



