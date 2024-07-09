#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"


class clsFindClientScreen : protected clsScreen
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

    public:
        static void findClientScreen()
        {
           if(!CheckAccessRights(clsUser::enPermissions::pFindClient))
              {
                   return ; 
              } 
           string title = "\t  Find Client Screen";
          drawScreenHeader(title);
          string accNumber = "" ;
          cout << "\nPlease Enter Client Account Number : ";
          accNumber = clsInputValidate::ReadString();
          while (!clsBankClient::isClientExist(accNumber))
                {
                    cout << "Account Number is Not Found, Choose Another One : ";
                    accNumber = clsInputValidate::ReadString();
                }
           clsBankClient client1 = clsBankClient::find(accNumber);

           if(!client1.isEmpty())
           {
             cout << "Client is Not Empty:-).\n";
           }     
           else
           {
            cout << "Client was Not Found:-(.\n";
           }

           PrintClient(client1);
        }
         
};