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

bool testOrganizeLife();

int main() {
    
    string filename="assignmentSaveFile.txt";
    Date current_date;
    
    /*get todays date & display*/
    current_date=getCurrentDate();
    cout<<current_date<<endl;
    
    /*create a list of assignments*/
    list <Assignment> list_of_assignments;
    
    /*get initial number of assignments, up to 100*/
    int num_assignments;
    do{
        cout<<"Enter initial number of assignments: ";
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
        
        /*begin switch statement*/
        switch (in)
        {
            case 'a':
            {
                cout<<"Enter number of assignments: ";
                cin>>num_assignments;
                OrganizeLife(list_of_assignments, current_date, num_assignments);
                showlist(list_of_assignments);
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
                    break;
                }
                else
                {
                    cout<<"Cannot delete any assignments because there are no assignments to delete."<<endl;
                    break;
                }
            }
            case 'c':
            {
                if (!list_of_assignments.empty())
                {
                    int c;
                    cout<<"Which assignment would you like to mark complete?"<<endl;
                    showlist(list_of_assignments);
                    cout<<"Enter Assignment ID: ";
                    cin>>c;
                    completeAssignment(list_of_assignments, c);
                    /*printlist*/
                    showlist(list_of_assignments);
                    cout<<"Marked Complete. Now Deleting...: "<<endl;
                    deleteAssignment(list_of_assignments, c);
                    break;
                }
                else
                {
                    cout<<"Cannot mark complete because there are no assignments to mark complete."<<endl;
                    break;
                }
            }
            case 's':
            {
                if (!list_of_assignments.empty())
                {
                    searchList(list_of_assignments);
                    break;
                }
                else
                {
                    cout<<"Cannot search because there are no assignments to search through."<<endl;
                    break;
                }
            }
            case 'f':
            {
                saveToFile(list_of_assignments, filename);
                break;
            }
            case 'q':
            {
                char answer;
                if (!list_of_assignments.empty())
                {
                    cout<<"You still have uncompleted assignments remaining. Are you sure you want to quit? (y/n): ";
                    cin>>answer;
                    if (answer=='n')
                    {
                        in='a';
                        break;
                    }
                    else
                    {
                        cout<<"Quitting..."<<endl;
                        break;
                    }
                }
                else
                {
                    cout<<"Quitting..."<<endl;
                    break;
                }
            }
            default:
            {
                cout<<"default...quitting"<<endl;
                in='q';
            }
        }
        
    }while (in!='q');
    return 0;
}



/*include test case definitions*/
/*bool testOrganizeLife()
 {
 list<Assignment> l_o_c;
 Date today=getCurrentDate();
 int num=1;
 OrganizeLife(l_o_c,today,num);
 if (l_o_c==)
 cout<<"OrganizeLife function passed.";
 return true;
 }*/
 
