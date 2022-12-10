//
//  OrganizeLife.cpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/8/22.
//

#include "OrganizeLife.hpp"

/*intakes assignments, creates objects for them and stores them all in an array of Assignment pointers, accessible from main*/
void OrganizeLife(Assignment* Assignments[], Date current_date, int num_assignments)
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
      
      /*insert error-catching if the due date is before today's date*/
      
      Date duedate(monthdue, daydue, yeardue);
      cout<<"Assignment type..."<<endl;
      cout<<"1 for Homework"<<endl<<"2 for Project"<<endl<<"3 for exam/study"<<"4 for other..."<<endl;
      cout<<"Enter: ";
      cin>>type;
      Assignments[i]=new Assignment(current_date,duedate,type);
  }
}
