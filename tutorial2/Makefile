
all: p1

Character.o: Character.h Character.cc
	g++ -c Character.cc

battle.o: battle.h battle.cc
	g++ -c battle.cc

p1: Character.o battle.o main.o
	g++ -o p1 Character.o battle.o main.o

main.o: Character.h battle.h main.cc
	g++ -c main.cc
clean :
	rm -f *.o
