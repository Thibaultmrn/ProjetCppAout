#include "Exception.h"

namespace planning 
{
	Exception::Exception()
	{
		#ifdef DEBUG
        cout << ">>Exception: Constructeur par defaut <<" <<endl;
        #endif
        setMessage("  ");
	}

	Exception::Exception(const string& Message)
	{
		#ifdef DEBUG
        cout << ">>Exception: Constructeur d'initialistion <<" <<endl;
        #endif

        setMessage(Message);
	}

	Exception::Exception(const Exception&c)
	{
		#ifdef DEBUG
        cout << ">>Exception: Constructeur de copie <<" <<endl;
        #endif

        setMessage(c.getMessage());
	}

	void Exception::setMessage(const string& Message)
	{
		this->message=Message;
	}

	string Exception::getMessage()const
	{
		return this->message;
	}


}