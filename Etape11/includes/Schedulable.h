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
			static int currentId;
			
		public:
			Schedulable();
			Schedulable(int id);
			Schedulable(const Schedulable& S);
			~Schedulable();

			void setId(int id);
			static void setCurrentId(int);

			int getId() const;
			static int getCurrentId();

			Schedulable& operator=(const Schedulable&);
			
			virtual string toString()const = 0;
			virtual string tuple()const = 0;
	};
}

#endif