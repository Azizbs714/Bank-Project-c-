#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsUpdateClientScreen : protected clsScreen
{
    private:
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
       
static void updateClient()
{
   if(!CheckAccessRights(clsUser::enPermissions::pUpdateClients))
      {
        return ; 
      } 
    string title = "\t  Update Client Screen";
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

  cout << "\n\nUpdate Client Info :\n";
  cout << "________________________\n"; 
  readClientInfo(client1);

  clsBankClient::enSaveResults saveResult ;

   saveResult = client1.save();

   switch (saveResult)
   {
   case clsBankClient::enSaveResults::svSucceeded :
   {
     cout << "\nAccount Updated Succesfully :-)\n";
     PrintClient(client1);
     break;
   }
   case clsBankClient::enSaveResults::svFaildEmptyObject :
   {
      cout << "\nError Account Was Not saved Because it's Empty";
      break ; 
   }
   }
}   
};