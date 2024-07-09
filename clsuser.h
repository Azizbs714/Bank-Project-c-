#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "clsPerson.h"
#include "clsString.h"
#include "clsDate.h"
#include "clsUtil.h"

using namespace std ;

class clsUser : public clsPerson
{
    
 private :
     
     enum enMode {emptyMode = 0 , updateMode = 1 , addNewMode = 2 };

     enMode mode ; 
     string userName ; 
     string password ; 
     int permissions ;

     bool markForDelete = false ;
    
    // struct stLoginRegisterRecord;

    
      static clsUser ConvertLinetoUserObject(string line , string delim = "#//#")
    {
       vector<string> vec ; 
       vec = clsString::Split(line,delim);
       return clsUser(enMode::updateMode,vec.at(0),vec.at(1),vec.at(2),vec.at(3),vec.at(4),clsUtil::DecryptText(vec.at(5)),stoi(vec.at(6)));
    } 
    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.getFirstName() + Seperator;
        UserRecord += User.getLastName() + Seperator;
        UserRecord += User.getEamil() + Seperator;
        UserRecord += User.getPhone() + Seperator;
        UserRecord += User.userName + Seperator;
        UserRecord += clsUtil::EncryptText(User.password,2) + Seperator;
        UserRecord += to_string(User.permissions);

        return UserRecord;
    } 

    static vector<clsUser> loadDataUsersFromFile()
    {
      vector<clsUser> vUsersResult ;
      fstream myFile ;

      myFile.open("users.txt",ios::in);

      if(myFile.is_open())
      {
         string line ; 
         while (getline(myFile,line))
         {
           vUsersResult.push_back(ConvertLinetoUserObject(line));
         }
         myFile.close() ; 
      }
      return vUsersResult ; 
    }   
    static void saveUsersDataToFile(vector<clsUser> vUsers)
    {
       fstream myfile ;
       myfile.open("users.txt",ios::out);
       if(myfile.is_open())
       {
        string line ; 
        for(clsUser val : vUsers)
        {
          if (val.markForDelete == false)
          {
            myfile << _ConverUserObjectToLine(val) << endl  ;
          }
           
        }
        myfile.close();
       }
    }
    static clsUser _GetEmptyUserObject()
    {
        return clsUser(enMode::emptyMode, "", "", "", "", "", "", 0);
    }
    void update()
    {
        vector <clsUser> _vUsers;
        _vUsers = loadDataUsersFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.userName == userName)
            {
                U = *this;
                break;
            }

        }

        saveUsersDataToFile(_vUsers);

    }
    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }
    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
    string preparedLogINRecord(string seperator = "#//#" )
    {
             string login = "";
            login += clsDate::GetSystemDateTimeString() + seperator ;
            login += userName + seperator;
            login += clsUtil::EncryptText(password) + seperator ;
            login += to_string(permissions);
            return login ; 
    }
    

     public:
     enum enPermissions {
        eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4,
        pUpdateClients = 8, pFindClient = 16, pTranactions = 32, pManageUsers = 64 , pLoginRegister = 128
    };
    struct stLoginRegisterRecord {
        string DateTime;
        string UserName;
        string Password;
        int Permissions;
    }; 
    static stLoginRegisterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seperator = "#//#") {
        stLoginRegisterRecord LoginRegisterRecord;
        vector<string> LoginRegisterDataLine = clsString::Split(Line, Seperator);
        LoginRegisterRecord.DateTime = LoginRegisterDataLine[0];
        LoginRegisterRecord.UserName = LoginRegisterDataLine[1];
        LoginRegisterRecord.Password = clsUtil::DecryptText(LoginRegisterDataLine[2]);
        LoginRegisterRecord.Permissions = stoi(LoginRegisterDataLine[3]);
        return LoginRegisterRecord;
    }
     
        clsUser(enMode Mode, string FirstName, string LastName,
        string Email, string Phone, string UserName, string Password,
        int Permissions) :
        clsPerson(FirstName, LastName, Email, Phone)
        {
            mode = Mode;
            userName = UserName;
            password = Password;
            permissions = Permissions;
        }
       bool IsEmpty()
       {
        return (mode == enMode::emptyMode);
       }
       bool MarkedForDeleted()
    {
        return markForDelete;
    }

    string GetUserName()
    {
        return userName;
    }

    void SetUserName(string UserName)
    {
        userName = UserName;
    }
     void SetPassword(string Password)
    {
        password = Password;
    }

    string GetPassword()
    {
        return password;
    }
    void SetPermissions(int Permissions)
    {
        permissions = Permissions;
    }
    int GetPermissions()
    {
        return permissions;
    }
    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {    string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = ConvertLinetoUserObject(Line);
                if (User.userName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }
     static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);//read Mode

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = ConvertLinetoUserObject(Line);
                if (User.userName == UserName && User.password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }
    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };
    
    enSaveResults Save()
    {

        switch (mode)
        {
        case enMode::emptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case enMode::updateMode:
        {
            update();
            return enSaveResults::svSucceeded;

            break;
        }

        case enMode::addNewMode:
        {
            if (clsUser::IsUserExist(userName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                mode = enMode::updateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }
    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }
    
    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = loadDataUsersFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.userName == userName)
            {
                U.markForDelete = true;
                break;
            }

        }

        saveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }
     static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(enMode::addNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return loadDataUsersFromFile();
    }
    
    bool CheckAccessPermission(enPermissions permission)
    {
      if(this->GetPermissions() == enPermissions::eAll)
          return true ; 

      if((this->GetPermissions() & permission) == permission) 
          return true ;
      else 
         return false ;     
    }

    void registerLogIn()
    {
        string stDataLine = preparedLogINRecord();
        fstream MyFile;
         MyFile.open("loginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }
    }
    static  vector <stLoginRegisterRecord> GetLoginRegisterList()
     {
         vector <stLoginRegisterRecord> vLoginRegisterRecord;

         fstream MyFile;
         MyFile.open("loginRegister.txt", ios::in);

         if (MyFile.is_open())
         {

             string Line;
             while (getline(MyFile, Line))
             {
                 vLoginRegisterRecord.push_back(_ConvertLoginRegisterLineToRecord(Line));
             }

             MyFile.close();

         }

         return vLoginRegisterRecord;

     }
        
};