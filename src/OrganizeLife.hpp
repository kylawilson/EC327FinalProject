//
//  OrganizeLife.hpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/8/22.
//

#ifndef OrganizeLife_hpp
#define OrganizeLife_hpp

#include <stdio.h>
#include "Date.hpp"

class Assignment
{
private:
  Date due_date, todays_date;
  int assignment_type, days_until_due;
  char priority;
  bool is_complete;
public:
  Assignment(Date todays_date);
  Assignment(Date todays_date, Date due_date, int assignment_type);
  ~Assignment();
  void calcPriority();
  void markComplete();
  bool isComplete();
};

void OrganizeLife(Date, int);

#endif /* OrganizeLife_hpp */
