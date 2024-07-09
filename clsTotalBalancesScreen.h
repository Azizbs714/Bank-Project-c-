#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include <iomanip>


class clsTotalBalancesScreen : protected clsScreen
{
   private :
      static void printBalancesInfo(clsBankClient Client)
            {
              cout << setw(25) << left << "" << 
              "| " << setw(15) << left << Client.getAccNumber();
              cout << "| " << setw(40) << left << Client.FullName();
              cout << "| " << setw(12) << left << Client.getAccBalance();  
            }
    public :
      static void showTotalBalances()
    {
        vector<clsBankClient> vClients = clsBankClient::getClientList();
        double totalBlances = clsBankClient::getTotalBalances() ; 
        string Title = "\t  Client List Screen";
        string SubTitle ="\t    (" + to_string(vClients.size()) + ") Client(s).";
        drawScreenHeader(Title,SubTitle);
            cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
            cout << "__________________________\n" << endl;
            cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
            cout <<   "| " << setw(40) << left << "Client Name";
            cout <<   "| " << setw(40) << left << "Balance";
           cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
            cout << "__________________________\n" << endl;;
            if(vClients.size() == 0 )
            {
            cout << "\t\t\t\tNo Clients Available In the System!";
            }
            else
            {
            for(clsBankClient &client : vClients)
              {
                  printBalancesInfo(client);  
                  cout << endl ; 
              }
            }
          cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
            cout << "__________________________\n" << endl;
            cout << setw(70) << right << "Total Balances = "<< totalBlances << endl ;
            cout << setw(55) << right  << "( " << clsUtil::NumberToText(totalBlances)  << " )" << endl ; 
     }        
};