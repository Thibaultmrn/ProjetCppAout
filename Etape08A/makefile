CLASSE=./Classes
COMPIL=g++ -I $(CLASSE)
OBJS=$(CLASSE)/Timetable.o $(CLASSE)/XmlFileSerializerException.o $(CLASSE)/TimingException.o $(CLASSE)/Time.o $(CLASSE)/Timing.o $(CLASSE)/Event.o $(CLASSE)/Exception.o $(CLASSE)/Professor.o $(CLASSE)/Schedulable.o $(CLASSE)/Group.o $(CLASSE)/Classroom.o $(CLASSE)/TimeException.o
PROGRAMS=Test8a

Test8a: Test8a.cpp $(OBJS)
	$(COMPIL) Test8a.cpp $(OBJS) -o Test8a

Time.o: $(CLASSE)/Time.cpp $(CLASSE)/Time.h
	$(COMPIL) $(CLASSE)/Time.cpp -c -o $(CLASSE)/Time.o

Timetable.o: $(CLASSE)/Timetable.cpp $(CLASSE)/Timetable.h
	$(COMPIL) $(CLASSE)/Timetable.cpp -c -o $(CLASSE)/Timetable.o

Timing.o: $(CLASSE)/Timing.cpp $(CLASSE)/Timing.h
	$(COMPIL) $(CLASSE)/Timing.cpp -c -o $(CLASSE)/Timing.o

Event.o: $(CLASSE)/Event.cpp $(CLASSE)/Event.h $(CLASSE)/Timing.h
	$(COMPIL) $(CLASSE)/Event.cpp -c -o $(CLASSE)/Event.o

Exception.o: $(CLASSE)/Exception.cpp $(CLASSE)/Exception.h
	$(COMPIL) $(CLASSE)/Exception.cpp -c -o Exception.o

Schedulable.o: $(CLASSE)/Schedulable.cpp $(CLASSE)/Schedulable.h
	$(COMPIL) $(CLASSE)/Schedulable.cpp -c -o $(CLASSE)/Schedulable.o

Professor.o: $(CLASSE)/Professor.cpp $(CLASSE)/Professor.h $(CLASSE)/Schedulable.h
	$(COMPIL) $(CLASSE)/Professor.cpp -c -o $(CLASSE)/Professor.o

Group.o: $(CLASSE)/Group.cpp $(CLASSE)/Group.h $(CLASSE)/Schedulable.h
	$(COMPIL) $(CLASSE)/Group.cpp -c -o $(CLASSE)/Group.o

Classroom.o: $(CLASSE)/Classroom.cpp $(CLASSE)/Classroom.h $(CLASSE)/Schedulable.h
	$(COMPIL) $(CLASSE)/Classroom.cpp -c -o $(CLASSE)/Classroom.o

TimeException.o: $(CLASSE)/TimeException.cpp $(CLASSE)/TimeException.h
	$(COMPIL) $(CLASSE)/TimeException.cpp -c -o $(CLASSE)/TimeException.o

TimingException.o: $(CLASSE)/TimingException.cpp $(CLASSE)/TimingException.h
	$(COMPIL) $(CLASSE)/TimingException.cpp -c -o $(CLASSE)/TimingException.o

XmlFileSerializerException.o: $(CLASSE)XmlFileSerializerException.cpp $(CLASSE)XmlFileSerializerException.h
	$(COMPIL)$(CLASSE)/XmlFileSerializerException.cpp -c -o XmlFileSerializerException.o

clean:
	rm -f $(OBJS) core
clobber: clean
	rm -f $(PROGRAMS)