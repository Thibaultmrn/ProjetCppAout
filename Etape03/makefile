CLASSE=./Classes
COMPIL=g++ -I $(CLASSE)
OBJS=$(CLASSE)/Time.o $(CLASSE)/Timing.o $(CLASSE)/Event.o
PROGRAMS=Test3

Test3: Test3.cpp $(CLASSE)/Time.o $(CLASSE)/Timing.o $(CLASSE)/Event.o
	$(COMPIL) Test3.cpp $(CLASSE)/Time.o $(CLASSE)/Timing.o $(CLASSE)/Event.o -o Test3

Time.o: $(CLASSE)/Time.cpp $(CLASSE)/Time.h
	$(COMPIL) $(CLASSE)/Time.cpp -c -o $(CLASSE)/Time.o

Timing.o: $(CLASSE)/Timing.cpp $(CLASSE)/Timing.h
	$(COMPIL) $(CLASSE)/Timing.cpp -c -o $(CLASSE)/Timing.o

Event.o: $(CLASSE)/Event.cpp $(CLASSE)/Event.h $(CLASSE)/Timing.h
	$(COMPIL) $(CLASSE)/Event.cpp -c -o $(CLASSE)/Event.o


clean:
	rm -f $(OBJS) core
clobber: clean
	rm -f $(PROGRAMS)