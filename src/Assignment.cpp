//
//  Assignment.cpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/10/22.
//

#include "Assignment.hpp"

/*Assignment Constructor 1*/
Assignment::Assignment(Date in_date)
:todays_date(in_date), is_complete(false)
{
    if (todays_date.year==due_date.year & todays_date.month==due_date.month)
        days_until_due=due_date.day-todays_date.day;
    else if (todays_date.year==due_date.year & todays_date.month<=due_date.month)
        days_until_due=((due_date.month-todays_date.month)*30)+(due_date.day-todays_date.day);
        
    
}
/*Assignment Constructor 2*/
Assignment::Assignment(Date in_date, Date out_date, int type)
:todays_date(in_date), due_date(out_date), assignment_type(type), is_complete(false)
{
    
}

/*Assignment Destructor*/
Assignment::~Assignment()
{
}
/*Assignment member function that calculates priority of the assignment*/
void Assignment::calcPriority()
{
    
}
/*Assignment member function that will mark the assignment as complete*/
void Assignment::markComplete()
{
    is_complete=true;
}
/*Assignment member function that returns whether or not the assignment is complete*/
bool Assignment::isComplete()
{
    return is_complete;
}

/*Assignment member function that returns due date of assignment*/
Date Assignment::GetDueDate()
{
    return due_date;
}
/*Returns assignment */
int Assignment::GetAssignmentType()
{
    if (assignment_type==1)
        cout<<"Homework"<<endl;
    else if (assignment_type==2)
        cout<<"Project"<<endl;
    else if (assignment_type==3)
        cout<<"Exam"<<endl;
    else if (assignment_type==4)
        cout<<"Other"<<endl;
    else
        cout<<"Thats weird...ERROR!"<<endl;
    return assignment_type;
}
