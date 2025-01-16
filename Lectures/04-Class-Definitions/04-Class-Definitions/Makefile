EXECS = p3 p4

all:	$(EXECS)

p3:	p3-scope.cc
	g++ -o p3 p3-scope.cc

p4:	p4-nspace.cc
	g++ -o p4 p4-nspace.cc

ext.o: ext.cc
	g++ -c ext.cc

clean:
	rm -f $(EXECS) *.o
