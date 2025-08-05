CLASSE=./Classes
COMPIL=g++ -I $(CLASSE)
OBJS=$(CLASSE)/Time.o $(CLASSE)/Timing.o $(CLASSE)/Event.o $(CLASSE)/Professor.o $(CLASSE)/Schedulable.o $(CLASSE)/Group.o $(CLASSE)/Classroom.o
PROGRAMS=Test4

Test4: Test4.cpp $(OBJS)
	$(COMPIL) Test4.cpp $(OBJS) -o Test4

Time.o: $(CLASSE)/Time.cpp $(CLASSE)/Time.h
	$(COMPIL) $(CLASSE)/Time.cpp -c -o $(CLASSE)/Time.o

Timing.o: $(CLASSE)/Timing.cpp $(CLASSE)/Timing.h
	$(COMPIL) $(CLASSE)/Timing.cpp -c -o $(CLASSE)/Timing.o

Event.o: $(CLASSE)/Event.cpp $(CLASSE)/Event.h $(CLASSE)/Timing.h
	$(COMPIL) $(CLASSE)/Event.cpp -c -o $(CLASSE)/Event.o

Schedulable.o: $(CLASSE)/Schedulable.cpp $(CLASSE)/Schedulable.h
	$(COMPIL) $(CLASSE)/Schedulable.cpp -c -o $(CLASSE)/Schedulable.o

Professor.o: $(CLASSE)/Professor.cpp $(CLASSE)/Professor.h $(CLASSE)/Schedulable.h
	$(COMPIL) $(CLASSE)/Professor.cpp -c -o $(CLASSE)/Professor.o

Group.o: $(CLASSE)/Group.cpp $(CLASSE)/Group.h $(CLASSE)/Schedulable.h
	$(COMPIL) $(CLASSE)/Group.cpp -c -o $(CLASSE)/Group.o

Classroom.o: $(CLASSE)/Classroom.cpp $(CLASSE)/Classroom.h $(CLASSE)/Schedulable.h
	$(COMPIL) $(CLASSE)/Classroom.cpp -c -o $(CLASSE)/Classroom.o

clean:
	rm -f $(OBJS) core
clobber: clean
	rm -f $(PROGRAMS)