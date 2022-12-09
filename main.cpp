//
//  main.cpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/6/22.
//

#include <iostream>
#include "OrganizeLife.hpp"
using namespace std;

int main() {
    /* get current date and print*/
    time_t now=time(0);
    struct tm* localtm=localtime(&now);
    int current_year=1900+localtm->tm_year;
    int current_month=1+localtm->tm_mon;
    int current_day=localtm->tm_mday;
    Date current_date(current_month,current_day,current_year);
    cout<<current_date<<endl;
    
    /*get number of assignments*/
    int num_assignments;
    cout<<"Enter number of assignments: ";
    cin>>num_assignments;
    
    Assignment* AssignmentArr[num_assignments];
    OrganizeLife(current_date, num_assignments);
    
    return 0;
}
