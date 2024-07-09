#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsAddClientScreen : protected clsScreen
{
   private :
       static void readClientInfo(clsBankClient &cleint)
       {
            cout << "Enter First Name : ";
            cleint.setFirstName(clsInputValidate::ReadString()) ;
            cout << "Enter Last Name  : ";
            cleint.setLastName(clsInputValidate::ReadString()) ;
            cout << "Enter Email     : ";
            cleint.setEamil(clsInputValidate::ReadString()) ;
            cout << "Enter Phone      : ";
            cleint.setPhone(clsInputValidate::ReadString()) ;
            cout << "Enter PinCode    : ";
            cleint.setPinCode(clsInputValidate::ReadString()) ;
            cout << "Enter Balance    : ";
            cleint.setAccBalance(clsInputValidate::readDblNumber()) ;
      }
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
       static void addNewClient()
       {
           if(!CheckAccessRights(clsUser::enPermissions::pAddNewClient))
                 {
                   return ; 
                 } 
            string title = "\t  Add Client Screen";
            drawScreenHeader(title);
            string accNumber ; 
            cout << "\nPlease Enter Client Account Number : ";
            accNumber = clsInputValidate::ReadString();
            while (clsBankClient::isClientExist(accNumber))
            {
                cout << "\nAccount Number is Already Used, Choose Another One: ";
                accNumber = clsInputValidate::ReadString();
            }
            clsBankClient addNewClient = clsBankClient::getAddNewClientObject(accNumber);

            readClientInfo(addNewClient);

            clsBankClient::enSaveResults saveResult ; 
            saveResult = addNewClient.save();
            switch (saveResult)
            {
            case clsBankClient::enSaveResults::svSucceeded :
            {
                cout << "\nAccount Added Succesfully :-)\n";
                PrintClient(addNewClient);
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject :
            {
                cout << "\nError Account Was Not saved Because it's Empty";
                break ; 
            }
            case clsBankClient::enSaveResults::svFaildAccountNumberExists :
            {
                cout << "\nError account was not saved because account number is used!\n";
                break;
            }
            }
        }  
};