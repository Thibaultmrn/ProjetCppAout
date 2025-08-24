#ifndef GROUP_H 
#define GROUP_H 

#include <string>
#include "Schedulable.h"
#include <iostream>
using namespace std;

namespace planning
{
    class Group : public Schedulable 
    {
        friend ostream& operator<<(ostream&, const Group&);
        friend istream& operator>>(istream&, Group&);

        private:
            string name;

        public:
            Group();
            Group(int, const string&);
            Group(const string&);

            Group(const Group &);
            ~Group() = default;

            void setName(const string&);
            
            string getName() const;

            string toString()const override;
            string tuple()const override;

            Group& operator=(const Group&);

            /*J’ai ajouté operator< dans ma classe Group, car j’utilise un std::set<Group> dans Timetable. Le set étant un conteneur ordonné, il a besoin de comparer les objets qu’il contient. Sans operator<, le compilateur ne peut pas trier ou gérer les éléments dans le set.*/
            bool operator<(const Group& ) const ;
    };
}
#endif