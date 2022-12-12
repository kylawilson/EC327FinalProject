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
    if (todays_date.getYear()==due_date.getYear() & todays_date.getMonth()==due_date.getMonth())
        days_until_due=due_date.getDay()-todays_date.getDay();
    else if (todays_date.getYear()==due_date.getYear() & todays_date.getMonth()<=due_date.getMonth())
        days_until_due=((due_date.getMonth()-todays_date.getMonth())*30)+(due_date.getDay()-todays_date.getDay());
        
    
}
/*Assignment Constructor 2*/
Assignment::Assignment(Date in_date, Date out_date, int type, string classnm)
:todays_date(in_date), due_date(out_date), is_complete(false), classname(classnm)
{
    days_until_due=due_date.getDay()-todays_date.getDay();
    months_until_due=due_date.getMonth()-todays_date.getMonth();
    years_until_due=due_date.getYear()-todays_date.getYear();
        if ((due_date.getYear())<(todays_date.getYear()))
        {
            cout<<"Past date entered..."<<endl;
            throw(1);
            
        }
        if ((due_date.getYear())==(todays_date.getYear()))
        {
            if ((due_date.getMonth())<(todays_date.getMonth()))
            {
                cout<<"Past date entered..."<<endl;
                throw(1);
            }
            else if (((due_date.getMonth())==(todays_date.getMonth())) & ((due_date.getDay())<(todays_date.getDay())))
            {
                cout<<"Past date entered..."<<endl;
                throw(1);
            }
        }
    if (days_until_due<0)
    {
        days_until_due=31+days_until_due;
    }
    if ((months_until_due<0) & (years_until_due==1))
        years_until_due=0;
    if (months_until_due<0)
        months_until_due=12+months_until_due;
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
/*Assignment member function that returns days until assignment is due*/
int Assignment::GetMonthsUntilDue() const
{
    return months_until_due;
    
}
/*Assignment member function that returns days until assignment is due*/
int Assignment::GetYearsUntilDue() const
{
    return years_until_due;
    
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
  os << "Class: "<<assignment.GetClassName()<<endl<<"Due Date: "<< assignment.GetDueDate() << "Assignment Type: " << assignment.GetAssignmentType() << endl << "Days Until Due: "<< assignment.GetDaysUntilDue() << endl<< "Months Until Due: "<< assignment.GetMonthsUntilDue() << endl <<"Years Until Due: "<<assignment.GetYearsUntilDue()<<endl<< "Status: " << assignment.getStatus() << endl;
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
