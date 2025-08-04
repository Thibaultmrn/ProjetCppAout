#include "Time.h"
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
		if(h < 0 || h > 23) return;
		hour = h;
	}

	void Time::setMinute(int m) {
		if(m < 0 || m > 59) return;
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

	Time operator+(const int t, const Time t1) {
		Time time(t1);
		time.minute += t;
		if(time.minute > 59)
		{
			time.hour += time.minute / 60;
			time.minute = time.minute % 60;
		}

		return time;
	}

	Time operator+( const Time t1, const int t) {
		Time time(t1);
		time.minute += t;

		if(time.minute > 59)
		{
			time.hour += time.minute / 60;
			time.minute = time.minute % 60;
		}
		return time;
	}

	Time operator+(const Time t1,const Time t2) {
		Time time(t1);
		time.hour += t2.hour;
		time.minute += t2.minute;

		if(time.minute > 59)
		{
			time.hour += time.minute / 60;
			time.minute = time.minute % 60;
		}
		return time;
	}

	Time operator-( const Time t1, const int t) {
		Time time(t1);
		time.minute -= t;

		while(time.minute < 0)
		{
			time.hour -= 1;
			time.minute = time.minute + 60;
		}
		return time;
	}

	Time operator-(const int t, const Time t1) {
		Time time(t1);
		time.minute -= t;

		while(time.minute < 0)
		{
			time.hour -= 1;
			time.minute = time.minute + 60;
			if(time.hour <0)
			{
				time.hour = 23;
			}
		}

		return time;
	}

	Time operator-(const Time t1,const Time t2) {
		Time time(t1);
		time.hour -= t2.hour;
		time.minute -= t2.minute;

		while(time.minute < 0)
		{
			time.hour -= 1;
			time.minute = time.minute + 60;
			if(time.hour <0)
			{
				time.hour = 23;
			}
		}
		return time;
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
		if(hour < t.hour) return -1;
		if(hour > t.hour) return 1;

		if(minute < t.minute) return -1;
		if(minute > t.minute) return 1;

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