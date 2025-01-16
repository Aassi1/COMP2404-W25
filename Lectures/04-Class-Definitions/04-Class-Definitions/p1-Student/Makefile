all: p1

p1: p1.cc Student.o
	g++ -o p1 p1.cc Student.o

Student.o: Student.h Student.cc
	g++ -c Student.cc
	
clean:
	rm -f p1 *.o