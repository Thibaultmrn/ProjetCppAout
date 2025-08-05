#include "TimeException.h"
#include <iostream>
#include <string.h>
#include "Time.h"
using namespace std;

namespace planning
{
    Time::Time(){
		#ifdef DEBUG
		cout << ">>> Time : constructeur par défaut <<<" << endl;
		#endif
		hour = 0;
		minute = 0;        
    }

    Time::Time(int h, int m){
		#ifdef DEBUG
		cout << ">>> Time: constructeur d'initialisation heure <<<" << endl;
		#endif
		hour = h;
		minute = m;
	}

    Time::Time(int m){
		#ifdef DEBUG
		cout << ">>> Time: constructeur d'initialisation duree <<<" << endl;
		#endif
		if(m<0 || m>1440) 
    		throw TimeException("HEURE HORS DE L'INTERVALLE 00H-23h59",TimeException::OVERFLOW);
 
		hour = m / 60;
		minute = m % 60;
	}

    Time::Time(const Time &t){
		#ifdef DEBUG
		cout << ">>> Time : constructeur de copie <<<" << endl;
		#endif
		setHour(t.getHour());
		setMinute(t.getMinute());
	}

 	Time::~Time(){ 
		#ifdef DEBUG
		cout << ">>> Time : destructeur <<<" << endl;
		#endif
	} 

	int Time::getHour() const {
		return hour;
	}

	int Time::getMinute() const {
		return minute;
	}

	void Time::setHour(int h) {
		if (h < 0||h > 23) 
			throw TimeException("Heure invalide !(doit être entre 0 et 23)",TimeException::INVALID_HOUR);
		
		hour = h;
	}

	void Time::setMinute(int m) {
		if (m < 0 || m > 59) 
			throw TimeException("Minutes invalides (doivent être entre 0 et 59)", TimeException::INVALID_MINUTE);

		minute = m;
	}
    
	void Time::display() const {
		if(hour < 10)
			cout << "0";
		cout << hour << "h";
		if(minute < 10)
			cout << "0";
		 cout<< minute;
	}      

	Time& Time::operator=(const Time& t) {
		hour = t.hour;
		minute = t.minute;

		return (*this);
	}

	Time Time::operator+(int n) const 
	{

		Time result = *this;
		result.minute = result.getMinute() + result.getHour() * 60 + n;

		return Time(result.minute);
	}


	Time operator+(int n, const Time& time) 
	{
		return time + n;
	}

	Time Time::operator+(const Time &t) const 
	{
		Time time(*this);

		int total,totalA,totalB;

		totalA = time.hour*60 + time.minute;
		totalB = t.getMinute() + t.getHour() * 60;
		total = totalA + totalB;

		return Time(total);
	}

	Time Time::operator-(int n) const 
	{
		Time result = *this;

		int total = result.getMinute() + result.getHour() * 60 - n;

		return Time(total);

	}

	Time operator-(int n, const Time& time) 
	{

		int totalMinutes = 60 * time.getHour() + time.getMinute();

		int resultMinutes = n - totalMinutes;

		return Time(resultMinutes);

	}


	Time Time::operator-(const Time &t) const 
	{
		Time time(*this);

		int total,totalA,totalB;

		totalA = time.hour*60 + time.minute;
		totalB = t.getMinute() + t.getHour()*60;
		total = totalA - totalB;

		return Time(total);

	}

	int Time::operator<(const Time& t) {
		return compTime(t)==-1;
	}

	int Time::operator>(const Time& t) {
		return compTime(t)==1;
	}

	int Time::operator==(const Time& t) {
		return compTime(t)==0;
	}

	int Time::compTime(const Time& t) {
		if (getHour() < t.getHour()) return -1;
		if (getHour() > t.getHour()) return 1;

		if (getMinute() < t.getMinute()) return -1;
		if (getMinute() > t.getMinute()) return 1;

		return 0;
	}

	ostream& operator<<(ostream& s, const Time& t) {
	    if (t.hour < 10) 
	    {
	        s << "0";
	    }
	    s << t.hour << "h";

	    if (t.minute < 10) 
	    {
	        s << "0";
	    }
	    s << t.minute;
		
		return s;
	}

	istream& operator>> (istream& s, Time& t) {
		char h;
		s>>t.hour >> h >> t.minute;

		return s; 
	}

	Time Time::operator++() //pre-incrementation
	{
		(*this) = (*this) + 30;
		return (*this);
	}

	Time Time::operator++(int) //post-incrementation
	{
		Time tmp(*this);
		(*this) = (*this) + 30;
		return tmp;
	}

	Time Time::operator--() //pre-incrementation
	{
		(*this) = (*this) - 30;
		return (*this);
	}

	Time Time::operator--(int) //post-incrementation
	{
		Time tmp(*this);
		(*this) = (*this) - 30;
		return tmp;
	}
	
}