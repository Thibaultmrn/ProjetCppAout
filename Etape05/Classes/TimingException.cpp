#include "TimingException.h"
using namespace std;
#include <iostream>
#include <string.h>

namespace planning
{
	TimingException::TimingException():Exception()
	{
		#ifdef DEBUG
        cout << ">>TimingException: Constructeur par défaut <<" << endl;
        #endif

        setCode(0);
	}

	TimingException::TimingException(const string& Message, int Code):Exception(Message)
	{
		#ifdef DEBUG
        cout << ">>TimingException: Constructeur d'initialisation <<" << endl;
        #endif

        setCode(Code);

	}

	TimingException::TimingException(const TimingException&c):Exception(c)
	{
		#ifdef DEBUG
        cout << ">>TimingException: Constructeur de copie <<" << endl;
        #endif

       setCode(c.getCode());
	}

	void TimingException::setCode(int Code)
	{
		this->code=Code;
	}

	int TimingException::getCode()const
	{
		return this->code;
	}

	const int TimingException::INVALID_DAY = 4;
	const int TimingException::NO_TIMING = 5;
}