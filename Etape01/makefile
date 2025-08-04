Test1: Test1.o Event.o
	g++ Test1.o Event.o -o Test1

Test1.o: Test1.cpp Classes/Event.h
	g++ Test1.cpp -c

Event.o: Classes/Event.cpp Classes/Event.h
	g++ Classes/Event.cpp -c