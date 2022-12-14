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
  int days_until_due, months_until_due, years_until_due, hours_of_work;
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
  int GetMonthsUntilDue() const;
  int GetYearsUntilDue() const;
  string GetClassName() const;
  void calcPriority();
  void markComplete();
  string getStatus() const;
  void setAssignmentID(int);
  int getHrsOfWork() const;
  Date getTodaysDate() const;
  friend ostream& operator << (ostream &os, const Assignment &assignment);
  friend bool operator==(const Assignment& asmnt, const Assignment& asmnt1);
};
#endif /* Assignment_hpp */
