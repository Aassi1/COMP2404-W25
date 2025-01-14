
p1: p1.cc
	g++ -o p1 p1.cc

p2 : p2.cc
	g++ -o p2 p2.cc

p3: p3.cc power.o
	g++ -o p3 p3.cc power.o

power.o:power.cc
	g++ -c power.cc power.o
all: p1 p2 p3
clean : 
	rm -f *.o
