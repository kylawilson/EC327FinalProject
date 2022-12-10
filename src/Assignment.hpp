//
//  Assignment.hpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/10/22.
//

#ifndef Assignment_hpp
#define Assignment_hpp

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
  Date GetDueDate();
  int GetAssignmentType();
  void calcPriority();
  void markComplete();
  bool isComplete();
};
#endif /* Assignment_hpp */
