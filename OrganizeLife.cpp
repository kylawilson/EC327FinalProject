//
//  OrganizeLife.cpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/8/22.
//

#include "OrganizeLife.hpp"
#include "Date.hpp"

void OrganizeLife(int num_assignments)
{
  for (int i=0; i<num_assignments;i++)
    {
      int monthdue, daydue, yeardue;
      cout<<"Enter due date; month (#):";
      cin>>monthdue;
      cout<<"Enter due date; day (#):";
      cin>>daydue;
      cout<<"Enter due date; year (#):";
      cin>>yeardue;
    }
}

Assignment::Assignment(Date in_date)
:todays_date(in_date)
{
    
}
Assignment::Assignment(Date in_date, Date out_date, int type)
:todays_date(in_date), due_date(out_date), assignment_type(type)
{
    
}
void Assignment::calcPriority()
{
    
}
void Assignment::markComplete()
{
    
}
bool Assignment::isComplete()
{
    return is_complete;
}
