#include "Timing.h"
namespace planning
{
	Timing::Timing() {
		#ifdef DEBUG
		cout << ">>> Timing : constructeur par défaut <<<" << endl;
		#endif
		setDay("Lundi");
		setStart(0);
		setDuration(0);
	}

	Timing::Timing(const string& d, const Time& s,const Time& du) {
		#ifdef DEBUG
		cout << ">>> Timing : constructeur d'initialisation <<<" << endl;
		#endif
	 	setDay(d);
	 	setStart(s);
	 	setDuration(du);
	}

	Timing::Timing(const Timing &t) {
		#ifdef DEBUG
		cout << ">>> Timing : constructeur de copie <<<" << endl;
		#endif
	  	setDay(t.getDay());
	 	setStart(t.getStart());
	  	setDuration(t.getDuration());
	}

	Timing::~Timing() {
	  #ifdef DEBUG
	  cout << ">>> Timing : destructeur <<<" << endl;
	  #endif
	}

	void Timing::setDay(const string& d) {
		day = d;
	}

	void Timing::setStart(const Time& s) {
		start.setHour(s.getHour());
    	start.setMinute(s.getMinute());
	}

	void Timing::setDuration(const Time& du) {
		duration.setHour(du.getHour());
    	duration.setMinute(du.getMinute());
	}

	string Timing::getDay() const {
		return day;
	}

	Time Timing::getStart() const {
		return start;
	}

	Time Timing::getDuration() const {
		return duration;
	}

	void Timing::display() const {
		cout << "Timing :" << day << " a ";
		start.display();
		cout<<" (";
		duration.display() ;
		cout << ") ";
	}

	const string Timing::MONDAY = "Lundi";
	const string Timing::TUESDAY = "Mardi";
	const string Timing::WEDNESDAY = "Mercredi";
	const string Timing::THURSDAY = "Jeudi";
	const string Timing::FRIDAY = "Vendredi";
	const string Timing::SATERDAY = "Samedi";
	const string Timing::SUNDAY= "Dimanche";
    
}