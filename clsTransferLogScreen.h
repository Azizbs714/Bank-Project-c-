#pragma once
#include <iostream>
#include "clsuser.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include <iomanip>

class clsTransferLogScreen : protected clsScreen
{
    private:
    
    static void PrintLoginRegisterRecordLine(clsBankClient::stTransactionLog Record)
    {

        cout << setw(8) << left << "" << "| " << setw(35) << left << Record.time ;
        cout << "| " << setw(15) << left << Record.accBalFrom; 
        cout << "| " << setw(15) << left << Record.accBalTo;
        cout << "| " << setw(15) << left << Record.amount ; 
        cout << "| " << setw(15) << left << Record.balanceFrom ;
        cout << "| " << setw(15) << left << Record.balanceTo ;
        cout << "| " << setw(15) << left << Record.userName ;
    }






    public:
        static void showTransferLogFile()
        {
            vector<clsBankClient::stTransactionLog> vTransfer = clsBankClient::getTransactionLogList();
            string title = "\tTransaction List Screen\n";
            string SubTitle =  "\t\t(" + to_string(vTransfer.size()) + ") Record(s).";
            drawScreenHeader(title,SubTitle);
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "___________________________________________________________________________\n" << endl;
            cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
            cout << "| " << left << setw(15) << "s.Acct";
            cout << "| " << left << setw(15) << "d.Acct";
            cout << "| " << left << setw(15) << "Amount";
            cout << "| " << left << setw(15) << "s.Balnce";
            cout << "| " << left << setw(15) << "d.Balance";
            cout << "| " << left << setw(15) << "User";
            cout << setw(8) << left << "" << "\n\t_______________________________________________________";
            cout << "___________________________________________________________________________\n" << endl;
            if (vTransfer.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
            else

            for (clsBankClient::stTransactionLog Record : vTransfer)
            {

                PrintLoginRegisterRecordLine(Record);
                cout << endl;
            }
        }
};