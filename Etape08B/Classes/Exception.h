#ifndef EXCEPTION_H 
#define EXCEPTION_H 

#include <string>
using namespace std;
#include <iostream>


namespace planning {

    class Exception
    {

        protected:
            string message;

        public:
            Exception();
            Exception(const string&);
            Exception(const Exception&);
            virtual ~Exception()=default;

            
            void setMessage(const string&);
            string getMessage()const;
    };

}
#endif