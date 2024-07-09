#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsuser.h"
#include "clsBankClient.h"

class clsTransferScreen : protected clsScreen
{
   static void PrintClient(clsBankClient client)
      {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nAcc. Number : " << client.getAccNumber();
        cout << "\nBalance     : " << client.getAccBalance();
        cout << "\n___________________\n";

      }

     static float ReadAmount(clsBankClient SourceClient)
   {
       float Amount;

       cout << "\nEnter Transfer Amount? ";

       Amount = clsInputValidate::readDblNumber();

       while (Amount > SourceClient.getAccBalance())
       {
           cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
           Amount = clsInputValidate::readDblNumber();
       }
       return Amount;
   } 

 public:
      static void showTransferScreen()
      {
        string title = "Transfer Screen";
        drawScreenHeader(title);
        string accFrom ; 
        cout << "Please Enter Account Number To Transfer From :";
        accFrom = clsInputValidate::ReadString();

        while (!clsBankClient::isClientExist(accFrom))
        {
           cout << "There's No Client By This Account!!\n";
           cout << "Please Enter Another Account Number : ";
           accFrom = clsInputValidate::ReadString();
        }

        clsBankClient clientFrom = clsBankClient::find(accFrom);
        PrintClient(clientFrom);
        
        cout << "Please Enter Account Number To Transfer To :";
        accFrom = clsInputValidate::ReadString();

        while (!clsBankClient::isClientExist(accFrom))
        {
           cout << "There's No Client By This Account!!\n";
           cout << "Please Enter Another Account Number : ";
           accFrom = clsInputValidate::ReadString();
        }
        
        clsBankClient clientTo = clsBankClient::find(accFrom);
        PrintClient(clientTo);

        float amount = ReadAmount(clientFrom);

        char isSure = 'n';

        cout << "Are You Sure You want to perform this Action ? Y/N : " ; 
        cin >> isSure ; 

        if(isSure == 'y' || isSure == 'Y')
        {
            if (clientFrom.Transfer(amount, clientTo))
            {
                cout << "\nTransfer done successfully\n";
                clientFrom.registerTransaction(clientTo,amount);
            }
            else
            {
                cout << "\nTransfer Faild \n";
            }
        }
        
        
        PrintClient(clientFrom);
        PrintClient(clientTo);
        
     






      }

};
