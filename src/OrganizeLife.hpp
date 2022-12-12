//
//  OrganizeLife.hpp
//  EC327Project
//
//  Created by Kyla Wilson on 12/8/22.
//

#ifndef OrganizeLife_hpp
#define OrganizeLife_hpp

#include <stdio.h>
#include "Assignment.hpp"
#include <list>
#include <fstream>

void OrganizeLife(list <Assignment> & list_of_assignments,Date, int);
void showlist(list<Assignment> list_of_assignments);
void deleteAssignment(list <Assignment> & list_of_assignments, int assignment_id);
void completeAssignment(list <Assignment> & list_of_assignments, int assignment_id);
void saveToFile(list <Assignment> list_of_assignments, string filename);
void searchList(list <Assignment> list_of_assignments);
list<Assignment> searchListComp(list <Assignment> list_of_assignments);
list<Assignment> searchListIncomp(list <Assignment> list_of_assignments);
list<Assignment> searchListIncomp(list <Assignment> list_of_assignments);
list<Assignment> searchListID(list <Assignment> list_of_assignments);
list<Assignment> searchListDate(list <Assignment> list_of_assignments);
list<Assignment> searchListName(list <Assignment> list_of_assignments);
Date getCurrentDate();

#endif /* OrganizeLife_hpp */
