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
    do{
        cout<<"Enter number of assignments: ";
        cin>>num_assignments;
    }while (num_assignments>100);
    
    /*create an array of assignment pointers*/
    Assignment* AssignmentArr[num_assignments];
    
    /*call the function to collect all assignment data and put into AssignmentArr*/
    OrganizeLife(AssignmentArr, current_date, num_assignments);
    
    /*test code - ignore*/
    /*cout<<AssignmentArr[0]->GetDueDate()<<endl;*/
    
    /*delete AssignmentArr from the heap*/
    for (int j=0;j<num_assignments;j++)
    {
        delete AssignmentArr[j];
    }
    
    return 0;
}

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
    int i;
    for(i = 0; i<argc; i++) {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}
