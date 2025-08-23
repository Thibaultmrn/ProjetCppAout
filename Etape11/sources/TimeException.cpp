#include "TimeException.h"
using namespace std;

namespace planning 
{
	TimeException::TimeException():Exception()
	{
		#ifdef DEBUG
        cout << ">>TimeException: Constructeur par défaut <<" << endl;
        #endif

        setCode(0);
	}

	TimeException::TimeException(const string& Message ,int Code):Exception(Message)
	{
		#ifdef DEBUG
        cout << ">>TimeException: Constructeur d'initialisation <<" << endl;
        #endif

        setCode(Code);
	}

	TimeException::TimeException(const TimeException& c):Exception(c)
	{
		#ifdef DEBUG
        cout << ">>TimeException: Constructeur de copie <<" << endl;
        #endif

       setCode(c.getCode());
	}

	void TimeException::setCode(int Code)
	{
		this->code=Code;
	}

	int TimeException::getCode()const
	{
		return this->code;
	}

	const int TimeException::INVALID_HOUR = 1;
	const int TimeException::INVALID_MINUTE = 2;
	const int TimeException::OVERFLOW = 3;

}