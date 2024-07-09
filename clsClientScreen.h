#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"

class clsClientScreen : protected clsScreen
{
   private :
       static void PrintClientRecordLine(clsBankClient Client)
         {

            cout << setw(8) << left << "" << "| " << setw(15) << left << Client.getAccNumber();
            cout << "| " << setw(20) << left << Client.FullName();
            cout << "| " << setw(12) << left << Client.getPhone();
            cout << "| " << setw(30) << left << Client.getEamil();
            cout << "| " << setw(10) << left << Client.getPinCode();
            cout << "| " << setw(12) << left << Client.getAccBalance();

         }

   public:
      static void showClientList()
      {
                 if(!CheckAccessRights(clsUser::enPermissions::pListClients))
                 {
                   return ; 
                 }        
    vector<clsBankClient> vClients = clsBankClient::getClientList() ; 
    string Title = "\t  Client List Screen";
    string SubTitle ="\t    (" + to_string(vClients.size()) + ") Client(s).";
    drawScreenHeader(Title,SubTitle);
    cout << setw(8) << left << "" <<   "\n\t________________________________________________________";
    cout <<   "___________________________________________________\n" << endl;
    cout <<  setw(8) << left << "" << "| " << left << setw(15) << "Accout Number";
    cout << "| "     << left << setw(20) << "Client Name";
    cout << "| "     << left << setw(12) << "Phone";
    cout << "| "     << left << setw(30) << "Email";
    cout << "| "     << left << setw(10) << "Pin Code";
    cout << "| "     << left << setw(12) << "Balance";
   cout << setw(8) << left << "" << "\n\t________________________________________________________";
        cout <<   "___________________________________________________\n" << endl;
    if (vClients.size() == 0)
        cout << "\t\t\t\tNo Clients Available In the System!";
    else

        for (clsBankClient Client : vClients)
        {

            PrintClientRecordLine(Client);
            cout << endl;
        }    
           cout << setw(8) << left << "" <<   "\n\t________________________________________________________";
           cout <<   "___________________________________________________\n" << endl;
      }      
};