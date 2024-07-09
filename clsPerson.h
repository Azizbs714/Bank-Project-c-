#pragma once
#include <iostream>
#include <string>

using namespace std ; 

class   clsPerson
{
    string firstName ;
    string LastName ; 
    string email ; 
    string phone ; 
  public:
    clsPerson(string firstName,string LastName , string email , string phone)
    {
       this->firstName = firstName ; 
       this->LastName  = LastName  ; 
       this->email     = email     ; 
       this->phone     = phone     ; 
    }
    void setFirstName(string fName) 
    {
        firstName = fName ; 
    }
    string getFirstName()
    {
        return firstName ; 
    }
     void setLastName(string lName) 
    {
        LastName = lName ; 
    }
    string getLastName()
    {
        return LastName ; 
    }
    string FullName()
    {
        return firstName + " " + LastName;
    }
     void setEamil(string Email) 
    {
        email = Email ; 
    }
    string getEamil()
    {
        return email ; 
    }
     void setPhone(string Phone) 
    {
        phone = Phone ; 
    }
    string getPhone()
    {
        return phone ; 
    }
    
};