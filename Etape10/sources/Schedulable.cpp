#include "Schedulable.h"
#include <iostream>
using namespace std;

namespace planning
{

    int Schedulable::currentId = 1;
    Schedulable::Schedulable() 
    {
        #ifdef DEBUG
        cout << ">>Schedulable: Constructeur par defaut <<" << endl;
        #endif
        setId(0);
    }

    Schedulable::Schedulable(int c) 
    {
        #ifdef DEBUG
        cout << ">>Schedulable: Constructeur d'initialisation <<" << endl;
        #endif
        setId(c);
    }

    Schedulable::Schedulable(const Schedulable& c) 
    {
        #ifdef DEBUG
        cout << ">>Schedulable: Constructeur de copie <<" << endl;
        #endif
        setId(c.getId());
    }

    Schedulable::~Schedulable() 
    {
        #ifdef DEBUG
        cout << ">>Schedulable: destructeur <<" << endl;
        #endif
    }

    void Schedulable::setId(int i) 
    {
        this->id = i;
    }

    void Schedulable::setCurrentId(int newId) 
    {
        currentId = newId;
    }
    
    int Schedulable::getId() const 
    {
        return this->id;
    }

    int Schedulable::getCurrentId()
    {
        return currentId++;
    }

    Schedulable& Schedulable::operator=(const Schedulable &S) 
    {

    setId(S.getId());
    return (*this);
    }
}