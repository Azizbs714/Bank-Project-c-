#pragma once
#include <iostream>
#include "clsuser.h"
#include "clsScreen.h"
#include "global.h"
#include "clsMainMenuScreen.h"
#include "clsDate.h"
#include <fstream>

class clsShowLoginScreen : protected clsScreen
{
  private:
      static void addDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("loginRegister.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }
      static void login()
      {
         string userName , password ;
         bool loginFlaid = false ; 
        short loginsCount = 3 ; 

         do
         {
            if(loginFlaid)
              {
                cout << "\nInvalid Username/Password!\n\n";
                if(loginsCount == 0) 
                {
                    cout << "You are Locked After 3 Faild Trails. :-(\n";
                    break;
                }
                cout << "You Have " << loginsCount << " Trial(s) To Login.\n";
              }

              cout << "Enter UserName : ";
              cin >> userName ; 

              cout << "Enter Password : ";
              cin >> password ; 
              loginsCount--;
              cureentUser =  clsUser::Find(userName,password);
              loginFlaid  =  cureentUser.IsEmpty();
         } while (loginFlaid);

        if(loginsCount != 0)
          {
            cureentUser.registerLogIn();
            clsMainMenuScreen::showMainMenu();
          }  
      }
 public:
  static void showLoginScreen()
  {
    drawScreenHeader("Login Screen");
    login();
  } 

};