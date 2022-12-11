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
  int days_until_due;
  char priority;
  bool is_complete;
  string classname, status, assignment_type;
public:
    int id_num;
  Assignment(Date todays_date);
  Assignment(Date todays_date, Date due_date, int assignment_type, string classname);
  virtual ~Assignment();
  Date GetDueDate() const;
  string GetAssignmentType() const;
  int GetDaysUntilDue() const;
  string GetClassName() const;
  void calcPriority();
  void markComplete();
  string showStatus() const;
  void setAssignmentID(int);
  friend ostream& operator << (ostream &os, const Assignment &assignment);
};
#endif /* Assignment_hpp */
