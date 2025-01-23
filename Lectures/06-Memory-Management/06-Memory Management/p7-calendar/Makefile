all:	p7

p7:	main.cc Date.o Calendar.o
	g++ -o p7 main.cc Date.o Calendar.o

Date.o: Date.h Date.cc
	g++ -c Date.cc

Calendar.o: Calendar.h Calendar.cc
	g++ -c Calendar.cc

clean:
	rm -f p7 *.o
