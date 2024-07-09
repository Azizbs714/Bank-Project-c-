#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"

class clsDepositScreen : protected clsScreen
{

    private:
      static void PrintClient(clsBankClient client)
      {
        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << client.getFirstName();
        cout << "\nLastName    : " << client.getLastName();
        cout << "\nFull Name   : " << client.FullName();
        cout << "\nEmail       : " << client.getEamil();
        cout << "\nPhone       : " << client.getPhone();
        cout << "\nAcc. Number : " << client.getAccNumber();
        cout << "\nPassword    : " << client.getPinCode();
        cout << "\nBalance     : " << client.getAccBalance();
        cout << "\n___________________\n";

      }
      static string _ReadAccountNumber()
    {
        string AccountNumber = "";
        cout << "\nPlease enter AccountNumber? ";
        cin >> AccountNumber;
        return AccountNumber;
    }
    public:
        static void showDepositScreen()
        {
            drawScreenHeader("Deposit Screen");
            string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::isClientExist(AccountNumber))
         {
            cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
            AccountNumber = _ReadAccountNumber();
         }
          clsBankClient Client1 = clsBankClient::find(AccountNumber);
         PrintClient(Client1);
 
        double Amount = 0;
        cout << "\nPlease enter deposit amount? ";
        Amount = clsInputValidate::readDblNumber();
        cout << "\nAre you sure you want to perform this transaction? ";
        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'Y' || Answer == 'y')
        {
            Client1.deposit(Amount);
            cout << "\nAmount Deposited Successfully.\n";
            cout << "\nNew Balance Is: " << Client1.getAccBalance();
        }
        else
        {
            cout << "Operation Cacelled.\n";
        }
        

        }

};