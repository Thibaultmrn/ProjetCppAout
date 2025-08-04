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
}