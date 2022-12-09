//
//  Date.cpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/6/22.
//

#include "Date.hpp"


Date::Date(int m, int d, int y)
:month(m),day(d),year(y)
{
}

Date::Date()
:month(1),day(1),year(1970)
{
  cout<<"Date not assigned. Default constructed"<<endl;
}

  
ostream& operator << (ostream &os, const Date &date)
{
  os << date.month << "/" << date.day << "/" << date.year << endl;
  return os;
}

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

Date& operator- (const Date& date, const Date& dateadded)
{
    int mnew, dnew, ynew;
  if (date.month>dateadded.month)
    {
    mnew=date.month-dateadded.month;
    }
  else
  {
    cout<<"Error: invalid month entry"<<endl;
    mnew=date.month;
  }
  if (date.day>dateadded.day | (date.day+dateadded.day)<=31)
    {
    dnew=date.day-dateadded.day;
    }
  else
  {
    cout<<"Error: invalid day entry"<<endl;
    dnew=date.day;
  }
  if (date.year>dateadded.year)
    {
    ynew=date.year-dateadded.year;
    }
  else
  {
    cout<<"Error: invalid year entry"<<endl;
    ynew=date.year;
  }
    
  Date newdate=Date(mnew, dnew, ynew);
  Date* retdate=&newdate;
  return *retdate;
}
