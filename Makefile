CC = g++
CFLAGS = -c -g -Wall
EXE = prog_test
SOURCES = main.cpp Para.cpp Generator.cpp Net.cpp Timer.cpp
OBJECTS = $(SOURCES:.cpp=.o)
CLEAN	= rm -rf 

$(EXE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp 
Timer.o: Timer.cpp
	$(CC) $(CFLAGS) Timer.cpp
Para.o: Para.cpp
	$(CC) $(CFLAGS) Para.cpp 
Generator.o: Generator.cpp
	$(CC) $(CFLAGS) Generator.cpp
Net.o: Net.cpp
	$(CC) $(CFLAGS) Net.cpp	

clean:
	$(CLEAN) $(OBJECTS) $(EXE)
