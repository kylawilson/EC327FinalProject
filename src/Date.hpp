//
//  Date.hpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/6/22.
//

#ifndef Date_hpp
#define Date_hpp

#include <stdio.h>
#include <iostream>
using namespace std;

class Date
{
private:
    /*onitialize private member variables*/
    int month, day, year;
public:
    /*constructor*/
    Date(int, int, int);
    /*default constructor*/
    Date();
    /*destructor*/
    virtual ~Date();
    /*getter functions*/
    int getMonth();
    int getDay();
    int getYear();
    /*overloaded operators*/
    friend ostream& operator<<(ostream&os, const Date& date);
    friend Date& operator+(const Date& date, const Date& dateadded);
    friend Date& operator-(const Date& date, const Date& dateadded);
    friend bool operator==(const Date& date, const Date& dateadded);
    friend bool operator!=(const Date& date, const Date& dateadded);
};

#endif /* Date_hpp */
