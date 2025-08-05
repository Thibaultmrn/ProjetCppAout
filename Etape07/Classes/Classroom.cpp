#include "Classroom.h"
using namespace planning;

Classroom::Classroom():Schedulable() {
	#ifdef DEBUG
    cout<< ">>Classroom: Constructeur par défaut <<" << endl;
    #endif

    setSeatingCapacity(0);
    setName("----");
    
}

Classroom::Classroom(int n, const string& name,int seat):Schedulable(n) {
	#ifdef DEBUG
    cout<< ">>Classroom: Constructeur d'initialisation <<" << endl;
    #endif

    setName(name);
    setSeatingCapacity(seat);
    

}

Classroom::Classroom(const Classroom& c):Schedulable(c) {
	#ifdef DEBUG
    cout<< ">>Classroom: Constructeur de copie <<" << endl;
    #endif

    setName(c.getName());
    setSeatingCapacity(c.getSeatingCapacity());
}


void Classroom::setName(const string& name) {
	this->name=name;
}

void Classroom::setSeatingCapacity(int seat) {
	this->seatingCapacity=seat;
}

string Classroom::getName() const {
	return this->name;
}

int Classroom::getSeatingCapacity() const {
	return this->seatingCapacity;
} 


string Classroom::toString()const  {
    return name + "(" + to_string(seatingCapacity) + ")";
}

string Classroom::tuple()const  {
    return to_string(id) +";"+ name + "(" + to_string(seatingCapacity) + ")";
}

Classroom& Classroom::operator=(const Classroom& C)  {
    if (this != &C) 
    {
	    Schedulable::operator=(C); 
	    this->seatingCapacity = C.seatingCapacity;
	    this->name = C.name;
    }

	return *this;
}

ostream& operator<<(ostream& s, const Classroom& c)
{
    s <<"<Classroom>" << endl;
    s <<"<id>" << endl;
    s << c.id << endl;
    s <<"</id>" << endl;
    s <<"<name>" << endl;
    s << c.name << endl;
    s <<"</name>" << endl;
    s <<"<seatingCapacity>" << endl;
    s <<c.seatingCapacity << endl;
    s <<"</seatingCapacity>" << endl;
    s <<"</Classroom>";

    return s;
}

istream& operator>> (istream& s, Classroom& c)
{
    string sId, sName, sSetSeatingCapacity, tag;
    getline(s, tag);//<classroom>
    getline(s, tag);//<id>
    getline(s, sId);
    getline(s, tag);//</id>
    getline(s, tag);//<name>
    getline(s, sName);
    getline(s, tag);//</name>
    getline(s, tag);//<seatingCapacity>
    getline(s, sSetSeatingCapacity);
    getline(s, tag);//</seatingCapacity>
    getline(s, tag);//</classroom>

    c.setId(stoi(sId));
    c.setName(sName);
    c.setSeatingCapacity(stoi(sSetSeatingCapacity));

    return s; 
}