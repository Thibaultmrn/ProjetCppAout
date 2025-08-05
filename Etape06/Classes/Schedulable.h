#ifndef SCHEDULABLE
#define SCHEDULABLE
#include<stdlib.h>
#include<string>
#include<iostream>

using namespace std;

namespace planning
{
	class Schedulable
	{
		protected:
			int id;
		public:
			Schedulable();
			Schedulable(int id);
			Schedulable(const Schedulable& S);
			~Schedulable();

			void setId(int id);
			int getId() const;
			
			Schedulable& operator=(const Schedulable&);
			
			virtual string toString()const = 0;
			virtual string tuple()const = 0;
	};
}

#endif