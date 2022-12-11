//
//  main.cpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/6/22.
//

#include <iostream>
#include <stdio.h>
#include "OrganizeLife.hpp"
#include <unistd.h>

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
    
    string filename="AssignmentSaveFile.rtf";
    
    /*create a list of assignments*/
    list <Assignment> list_of_assignments;
    /*get number of assignments*/
    int num_assignments;
    do{
        cout<<"Enter number of assignments: ";
        cin>>num_assignments;
    }while (num_assignments>100);
    /*call the function to collect all assignment data and put into list*/
    OrganizeLife(list_of_assignments, current_date, num_assignments);
    /*printlist*/
    showlist(list_of_assignments);
    
    char in;
    do{
        cout<<"Enter a command."<<endl<<"'a' to add assignment(s)"<<endl<<"'d' to delete an assignement"<<endl<< "'c' to mark an assignment as complete"<<endl<<"'x' to mark an assignment as complete and delete the assignment immediately"<<endl<<"'s' to save assignments to a file"<<endl<<"'q' to quit"<<endl<<"Enter: ";
        cin>>in;
        
        switch (in)
        {
            case 'a':
                cout<<"Enter number of assignments: ";
                cin>>num_assignments;
                OrganizeLife(list_of_assignments, current_date, num_assignments);
                break;
            case 'd':
                int d;
                showlist(list_of_assignments);
                cout<<"Which assignment would you like to delete?"<<endl;
                cout<<"Enter Assignment ID: ";
                cin>>d;
                deleteAssignment(list_of_assignments, d);
                /*printlist*/
                showlist(list_of_assignments);
                break;
            case 'c':
                int c;
                cout<<"Which assignment would you like to mark complete?"<<endl;
                showlist(list_of_assignments);
                cout<<"Enter Assignment ID: ";
                cin>>c;
                completeAssignment(list_of_assignments, c);
                /*printlist*/
                showlist(list_of_assignments);
                break;
            case 'x':
                int x;
                cout<<"Which assignment would you like to mark complete & delete?"<<endl;
                /*printlist*/
                showlist(list_of_assignments);
                cout<<"Enter Assignment ID: ";
                cin>>x;
                completeAssignment(list_of_assignments, x);
                deleteAssignment(list_of_assignments, x);
                /*printlist*/
                showlist(list_of_assignments);
                break;
            /*case 's':
                saveToFile(list_of_assignments, filename);*/
            default:
                cout<<"default...quitting"<<endl;
                in='q';
        }
    }while (in!='q');

    return 0;
}
