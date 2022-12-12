//
//  Date.cpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/6/22.
//

#include "Date.hpp"

int Date::getMonth()
{
    return month;
}
int Date::getDay()
{
    return day;
}
int Date::getYear()
{
    return year;
}

/*Date constructor*/
Date::Date(int m, int d, int y)
{
    if (m<0 |m>12)
        month=1;
    else
        month=m;
    if (d<0 |d>31)
        day=1;
    else
        day=d;
    if (y<2022)
        year=2023;
    else
        year=y;
}

/* default Date constructor*/
Date::Date()
:month(1),day(1),year(1970)
{
}

/*Date destructor*/
Date::~Date(){
}

/*Overload << operator for Date class*/
ostream& operator << (ostream &os, const Date &date)
{
  os << date.month << "/" << date.day << "/" << date.year << endl;
  return os;
}

/*Overload + operator for date class*/
Date& operator+ (const Date& date, const Date& dateadded)
{
    int mnew, dnew, ynew;
    if (date.month+dateadded.month>0 & date.month+dateadded.month<13)
    {
        mnew=date.month+dateadded.month;
    }
  else
    cout<<"Error: invalid month entry"<<endl;
    mnew=date.month;
  if (((date.day+dateadded.day)<=31) & (date.day+dateadded.day>0))
    {
    dnew=date.day+dateadded.day;
    }
  else
    cout<<"Error: invalid day entry"<<endl;
    dnew=date.day;
  if (date.year+dateadded.year>0)
    {
    ynew=date.year+dateadded.year;
    }
  else
    cout<<"Error: invalid year entry"<<endl;
    ynew=date.year;
    
  Date newdate=Date(mnew, dnew, ynew);
  Date* retdate=&newdate;
  return *retdate;
}

/*Overload - operator for Date class*/
Date& operator-(const Date& date, const Date& dateadded)
{
  int mnew, dnew, ynew;
    mnew=(date.month)-(dateadded.month);
    dnew=(date.day)-(dateadded.day);
    ynew=(date.year)-(dateadded.year);
    /*
  if (date.month>dateadded.month)
    {
    mnew=date.month-dateadded.month;
    }
  else
  {
    mnew=0;
  }
  if (date.day>dateadded.day | (date.day+dateadded.day)<=31)
    {
    dnew=date.day-dateadded.day;
    }
  else
  {
    dnew=0;
  }
  if (date.year>dateadded.year)
    {
    ynew=date.year-dateadded.year;
    }
  else
  {
    ynew=0;
  }
    */
  Date newdate(mnew, dnew, ynew);
  Date* retdate=&newdate;
  return *retdate;
}

/*Overload == opertaor for Date class*/
bool operator==(const Date& date, const Date& dateadded)
{
    if (((date.month==dateadded.month) & (date.day==dateadded.day)) & (date.year==dateadded.year))
        return true;
    else
        return false;
}
