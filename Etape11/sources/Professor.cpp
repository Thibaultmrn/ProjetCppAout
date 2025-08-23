#include "Professor.h"
namespace planning
{

    Professor::Professor() : Schedulable() 
    {
        #ifdef DEBUG
        cout << ">>Professor: Constructeur par défaut <<" << endl;
        #endif

        setLastName("-----");
        setFirstName("----");
    }

    Professor::Professor(int i, const string &ln, const string &fn) : Schedulable(i) 
    {
        #ifdef DEBUG
        cout << ">>Professor: Constructeur d'initialisation <<" << endl;
        #endif

        setLastName(ln);
        setFirstName(fn);
    }
    Professor::Professor(const string &ln, const string &fn) : Schedulable() 
    {
        #ifdef DEBUG
        cout << ">>Professor: Constructeur d'initialisation <<" << endl;
        #endif

        setLastName(ln);
        setFirstName(fn);
    }
    Professor::Professor(const Professor &c) : Schedulable(c) 
    {
        #ifdef DEBUG
        cout << ">>Professor: Constructeur de copie <<" << endl;
        #endif

        setLastName(c.getLastName());
        setFirstName(c.getFirstName());
    }

    void Professor::setLastName(const string &ln)
    {
        lastName = ln;
    }

    void Professor::setFirstName(const string &fn)
    {
        firstName = fn;
    }

    string Professor::getLastName() const 
    {
        return lastName;
    }

    string Professor::getFirstName() const 
    {
        return firstName;
    }


    string Professor::toString()const 
    {
        return lastName + " " + firstName;
    }

    string Professor::tuple()const 
    {
        return to_string(id) + ";" + lastName + ";" + firstName;
    }

    Professor& Professor::operator=(const Professor& P) 
    {
        if (this != &P) 
        {
            Schedulable::operator=(P); 
            this->lastName = P.lastName;
            this->firstName = P.firstName;
        }

        return *this;
    }
    
    ostream& operator<<(ostream& s, const Professor& professor) 
    {
        s << "<Professor>" << endl;

        s << "<id>" << endl;
        s << professor.getId() << endl;
        s << "</id>" << endl;

        s << "<lastName>" << endl;
        s << professor.getLastName() << endl;
        s << "</lastName>" << endl;

        s << "<firstName>" << endl;
        s << professor.getFirstName() << endl;
        s << "</firstName>" << endl;

        s << "</Professor>";
        return s;
    }

    istream& operator>>(istream& s, Professor& professor) 
    {
        string tag, sId, sLastName, sFirstName;

        getline(s, tag); // <Professor>
        getline(s, tag); // <id>
        getline(s, sId);
        getline(s, tag); // </id>

        getline(s, tag); // <lastName>
        getline(s, sLastName);
        getline(s, tag); // </lastName>

        getline(s, tag); // <firstName>
        getline(s, sFirstName);
        getline(s, tag); // </firstName>

        getline(s, tag); // </Professor>

        professor.setId(stoi(sId));
        professor.setLastName(sLastName);
        professor.setFirstName(sFirstName);

        return s;
    }

    bool Professor::operator<(const Professor& other) const 
    {
        return this->getId() < other.getId(); // comparaison sur le id pour <set>
    }

}

