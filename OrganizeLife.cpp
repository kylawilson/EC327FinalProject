//
//  OrganizeLife.cpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/8/22.
//

#include "OrganizeLife.hpp"

void OrganizeLife(Date current_date, int num_assignments)
{
    /*intake all assignmnets & their details, create assignment objects for each*/
  for (int i=0; i<num_assignments;i++)
  {
      int monthdue, daydue, yeardue, type;
      cout<<"Assignment "<<(i+1)<<": "<<endl;
      cout<<"Enter due date; month (#): ";
      cin>>monthdue;
      cout<<"Enter due date; day (#): ";
      cin>>daydue;
      cout<<"Enter due date; year (#): ";
      cin>>yeardue;
      Date duedate(monthdue, daydue, yeardue);
      cout<<"Assignment type..."<<endl;
      cout<<"1 for Homework"<<endl<<"2 for Project"<<endl<<"3 for exam/study"<<endl;
      cout<<"Enter: ";
      cin>>type;
      Assignment* AssignmentArr[num_assignments];
      AssignmentArr[i]=new Assignment(current_date,duedate,type);
  }
}

Assignment::Assignment(Date in_date)
:todays_date(in_date), is_complete(false)
{
    
}
Assignment::Assignment(Date in_date, Date out_date, int type)
:todays_date(in_date), due_date(out_date), assignment_type(type), is_complete(false)
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

Assignment::~Assignment()
{
    
}
