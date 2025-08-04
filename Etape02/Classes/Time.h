#ifndef TIME
#define TIME
#include <iostream>
using namespace std;
namespace planning
{
    class Time
    {
        private :
            int hour;
            int minute;

        public:
			Time(); 
			Time(int h, int m); 
			Time(int m);//constr init duree
			Time(const Time &t); 
			~Time(); 

            void setHour(int h);
            void setMinute(int m);
            int getHour() const;
            int getMinute() const;
            void display() const;
    };
}
#endif