#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUsersScreen : protected clsScreen
{

  private:  
    enum enManageUsers  {listUsers = 1 , addNewuser = 2 , deleteUser = 3 , updateUser = 4 , findUser = 5 , MainMenu = 6};

    static short readUsersMenuOption()
          {
                    cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
                    short choice = clsInputValidate::ReadIntNumberBetween(1,6,"Enter Number Betwwen 1 And 6 : ");
                    return choice ; 
          } 
    
    static void _ShowListUsersScreen()
    {
       clsListUserScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
       clsDeleteUserScreen::ShowDeleteUserScreen();

    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }      

    static void performTransactionMenuOption(enManageUsers manageUsers)
    {
       switch (manageUsers)
       {
       case enManageUsers::listUsers :
        {
          _ShowListUsersScreen();
          break;
        }
        case enManageUsers::addNewuser :
        {
          _ShowAddNewUserScreen(); 
          break;
        }
        case enManageUsers::deleteUser :
        {
            _ShowDeleteUserScreen();
            break;
        }
        case enManageUsers::updateUser :
        {
            _ShowUpdateUserScreen();
            break;
        }
        case enManageUsers::findUser :
        {
            _ShowFindUserScreen();
            break;  
        }
        case enManageUsers::MainMenu :
        {
            //do nothing here the main screen will handle it :-) ;
        }
       
       default:
        break;
       }
    }
    
  public:
     static void  ShowManageUsersMenue()
     {
        if(!CheckAccessRights(clsUser::enPermissions::pManageUsers))
        {
          return ; 
        } 
        drawScreenHeader("Manage Users Screen");
         cout << setw(37) << left << "" << "=================================================" << endl ; 
         cout << setw(37) << left << "" << "\t\t\tManage Users Menue\n";
         cout << setw(37) << left << "" << "=================================================" << endl ;
         cout << setw(37) << left << "" << "\t[1] List Users.\n";
         cout << setw(37) << left << "" << "\t[2] Add New User.\n";
         cout << setw(37) << left << "" << "\t[3] Delete User.\n";
         cout << setw(37) << left << "" << "\t[4] Update User.\n";
         cout << setw(37) << left << "" << "\t[5] Find User.\n";
         cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
         performTransactionMenuOption((enManageUsers) readUsersMenuOption());
     }    
     
};
