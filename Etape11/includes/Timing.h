#ifndef TIMING
#define TIMING
#include <iostream>
#include <string.h>
using namespace std;
#include "Time.h"

namespace planning
{
	class Timing
	{
		friend istream& operator>> (istream& s, Timing& t);
		friend ostream& operator<<(ostream& s, const Timing& t);
		
		private:
			string day;
			Time start;
			Time duration;
			int compT(const Timing& t);

		public:
			

			Timing();
			Timing(const string& d, const Time& s, const Time& du);
			Timing(const Timing &t);
			~Timing();

			void setDay(const string& d);
			void setStart(const Time& s);
			void setDuration(const Time& du);

			string getDay() const;
			Time getStart() const;
			Time getDuration() const;

			void display() const;
			string toString() const;
			static const string MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATERDAY, SUNDAY ;

			int operator<(const Timing& t);
			int operator>(const Timing& t);
			int operator==(const Timing& t);

			bool intersect(const Timing& t) const ;
	};	
}

#endif