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
public:
  int month, day, year;
  Date(int, int, int);
  Date();
  virtual ~Date();
  friend ostream& operator<<(ostream&os, const Date& date);
  friend Date& operator+(const Date& date, const Date& dateadded);
  friend Date& operator-(const Date& date, const Date& dateadded);
};

#endif /* Date_hpp */
