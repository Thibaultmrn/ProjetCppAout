#include "Event.h"
#include "TimingException.h"

namespace planning
{
    int Event::currentCode = 1;

    Event::Event() {
        #ifdef DEBUG
        cout<<">>> Event : constructeur par defaut <<<"<<endl;
        #endif
        code = 1;
        title = nullptr;
        setTitle("---");
        timing = nullptr;   
    }

    Event::Event(const Event &e) {
        #ifdef DEBUG
        cout<<">>> Event : constructeur de copie <<<"<<endl;
        #endif
        setCode (e.getCode());
        title = nullptr;
        setTitle(e.getTitle());
        timing = nullptr;
        setTiming(e.getTiming());
    }

    Event::Event(int c, const char *t) {
        #ifdef DEBUG
        cout << ">>> Event : constructeur d'initialisation <<<" << endl;
        #endif
        setCode(c);
        title = nullptr;
        setTitle(t);
        timing = nullptr;
    }

    Event::~Event() {
        #ifdef DEBUG
        cout << ">>> Event : destructeur <<<" << endl;    
        #endif
        if (title) delete title;
        if (timing) delete timing;
    }

    void Event::setCode (int c) {
        if(c < 1) return;
        code = c;
    }

    void Event::setTitle(const char *t) {
        if(t == nullptr) return;
        if(title) delete title;
        title = new char[strlen(t)+1];
        strcpy(title, t);
    }

    void Event::setTiming(const Timing& t) {
        if (timing) delete timing;
        timing = new Timing(t);
    }
    int Event::getCode() const {
        return code;
    }

    const char *Event::getTitle() const {
        return title;
    }

    Timing Event::getTiming() const {
        if (timing == nullptr)
        {
            throw TimingException("Aucune planification !", TimingException::NO_TIMING);
        }
        return *timing;
    }

    void Event::display() const {
        cout << "Event("<<code<<") : " << title<<endl;
        if(timing)
        {
        timing->display();
        }
    }

    string Event::toString()const
    {
        string ret;
        ret= "Event : code = ";
        ret+=to_string(getCode());
        ret+="et";
        ret+=title;

        if (timing != nullptr)
        {
            ret+="Timing : ";
            ret += timing->toString(); 
        } 
        else 
        {
            ret+="Timing : non defini";
        }


        return ret;
    }
    
    ostream& operator<<(ostream& s, const Event& e) 
    {
        s<<"<Event>"<<endl;

        s<<"<code>"<<endl;
        s<<e.getCode()<<endl;
        s<<"</code>"<<endl;

        s<<"<title>"<< endl;
        s<< e.getTitle()<<endl;
        s<<"</title>"<<endl;

        
        if (e.timing != nullptr) 
        {
            s << "<timing>" << endl;
            s <<*(e.timing)<<endl; 
            s<<"</timing>"<< endl;
        } 
        
        s<<"</Event>";

        return s;
    }

    istream& operator>>(istream& s, Event& e) 
    {
        string tag;
        Timing tempTiming;

        getline(s,tag);


        getline(s,tag);
        getline(s,tag);
        e.setCode(stoi(tag));
        getline(s,tag);

        getline(s,tag);
        getline(s,tag);
        e.setTitle(tag.c_str());
        getline(s,tag);

        
        getline(s,tag); 
        if (tag =="<timing>") 
        {
            s>>tempTiming;
            e.setTiming(tempTiming);
            getline(s, tag);
            getline(s, tag);
            return s;
        }
        else
        {
            return s;
        }
    }
}