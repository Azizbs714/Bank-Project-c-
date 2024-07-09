#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"
#include "clsUtil.h"
#include <limits>

class clsInputValidate
{
    public:
       static bool isNumberBetween(int val , int from , int to)
       {
        if(val >= from && val <= to) return true ;
          return false ;    
       }
        static bool isNumberBetween(short val , short from , short to)
       {
        if(val >= from && val <= to) return true ;
          return false ;    
       }
       static bool isNumberBetween(double val , double from , double to)
       {
        if(val >= from && val <= to) return true ;
          return false ;   
       }
       static bool isDateBetween(clsDate date , clsDate dateFrom , clsDate dateTo)
       {
          if(clsDate::IsDate1AfterDate2(dateFrom,dateTo))
          {
            clsDate::SwapDates(dateFrom,dateTo);
          }
          return ( (clsDate::IsDate1AfterDate2(date,dateFrom) || clsDate::IsDate1EqualDate2(date, dateFrom)) && (clsDate::IsDate1BeforeDate2(date,dateTo) || clsDate::IsDate1EqualDate2(date,dateTo))) ;
       }

       static int readIntNumber(string ErrorMessage = "Invalid Number, Enter again\n")
       {
         int Number ;
         while (!(cin >> Number)) 
         {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		 }
         return Number ; 
       }
       static int ReadIntNumberBetween(int From, int To, string ErrorMessage = "Number is not within range, Enter again:\n")
       {
        int number = readIntNumber() ; 
        
        while (!isNumberBetween(number,From,To))
        {
            cout << ErrorMessage ; 
            number = readIntNumber() ;
        }
        return number ; 
       }
       static double readDblNumber(string ErrorMessage = "Invalid Number, Enter again\n")
       {
         double Number ;
         while (!(cin >> Number)) 
         {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << ErrorMessage;
		 }
         return Number ; 
       }
       static double ReadDblNumberBetween(double From, double To, string ErrorMessage = "Number is not within range, Enter again:\n")
       {
        double number = readDblNumber() ; 
        
        while (!isNumberBetween(number,From,To))
        {
            cout << ErrorMessage ; 
            number = readDblNumber() ;
        }
        return number ; 
       }
       static bool isValidateDate(clsDate date)
       {
         if(clsDate::IsValidDate(date))
         {
            cout << "Valid Date\n";
            return true ; 
         }
         else 
         {
            return false ; 
         }
       }
       static string ReadString()
	{
		string  S1="";
		// Usage of std::ws will extract allthe whitespace character
      
		getline(cin >> ws, S1);
		return S1;
	}
       
};