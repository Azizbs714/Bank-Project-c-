#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsMainMenuScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

class clsMainMenuScreen;

class clsTransactionsMeu : protected clsScreen
{
  private:
        enum enTransactionsMenu{eDeposit = 1 , eWithdraw = 2,
                                eShowTotalBalance = 3 , eTransfer = 4 , eTransferLog = 5  , eShowMainMenu = 6
                                };
        static short readMainMenuOption()
          {
                    cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
                    short choice = clsInputValidate::ReadIntNumberBetween(1,6 ,"Enter Number Betwwen 1 And 6 : ");
                    return choice ; 
          }      
        static void showDepositScreen()
            {
                clsDepositScreen::showDepositScreen();
            }

        static void showWithdrawScreen()
            {
                clsWithdrawScreen::showWithDrawScreen();
            }

        static void showTotalBalancesScreen()
            {
                clsTotalBalancesScreen::showTotalBalances() ;
            } 
        static void showTransferScreen()
        {
            clsTransferScreen::showTransferScreen();
        } 
        static void showTransferLogScreen()
        {
            clsTransferLogScreen::showTransferLogFile();
        }     
        static void performTransactionMenuOption(enTransactionsMenu transactionMenu)
          {
             switch (transactionMenu)
             {
               case enTransactionsMenu::eDeposit :
               {
                 showDepositScreen();
                 break;
               }
               case enTransactionsMenu::eWithdraw :
               {
                 showWithdrawScreen();
                 break;
               } 
               case enTransactionsMenu::eShowTotalBalance :
               {
                 showTotalBalancesScreen();
                 break;
               }
               case enTransactionsMenu::eTransfer :
               {
                 showTransferScreen();
                 break;
               }
               case enTransactionsMenu::eTransferLog :
               {
                 showTransferLogScreen();
                 break;
               }
               case enTransactionsMenu::eShowMainMenu :
               {
               }
            
             default:
                break;
             }
          }                    

   










   public:
        static void showTransactionMenu()
        {
          if(!CheckAccessRights(clsUser::enPermissions::pTranactions))
            {
              return ; 
            } 
            drawScreenHeader("\t  Transaction Screen");
            cout << setw(37) << left << "" << "=================================================" << endl ; 
            cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
            cout << setw(37) << left << "" << "=================================================" << endl ;
            cout << setw(37) << left << "" << "=================================================" << endl ; 
            cout << setw(37) << left << "" << "\t[1] Deposit.\n";
            cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
            cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
            cout << setw(37) << left << "" << "\t[4] Transfer.\n";
            cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
            cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
            cout << setw(37) << left << "" << "===========================================\n";
            performTransactionMenuOption((enTransactionsMenu)readMainMenuOption());
        }
};