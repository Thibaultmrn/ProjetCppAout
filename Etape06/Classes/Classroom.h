#ifndef CLASSROOM_H 
#define CLASSROOM_H 

#include <iostream>
#include <string>
#include "Schedulable.h"
using namespace std;
using namespace planning;


class Classroom : public Schedulable 
{
    friend ostream& operator<<(ostream& s, const Classroom& c);
    friend istream& operator>> (istream& s, Classroom& c);

    private:
        int seatingCapacity;
        string name;

    public:
        Classroom();
        Classroom(int,const string&,int);
        Classroom(const Classroom &);
        ~Classroom() = default;

        void setSeatingCapacity(int);
        void setName(const string&);
        
        
        int getSeatingCapacity() const; 
        string getName() const;
        

        string toString()const override;
        string tuple()const override;

        Classroom& operator=(const Classroom&);
};


#endif