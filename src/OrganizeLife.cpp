//
//  OrganizeLife.cpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/8/22.
//

#include "OrganizeLife.hpp"

/*intakes assignments, creates objects for them and stores them all in an array of Assignment pointers, accessible from main*/
void OrganizeLife(list <Assignment> & list_of_assignments, Date current_date, int num_assignments)
{
    /*intake all assignmnets & their details, create assignment objects for each*/
  for (int i=0; i<num_assignments;i++)
  {
      int monthdue, daydue, yeardue, type;
      string classname;
      cout<<"Assignment "<<(list_of_assignments.size()+1)<<": "<<endl;
      cout<<"Enter due date; month (#): ";
      cin>>monthdue;
      cout<<"Enter due date; day (#): ";
      cin>>daydue;
      cout<<"Enter due date; year (#): ";
      cin>>yeardue;
      
      /*insert error-catching if the due date is before today's date*/
      cout<<"Enter class name: ";
      cin>>classname;
      Date duedate(monthdue, daydue, yeardue);
      cout<<"Assignment type..."<<endl;
      cout<<"1 for Homework"<<endl<<"2 for Project"<<endl<<"3 for exam/study"<<endl<<"4 for other..."<<endl;
      cout<<"Enter: ";
      cin>>type;
      list_of_assignments.push_back(Assignment(current_date,duedate,type,classname));
      /*Assignments[i]=new Assignment(current_date,duedate,type,classname);*/
  }
}

void showlist(list<Assignment> list_of_assignments)
{
    int count=1,
    total_work=0;
    for (list<Assignment>::iterator it=list_of_assignments.begin(); it != list_of_assignments.end(); ++it)
    {
        cout <<"Assignment "<<count<<"{"<<endl<<*it<<"}"<<endl;
        it->setAssignmentID(count);
        count++;
        total_work+=it->getHrsOfWork();
    }
    cout<<"Approximate Total Hours of Work: "<<total_work<<endl;
}

void deleteAssignment(list <Assignment> & list_of_assignments, int assignment_id)
{
    list<Assignment>::iterator it;
    it=list_of_assignments.begin();
    advance(it,(assignment_id-1));
    it=list_of_assignments.erase(it);
}

void completeAssignment(list <Assignment> & list_of_assignments, int assignment_id)
{
    list<Assignment>::iterator it;
    it=list_of_assignments.begin();
    advance(it,(assignment_id-1));
    it->markComplete();
    cout<<*it<<endl;
}

void saveToFile(list <Assignment> list_of_assignments, string filename)
{
    fstream file(filename);
    if (!file.good())
    {
        cout<<"file doesn't exist"<<endl;
    }
    for (list<Assignment>::iterator it=list_of_assignments.begin(); it != list_of_assignments.end(); ++it)
    {
        file<<*it<<endl;
    }
    file.close();
    
    string myText;
    ifstream MyReadFile(filename);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
      // Output the text from the file
      cout << myText;
    }
    // Close the file
    MyReadFile.close();
}

list <Assignment> searchListComp(list <Assignment> list_of_assignments)
{
    list<Assignment> retlist;
    list<Assignment>::iterator searchit=list_of_assignments.begin();
    while (searchit!=list_of_assignments.end())
    {
        if ((searchit->getStatus())=="Complete")
            retlist.push_back(*searchit);
        
    }
    return retlist;
}
list <Assignment> searchListIncomp(list <Assignment> list_of_assignments)
{
    list<Assignment> retlist;
    list<Assignment>::iterator searchit=list_of_assignments.begin();
    while (searchit!=list_of_assignments.end())
    {
        if ((searchit->getStatus())=="Incomplete")
            retlist.push_back(*searchit);
        
    }
    return retlist;
}
list <Assignment> searchListName(list <Assignment> list_of_assignments)
{
    string classnm;
    list<Assignment> retlist;
    list<Assignment>::iterator searchit=list_of_assignments.begin();
    cout<<"What class name are you looking for?: ";
    cin>>classnm;
    while (searchit!=list_of_assignments.end())
    {
        if ((searchit->GetClassName())==classnm)
            retlist.push_back(*searchit);
    }
    return retlist;
}

list <Assignment> searchListID(list <Assignment> list_of_assignments)
{
    int id;
    list<Assignment> retlist;
    list<Assignment>::iterator searchit=list_of_assignments.begin();
    cout<<"What Assignment ID are you searching for?: ";
    cin>>id;
    while (searchit!=list_of_assignments.end())
    {
        if (searchit->id_num==id)
            retlist.push_back(*searchit);
    }
    return retlist;
}
list <Assignment> searchListDate(list <Assignment> list_of_assignments)
{
    int m, d, y;
    list<Assignment> retlist;
    list<Assignment>::iterator searchit=list_of_assignments.begin();
    cout<<"What Due Date are you searching for?"<<endl<<"Month (#): ";
    cin>>m;
    cout<<"Day (#): ";
    cin>>d;
    cout<<"Year (#): ";
    cin>>y;
    Date compdate(m,d,y);
    while (searchit!=list_of_assignments.end())
    {
        if ((searchit->GetDueDate())==compdate)
            retlist.push_back(*searchit);
    }
    return retlist;
}
