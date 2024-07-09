#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
#include "global.h"

class clsBankClient : public clsPerson
{
   private:
       enum enMode {emptyMode = 0 , updateMode = 1 , addNewMode = 2 };
       enMode mode ; 

    string accNumber ; 
    string pinCode ;
    double accountBalance ;
    bool markForDelete = false ;  
    
    static clsBankClient ConvertLinetoClientObject(string line , string delim = "#//#")
    {
       vector<string> vec ; 
       vec = clsString::Split(line,delim);
       return clsBankClient(enMode::updateMode,vec.at(0),vec.at(1),vec.at(2),vec.at(3),vec.at(4),vec.at(5),stod(vec.at(6)));
    }
    static string convertLineObjectToLine(clsBankClient lineObj, string delim = "#//#")
    {
       return lineObj.getFirstName() + delim + lineObj.getLastName() + delim + lineObj.getEamil() + delim + lineObj.getPhone() + delim +lineObj.getAccNumber() +delim + lineObj.pinCode + delim + to_string(lineObj.accountBalance) ;
    }
    static clsBankClient _GetEmptyClientObject()
    {
         return clsBankClient(enMode::emptyMode,"","","","","","",0.0);
    }
    static vector<clsBankClient> loadDataClientsFromFile()
    {
      vector<clsBankClient> vClientsResult ;
      fstream myFile ;

      myFile.open("azouz.txt",ios::in);

      if(myFile.is_open())
      {
         string line ; 
         while (getline(myFile,line))
         {
           vClientsResult.push_back(ConvertLinetoClientObject(line));
         }
         myFile.close() ; 
      }
      return vClientsResult ; 
    }
    static void saveClientsDataToFile(vector<clsBankClient> vClients)
    {
       fstream myfile ;
       myfile.open("azouz.txt",ios::out);
       if(myfile.is_open())
       {
        string line ; 
        for(clsBankClient val : vClients)
        {
          if (val.markForDelete == false)
          {
            myfile << convertLineObjectToLine(val) << endl  ;
          }
           
        }
        myfile.close();
       }
    }
    void update()
    {
      vector<clsBankClient> vClients = loadDataClientsFromFile();

      for(clsBankClient &valObject : vClients)
      {
        if(valObject.accNumber == getAccNumber())
        {
          valObject = *this ;
          break;
        }
      }
      saveClientsDataToFile(vClients);
    }
    void addNew()
    {
      addDataLineToFile(convertLineObjectToLine(*this));
    }
    void addDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("azouz.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
    string preparedTransactionRecord(clsBankClient recivedClient , double amount , string seperator = "#//#")
    {
             string transaction = "";
            transaction += clsDate::GetSystemDateTimeString() + seperator ;
            transaction += accNumber + seperator;
            transaction += recivedClient.accNumber + seperator ;
            transaction += to_string(amount) + seperator ;
            transaction += to_string(accountBalance) + seperator ;
            transaction += to_string(recivedClient.accountBalance) + seperator ;
            transaction += cureentUser.GetUserName();

            return transaction ; 
    }
  public:
      clsBankClient(enMode mode , string fName , string lName , string email , string phone , string accNumber , string pinCode , double accBalnace)
      : clsPerson(fName,lName,email,phone)
      {
        this->mode = mode ; 
        this->accNumber = accNumber ;
        this->pinCode = pinCode ; 
        this->accountBalance = accBalnace ; 
      }
      struct stTransactionLog
      {
        string time ; 
        string accBalFrom ;
        string accBalTo ; 
        double amount ; 
        double balanceFrom ; 
        double balanceTo ; 
        string userName ;
      };  
      static stTransactionLog convertTransactionLineToRecord(string line , string sep = "#//#")
      {
        stTransactionLog transactionLog  ;
        vector<string> vec = clsString::Split(line , sep);
        transactionLog.time = vec.at(0);
        transactionLog.accBalFrom = vec.at(1) ; 
        transactionLog.accBalTo = vec.at(2);
        transactionLog.amount = stod(vec.at(3));
        transactionLog.balanceFrom = stod(vec.at(4));
        transactionLog.balanceTo = stod(vec.at(5));
        transactionLog.userName = vec.at(6);
        return transactionLog ; 
      }
      string getAccNumber()
      {
        return accNumber ; 
      }
      void setPinCode(string pCode)
      {
       pinCode = pCode ;
      }
      string getPinCode()
      {
        return pinCode ; 
      }
      double getAccBalance()
      {
        return accountBalance ; 
      }
      void setAccBalance(double newBalance)
      {
         accountBalance = newBalance ; 
      }
      bool isEmpty()
      {
        return mode == enMode::emptyMode ; 
      }
    
    
    static clsBankClient find(string accNum)
    {
       fstream myFile ; 

       myFile.open("azouz.txt",ios::in);

       if(myFile.is_open())
       {
        string line ;

        while (getline(myFile,line))
        {
           clsBankClient client = ConvertLinetoClientObject(line);
           if(client.accNumber == accNum)
           {
             myFile.close();
             return client ; 
           }
        }
         myFile.close();
       }
        return _GetEmptyClientObject();
    }
    bool Delete()
    {
      vector<clsBankClient> vecClients = loadDataClientsFromFile();
      for(clsBankClient &currentClient : vecClients)
      {
        if(currentClient.accNumber == getAccNumber())
        {
          currentClient.markForDelete = true ; 
          break;
        }
      }
      saveClientsDataToFile(vecClients);
      *this = _GetEmptyClientObject() ;
      return true ;
    }
    static clsBankClient find(string accNum , string pinCode)
    {
       fstream myFile ; 

       myFile.open("azouz.txt",ios::in);

       if(myFile.is_open())
       {
        string line ;

        while (getline(myFile,line))
        {
           clsBankClient client = ConvertLinetoClientObject(line);
           if(client.accNumber == accNum && client.pinCode == pinCode)
           {
             myFile.close();
             return client ; 
           }
        }
         myFile.close();
       }
        return _GetEmptyClientObject();
    }
    enum enSaveResults {svFaildEmptyObject = 0 , svSucceeded = 1 , svFaildAccountNumberExists = 2 };
    static clsBankClient getAddNewClientObject(string accNumber)
    {
      return clsBankClient(enMode::addNewMode,"","","","",accNumber,"",0.0);
    }
    static vector<clsBankClient> getClientList()
    {
      return loadDataClientsFromFile();
    }
    static double getTotalBalances()
    {
      vector<clsBankClient> vClients = loadDataClientsFromFile();
    double totalBalances = 0 ; 
      for(clsBankClient &client : vClients)
      {
        totalBalances += client.accountBalance ; 
      }
      return totalBalances ; 
    }
    enSaveResults save()
    {
      switch (mode)
      {
      case enMode::emptyMode :
       {
          return enSaveResults::svFaildEmptyObject ; 
       }  
       case enMode::updateMode :
       {
          update();
          return enSaveResults::svSucceeded ;
          break;
       } 
       case enMode::addNewMode :
       {
        if(clsBankClient::isClientExist(accNumber))
        {
          return enSaveResults::svFaildAccountNumberExists ;
        }
        else
        {
          addNew();
          mode = enMode::updateMode ; 
          return enSaveResults::svSucceeded ; 
        }
       }
      }
      return enSaveResults::svSucceeded ;
    }

    static bool isClientExist(string accNumber)
    {
      clsBankClient client1 = find(accNumber);
      return !client1.isEmpty() ;  // !true = !client doesn't exist = false = cleint e . 
    }          
    void deposit(double Amount)
    {
        accountBalance += Amount;
        save();
    }
    void withDraw(double Amount)
    {
      accountBalance -= Amount;
      save() ; 
    }
   
    bool Transfer(float Amount, clsBankClient &DestinationClient)
    {
        if (Amount > accountBalance)
        {
            return false;
        }
    
        withDraw(Amount);
        DestinationClient.deposit(Amount);
        return true;
    }
    
    void registerTransaction(clsBankClient recivedClient , double amount)
    {
      string transaction = preparedTransactionRecord(recivedClient ,amount);
       fstream MyFile;
         MyFile.open("transactionRegister.txt", ios::out | ios::app);
          if (MyFile.is_open())
        {

            MyFile << transaction << endl;

            MyFile.close();
        }
    }

  static vector<stTransactionLog> getTransactionLogList()
  {
     vector<stTransactionLog> vTransaction ; 
     fstream MyFile;
     MyFile.open("transactionRegister.txt", ios::in);
     if (MyFile.is_open())
     {
      string Line;
             while (getline(MyFile, Line))
             {
                 vTransaction.push_back(convertTransactionLineToRecord(Line));
             }
     }
     return vTransaction ;
  }







};

