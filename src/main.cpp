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
        cout<<"Enter a command."<<endl<<"'a' to add assignment(s)"<<endl<<"'d' to delete an assignement"<<endl<< "'c' to mark an assignment as complete"<<endl<<"'s' search your current assignments"<<endl<<"'q' to quit"<<endl<<"Enter: ";
        cin>>in;
        
        switch (in)
        {
            case 'a':
            {
                cout<<"Enter number of assignments: ";
                cin>>num_assignments;
                OrganizeLife(list_of_assignments, current_date, num_assignments);
                break;
            }
            case 'd':
            {
                if (!list_of_assignments.empty())
                {
                    int d;
                    showlist(list_of_assignments);
                    cout<<"Which assignment would you like to delete?"<<endl;
                    cout<<"Enter Assignment ID: ";
                    cin>>d;
                    deleteAssignment(list_of_assignments, d);
                    /*printlist*/
                    showlist(list_of_assignments);
                }
                else
                    cout<<"Cannot delete any assignments because there are no assignments to delete."<<endl;
                break;
            }
            case 'c':
            {
                if (!list_of_assignments.empty())
                {
                    int c, del;
                    cout<<"Which assignment would you like to mark complete?"<<endl;
                    showlist(list_of_assignments);
                    cout<<"Enter Assignment ID: ";
                    cin>>c;
                    completeAssignment(list_of_assignments, c);
                    /*printlist*/
                    showlist(list_of_assignments);
                    cout<<"Marked Complete. Would you like to now delete this assignment? (y/n): ";
                    cin>>del;
                    if (del=='y')
                    {
                        deleteAssignment(list_of_assignments, c);
                    }
                    else
                        break;
                    
                }
                else
                    cout<<"Cannot mark complete because there are no assignments to mark complete."<<endl;
                break;
            }
            case 's':
            {
                list <Assignment> temp;
                int srch;
                cout<<"Choose what you would like to search for: "<<endl<<"Complete Assignments (1)"<<endl<<"Incomplete Assignments (2)"<<endl<<"Class Name (3)"<<endl<<"Assignment ID (4)"<<endl<<"Due Date(5)"<<endl<<"Enter: ";
                cin>>srch;
                    if (srch==1)
                    {
                        temp=searchListID(list_of_assignments);
                        showlist(temp);
                        break;
                    }
                    else if (srch==2)
                    {
                        temp=searchListDate(list_of_assignments);
                        showlist(temp);
                        break;
                    }
                    else if (srch==3)
                    {
                        temp=searchListComp(list_of_assignments);
                        showlist(temp);
                        break;
                    }
                    else if (srch==4)
                    {
                        temp=searchListIncomp(list_of_assignments);
                        showlist(temp);
                        break;
                    }
                    else if (srch==5)
                    {
                        temp=searchListName(list_of_assignments);
                        showlist(temp);
                        break;
                    }
                
            }
                        /*case 's':
                         saveToFile(list_of_assignments, filename);*/
                    case 'q':
                        char answer;
                        if (!list_of_assignments.empty())
                        {
                            cout<<"You still have uncompleted assignments remaining. Are you sure you want to quit? (y/n): ";
                            cin>>answer;
                            switch (answer)
                            {
                                case 'n':
                                    in='a';
                                    break;
                                default:
                                    cout<<"Quitting..."<<endl;
                                    break;
                            }
                        }
                        else
                            cout<<"Quitting..."<<endl;
                        break;
                    default:
                        cout<<"default...quitting"<<endl;
                        in='q';
                }
        }while (in!='q');
        
        return 0;
    }
