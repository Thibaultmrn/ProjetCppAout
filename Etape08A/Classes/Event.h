#ifndef EVENT
#define EVENT
#include<stdlib.h>
#include<string.h>
#include<iostream>
#include "Timing.h"
using namespace std;

namespace planning
{
    class Event{
        friend ostream& operator<<(ostream& s, const Event& timing);
        friend istream& operator>>(istream& s, Event& timing);
        
        private :
            int code;
            char *title;
            Timing *timing;

        public :
            Event();
            Event(int c, const char *t);
            Event(const Event &e);
            ~Event();

            void setCode(int c);
            void setTitle(const char *t);
            void setTiming(const Timing& t);
            
            int getCode() const;
            const char *getTitle() const;
            Timing getTiming() const;

            void display() const;
            string toString()const;
            static int currentCode;

    };
}
#endif