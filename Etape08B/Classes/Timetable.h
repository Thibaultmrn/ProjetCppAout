#ifndef TIMETABLE_H 
#define TIMETABLE_H 

#include <iostream>
#include <string>
using namespace std;
#include <set>
#include "Classroom.h"
#include "Professor.h"
#include "Group.h"
#include "Schedulable.h"

namespace planning {
class Timetable 
{ 
  private: 
    set<Classroom> classrooms; 
    set<Professor> professors; 
    set<Group>     groups; 

    static Timetable instance;
    Timetable();
    Timetable(const Timetable&) = delete;
    Timetable& operator=(const Timetable&) = delete;
  public: 
   ~Timetable(); 
    static Timetable& getInstance();

   int addClassroom(const string& name,int seatingCapacity); 
   void displayClassrooms() const; 
   Classroom findClassroomByIndex(int index) const; 
   Classroom findClassroomById(int id) const; 
   void deleteClassroomByIndex(int index); 
   void deleteClassroomById(int id); 
 
   int addProfessor(const string& lastName,const string& firstName); 
   void displayProfessors() const; 
   Professor findProfessorByIndex(int index) const; 
   Professor findProfessorById(int id) const; 
   void deleteProfessorByIndex(int index); 
   void deleteProfessorById(int id); 
 
   int addGroup(const string& name); 
   void displayGroups() const; 
   Group findGroupByIndex(int index) const; 
   Group findGroupById(int id) const; 
   void deleteGroupByIndex(int index); 
   void deleteGroupById(int id); 
}; 
}

#endif