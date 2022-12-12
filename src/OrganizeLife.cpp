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
      /*collect due date for assignment*/
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
      try
      {
          list_of_assignments.push_back(Assignment(current_date,duedate,type,classname));
      }
      catch (int e)
      {
          cout<<"Error in constructing assignment object"<<endl;
      }
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
    ofstream file;
    file.open(filename);
    if (file.is_open())
    {
        for (list<Assignment>::iterator it=list_of_assignments.begin(); it != list_of_assignments.end(); ++it)
        {
            file<<*it<<endl;
        }
    }
    file.close();
    /* check to see if the file was propely saved*/
    /*string myText;
    ifstream MyReadFile(filename);

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {
      // Output the text from the file
      cout << myText;
    }
    // Close the file
    MyReadFile.close();*/
}
void searchList(list <Assignment> list_of_assignments)
{
    list <Assignment> temp;
    int srch;
    cout<<"Choose what you would like to search for: "<<endl<<"Complete Assignments (1)"<<endl<<"Incomplete Assignments (2)"<<endl<<"Class Name (3)"<<endl<<"Assignment ID (4)"<<endl<<"Due Date (5)"<<endl<<"Enter: ";
    cin>>srch;
    if (srch==4)
    {
        showlist(searchListID(list_of_assignments));
    }
    else if (srch==5)
    {
        temp=searchListDate(list_of_assignments);
        showlist(temp);
    }
    else if (srch==1)
    {
        temp=searchListComp(list_of_assignments);
        showlist(temp);
    }
    else if (srch==2)
    {
        temp=searchListIncomp(list_of_assignments);
        showlist(temp);
    }
    else if (srch==3)
    {
        temp=searchListName(list_of_assignments);
        showlist(temp);
    }
}
list <Assignment> searchListComp(list <Assignment> list_of_assignments)
{
    list<Assignment>::iterator searchit=list_of_assignments.begin();
    while (searchit!=list_of_assignments.end())
    {
        if ((searchit->getStatus())!="Complete")
        {
            searchit=list_of_assignments.erase(searchit);
        }
    }
    return list_of_assignments;
}
list <Assignment> searchListIncomp(list <Assignment> list_of_assignments)
{
    list<Assignment>::iterator searchit=list_of_assignments.begin();
    while (searchit!=list_of_assignments.end())
    {
        if ((searchit->getStatus())!="Incomplete")
            searchit=list_of_assignments.erase(searchit);
    }
    return list_of_assignments;
}
list <Assignment> searchListName(list <Assignment> list_of_assignments)
{
    string classnm;
    list<Assignment>::iterator searchit=list_of_assignments.begin();
    cout<<"What class name are you looking for?: ";
    cin>>classnm;
    while (searchit!=list_of_assignments.end())
    {
        if ((searchit->GetClassName())!=classnm)
            searchit=list_of_assignments.erase(searchit);
    }
    return list_of_assignments;
}

list <Assignment> searchListID(list <Assignment> list_of_assignments)
{
    int id;
    list<Assignment>::iterator searchit=list_of_assignments.begin();
    cout<<"What Assignment ID are you searching for?: ";
    cin>>id;
    while (searchit!=list_of_assignments.end())
    {
        if (searchit->id_num!=id)
            searchit=list_of_assignments.erase(searchit);
    }
    return list_of_assignments;
}
list <Assignment> searchListDate(list <Assignment> list_of_assignments)
{
    int m, d, y;
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
        if ((searchit->GetDueDate())!=compdate)
            searchit=list_of_assignments.erase(searchit);
    }
    return list_of_assignments;
}

Date getCurrentDate()
{
    /* get current date and print*/
    time_t now=time(0);
    struct tm* localtm=localtime(&now);
    int current_year=1900+localtm->tm_year;
    int current_month=1+localtm->tm_mon;
    int current_day=localtm->tm_mday;
    Date current_date(current_month,current_day,current_year);
    return current_date;
}
