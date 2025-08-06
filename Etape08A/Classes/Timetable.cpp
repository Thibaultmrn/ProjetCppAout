#include "Timetable.h"

namespace planning {

Timetable::Timetable() 
{
    cout << "Timetable initialisé" << endl;
}

Timetable::~Timetable() 
{
     cout << "Timetable détruit" << endl;
}

int Timetable::addClassroom(const string& name, int seatingCapacity) 
{
    Classroom c(name, seatingCapacity);
    c.setId(Schedulable::getCurrentId());
    classrooms.insert(c);

    return c.getId();
}

void Timetable::displayClassrooms() const 
{
    for (const auto& c : classrooms) 
    {
        cout << c.toString() << endl;
    }
}

Classroom Timetable::findClassroomByIndex(int index) const 
{
    auto it = classrooms.begin();
    advance(it, index);
    return *it;
}

Classroom Timetable::findClassroomById(int id) const 
{
    for (const auto& c : classrooms) 
    {
        if (c.getId() == id) 
        {
            return c;
        }
    }
    return Classroom();
}

void Timetable::deleteClassroomByIndex(int index) 
{
    auto it = classrooms.begin();
    advance(it, index);
    classrooms.erase(it);
}

void Timetable::deleteClassroomById(int id) 
{
    auto it = classrooms.begin();
    while (it != classrooms.end()) 
    {
        if (it->getId() == id) 
        {
            classrooms.erase(it);
            return;
        }
        ++it;
    }
}

//----------------------------------------//PROFESSOR-----------------
int Timetable::addProfessor(const string& lastName, const string& firstName) 
{
    Professor p(lastName, firstName);
    int newId = Schedulable::getCurrentId();
    p.setId(newId);
    professors.insert(p);

    return newId;
}
void Timetable::displayProfessors() const 
{
    for (const auto& p : professors) 
    {
        cout << p.toString() << std::endl;
    }
}
Professor Timetable::findProfessorById(int id) const 
{
    for (const auto& p : professors) 
    {
        if (p.getId() == id) 
        {
            return p;
        }
    }
    return Professor(); // Retourne un objet par défaut si non trouvé
}
Professor Timetable::findProfessorByIndex(int index) const 
{
    auto it = professors.begin();
    std::advance(it, index);
    return *it;
}
void Timetable::deleteProfessorByIndex(int index) 
{
    auto it = professors.begin();
    advance(it, index);
    professors.erase(it);
}
void Timetable::deleteProfessorById(int id) 
{
    auto it = professors.begin();
    while (it != professors.end()) 
    {
        if (it->getId() == id) 
        {
            professors.erase(it);
            return;
        }
        ++it;
    }
}

//-------------groupe-----------------

int Timetable::addGroup(const string& name) 
{
    Group g(name);
    int newId = Schedulable::getCurrentId();
    g.setId(newId);
    groups.insert(g);

    return newId;
}
void Timetable::displayGroups() const 
{
    for (const auto& g : groups) 
    {
        cout << g.toString() << std::endl;
    }
}
Group Timetable::findGroupById(int id) const 
{
    for (const auto& g : groups) 
    {
        if (g.getId() == id) 
        {
            return g;
        }
    }
    return Group(); 
}
Group Timetable::findGroupByIndex(int index) const 
{
    auto it = groups.begin();
    std::advance(it, index);
    return *it;
}
void Timetable::deleteGroupByIndex(int index) 
{
    auto it = groups.begin();
    std::advance(it, index);
    groups.erase(it);
}

void Timetable::deleteGroupById(int id) 
{
    auto it = groups.begin();
    while (it != groups.end()) 
    {
        if (it->getId() == id) 
        {
            groups.erase(it);
            return;
        }
        ++it;
    }
}
}
