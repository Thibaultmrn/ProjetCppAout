#include "Event.h"

Event::Event(){
    cout<<">>> Event : constructeur par defaut <<<"<<endl;
    code = 1;
    title = nullptr;
    setTitle("---");
}

Event::Event(const Event &e){
    cout<<">>> Event : constructeur de copie <<<"<<endl;
    setCode(e.getCode());
    title = nullptr;
    setTitle(e.getTitle());
}

Event::Event(int c, const char *t){
    cout << ">>> Event : constructeur d'initialisation <<<" << endl;
    setCode(c);
    title = nullptr;
    setTitle(t);
}

Event::~Event(){
    cout << ">>> Event : destructeur <<<" << endl;    
    if (title) delete title;
}

void Event::setCode (int c){
    if(c < 1) return;
    code = c;
}

void Event::setTitle(const char *t){
    if(t == nullptr) return;
    if(title) delete title;
    title = new char[strlen(t)+1];
    strcpy(title, t);
}

int Event::getCode() const{
    return code;
}

const char *Event::getTitle() const{
    return title;
}

void Event::display() const{
    cout << "Event("<<code<<") : " << title<<endl;
}