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
Assignment::Assignment(Date in_date, Date out_date, int type, string classnm)
:todays_date(in_date), due_date(out_date), is_complete(false), classname(classnm)
{
    Date time_till_due=out_date-in_date;
    cout<<time_till_due;
    days_until_due=time_till_due.day+((time_till_due.month)*30)+((time_till_due.year)*365);
    if (is_complete==true)
        status="Complete";
    else
        status="Incomplete";
    if (type==1){
        assignment_type="Homework";
        hours_of_work=1;
    }
    else if (type==2){
        assignment_type="Project";
        hours_of_work=5;
    }
    else if (type==3){
        assignment_type="Exam";
        hours_of_work=10;
    }
    else if (type==4){
        assignment_type="Other";
        cout<<"Enter approximate hours of work (whole #): ";
        cin>>hours_of_work;
    }
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
    status="Complete";
    hours_of_work=0;
}
/*Assignment member function that returns whether or not the assignment is complete*/
string Assignment::getStatus() const
{
    return status;
}

/*Assignment member function that returns due date of assignment*/
Date Assignment::GetDueDate() const
{
    return due_date;
}

/*Assignment member function that returns days until assignment is due*/
int Assignment::GetDaysUntilDue() const
{
    return days_until_due;
    
}
/*Returns assignment */
string Assignment::GetAssignmentType() const
{
    return assignment_type;
}

string Assignment::GetClassName() const
{
    return classname;
}

ostream& operator << (ostream &os, const Assignment& assignment)
{
  os << "Class: "<<assignment.GetClassName()<<endl<<"Due Date: "<< assignment.GetDueDate() << "Assignment Type: " << assignment.GetAssignmentType() << endl << "Days Until Due: "<< assignment.GetDaysUntilDue() << endl << "Status: " << assignment.getStatus() << endl;
  return os;
}

void Assignment::setAssignmentID(int id)
{
    id_num=id;
}

int Assignment::getHrsOfWork()
{
    return hours_of_work;
}
