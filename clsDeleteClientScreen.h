#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
class clsDeleteClientScreen : protected clsScreen
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
     static void deleteAccount()
  {
    if(!CheckAccessRights(clsUser::enPermissions::pDeleteClient))
      {
        return ; 
      } 
    string title = "\t  Delete Client Screen";
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
   PrintClient(client1);

   cout << "Are You Sure You Want To Delete This Client y/n? ";

   char answer = 'n'; 
   cin >> answer ;
   if(answer == 'y' || answer == 'Y')
   {
    if(client1.Delete())
    {
     cout << "\nClient Deleted Succesfully :-)\n";
     PrintClient(client1);
    }
    else
    {
      cout << "\nError Client Was Not Deleted:-(\n";
    }
    
   }
}
        
};