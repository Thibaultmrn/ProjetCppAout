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
		private:
			string day;
			Time start;
			Time duration;
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
			static const string MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATERDAY, SUNDAY ;
	};	
}

#endif