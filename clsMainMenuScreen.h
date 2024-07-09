#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsClientScreen.h"
#include "clsAddClientScreen.h"
#include "clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include "clsFindClientScreen.h"
#include "clsTransactionsMenu.h"
#include "clsManageUsersScreen.h"
#include "global.h"
#include "clsLoginRegister.h"

class clsMainMenuScreen : protected clsScreen
{
   private:
        enum enMainMenueOptions {
            eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
            eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
            eManageUsers = 7, eLoginRegister = 8 , eExit = 9
        };
        
      static short readMainMenuOption()
      {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 9]? ";
        short choice = clsInputValidate::ReadIntNumberBetween(1,9,"Enter Number Betwwen 1 And 9 : ");
        return choice ; 
      }   
       static void _ShowAllClientsScreen()
       {
         clsClientScreen::showClientList();
       }
       static void _ShowAddNewClientsScreen()
       {
           clsAddClientScreen::addNewClient(); 
       }

       static void _ShowDeleteClientScreen()
       {
           clsDeleteClientScreen::deleteAccount();
       }

       static void _ShowUpdateClientScreen()
       {
           clsUpdateClientScreen::updateClient();

       }

       static void _ShowFindClientScreen()
       {
          clsFindClientScreen::findClientScreen() ; 
       }

       static void _ShowTransactionsMenue()
       {
           clsTransactionsMeu::showTransactionMenu();
       }

       static void _ShowManageUsersMenue()
       {
          clsManageUsersScreen::ShowManageUsersMenue();
       }
       static void _ShowLoginRegister()
       { 
        clsLoginRegister::showLoginRegisterFile();
       }
       static void logOut()
           {
               cureentUser = clsUser::Find("","");
           } 
     static void _PerfromMainMenueOption(enMainMenueOptions MainMenueOption)
     {
        switch (MainMenueOption)
            {
            case enMainMenueOptions::eListClients:
            {
                _ShowAllClientsScreen();
                break;
            }
            case enMainMenueOptions::eAddNewClient:
               _ShowAddNewClientsScreen();
                break;

            case enMainMenueOptions::eDeleteClient:
                _ShowDeleteClientScreen();
                break;

            case enMainMenueOptions::eUpdateClient:
                _ShowUpdateClientScreen();
                break;

            case enMainMenueOptions::eFindClient:
                _ShowFindClientScreen();
                break;

            case enMainMenueOptions::eShowTransactionsMenue:
                _ShowTransactionsMenue();
                break;

            case enMainMenueOptions::eManageUsers:
                _ShowManageUsersMenue();
                break;
            case enMainMenueOptions::eLoginRegister:
                _ShowLoginRegister();
                break;
            case enMainMenueOptions::eExit:
                logOut();
                break;
            }
     }









  public:
        static void showMainMenu()
        {
            
            drawScreenHeader("\t\tMain Screen");

            cout << setw(37) << left << "" << "=================================================" << endl ; 
            cout << setw(37) << left << "" << "\t\t\tMain Menue\n";
            cout << setw(37) << left << "" << "=================================================" << endl ; 
            cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
            cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
            cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
            cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
            cout << setw(37) << left << "" << "\t[5] Find Client.\n";
            cout << setw(37) << left << "" << "\t[6] Transactions.\n";
            cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
            cout << setw(37) << left << "" << "\t[8] Login Register.\n";
            cout << setw(37) << left << "" << "\t[9] Logout.\n";
            cout << setw(37) << left << "" << "===========================================\n";
          _PerfromMainMenueOption((enMainMenueOptions)readMainMenuOption());



        }
 
};