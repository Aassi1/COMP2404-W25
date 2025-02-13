p1:	main.o Animal.o Chicken.o
	g++ -o p1 main.o Animal.o Chicken.o 

main.o:	main.cc Animal.h Chicken.h 
	g++ -c main.cc

Animal.o:	Animal.cc Animal.h
	g++ -c Animal.cc

Chicken.o:	Chicken.cc Chicken.h Animal.h
	g++ -c Chicken.cc

clean:
	rm -f *.o p1
