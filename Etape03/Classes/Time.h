#ifndef TIME
#define TIME
#include <iostream>
using namespace std;
namespace planning
{
    class Time
    {
        friend Time operator+(const int t, const Time t1);
		friend Time operator+(const Time t1,const int t);
		friend Time operator+(const Time t1,const Time t2);
		friend Time operator-(const int t, const Time t1);
		friend Time operator-(const Time t1,const int t);
		friend Time operator-(const Time t1,const Time t2);
		friend istream& operator>> (istream& s, Time& t);
		friend ostream& operator<<(ostream& s, const Time& t);

        private :
            int hour;
            int minute;
			int compTime(const Time& t);
            
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

            Time& operator=(const Time& t);

			int operator<(const Time& t);
			int operator>(const Time& t);
			int operator==(const Time& t);

			Time operator++();
			Time operator++(int);
			Time operator--();
			Time operator--(int);

    };
}
#endif