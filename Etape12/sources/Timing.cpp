#include "Timing.h"
#include "TimingException.h"

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
		if(d != MONDAY && d != TUESDAY && d != WEDNESDAY && d != THURSDAY && d != FRIDAY && d != TUESDAY && d != SATERDAY && d != SUNDAY)
		{

			throw TimingException("Jour invalide !",TimingException::INVALID_DAY);
		}
		day = d;
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

	string Timing::toString() const
	{
	  string ret;

	  ret="jour = ";
	  ret+=day;
	  ret+="heure de debut = ";
	  ret+=start.toString();
	  ret+="duree totale = ";
	  ret+=duration.toString();

	  return ret;
	}
	
	const string Timing::MONDAY = "Lundi";
	const string Timing::TUESDAY = "Mardi";
	const string Timing::WEDNESDAY = "Mercredi";
	const string Timing::THURSDAY = "Jeudi";
	const string Timing::FRIDAY = "Vendredi";
	const string Timing::SATERDAY = "Samedi";
	const string Timing::SUNDAY= "Dimanche";
    
	int Timing::operator<(const Timing& t) {
	 return compT(t)==-1;
	}

	int Timing::operator>(const Timing& t) {
	  return compT(t)==1;
	}

	int Timing::operator==(const Timing& t) {
	  return compT(t) == 0;
	}
	
	int Timing::compT(const Timing& t) {
	  if(day<t.day) return -1;
	  if(day>t.day) return 1;

	  if(start<t.start) return -1;
	  if(start>t.start) return 1;

	  if(duration<t.duration) return -1;
	  if(duration>t.duration) return 1;


	  return 0;
	}

	bool Timing::intersect(const Timing& t) const 
	{
		if (day != t.day) 
			return false;

		Time finPremierHoraire = getStart() + getDuration();         
		Time finDeuxiemeHoraire = t.getStart() + t.getDuration();   

		if(finPremierHoraire<t.getStart() || finPremierHoraire==t.getStart())
		return false;

		if(finDeuxiemeHoraire<getStart() || finDeuxiemeHoraire==getStart())
		return false;

		return true;
	}
	
	istream& operator>> (istream& s, Timing& t)
	{
		
		string sDay,tag;
		
		getline(s, tag);//<Timing>
		getline(s, tag);//<day>
		getline(s, sDay);
		getline(s, tag);//</day>
		getline(s, tag);//<start>
		s >> t.start;
		getline(s, tag);//</start>
		getline(s, tag);//<duratop>
	    s >> t.duration;
		getline(s, tag);//</duratop>
		getline(s, tag);//</Timing>

		t.setDay(sDay);

		return s;
	}

	ostream& operator<<(ostream& s, const Timing& t)
	{
		s <<"<Timing>" << endl;
		s <<"<day>" << endl;
		s <<t.getDay() << endl;
		s <<"</day>" << endl;

		s <<"<start>" << endl;
		s <<t.getStart()<< endl;
		s <<"</start>" << endl;

		s <<"<duration>" << endl;
		s <<t.getDuration()<< endl;
		s <<"</duration>" << endl;
		s <<"</Timing>";

		return s;
	}
}