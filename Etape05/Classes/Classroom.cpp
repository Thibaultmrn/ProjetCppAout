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

ostream& operator<<(ostream& os, const Classroom& s)  {
    os << s.toString();
    return os;
}