#include "Group.h"
namespace planning 
{
    Group::Group():Schedulable()
    {
        #ifdef DEBUG
        cout<< ">>Group: Constructeur par défaut <<" << endl;
        #endif

        setName("----");
    }

    Group::Group(int n,const string& m):Schedulable(n)
    {
        #ifdef DEBUG
        cout<< ">>Group: Constructeur d'initialisation <<" << endl;
        #endif

        setName(m);

    }

	Group::Group(const string& m):Schedulable()
	{
		#ifdef DEBUG
        cout<< ">>Group: Constructeur d'initialisation <<" << endl;
        #endif

        setName(m);

	}

    Group::Group(const Group& c):Schedulable(c)
    {
        #ifdef DEBUG
        cout<< ">>Group: Constructeur de copie <<" << endl;
        #endif

        setName(c.getName());

    }

    void Group::setName(const string& c)
    {
        this->name=c;
    }

    string Group::getName()const
    {
        return this->name;
    }

    string Group::toString()const 
    {
        return name;
    }

    string Group::tuple()const 
    {
        return to_string(id) + ";" + name;
    }

    Group& Group::operator=(const Group& G) 
    {
        if (this != &G) 
        {
            Schedulable::operator=(G); 
            this->name = G.name;
        }

        return *this;
    }
    ostream& operator<<(ostream& os, const Group& s) 
    {
        os << s.toString();
        return os;
    }

    bool Group::operator<(const Group& other) const 
    {
        return this->getId() < other.getId(); // comparaison sur le nom pour <set>
    }
}