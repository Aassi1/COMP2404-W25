
# If you are compiling natively on a mac, you will need to use the following flags.
# When you are compiling your executable: 
#
#     g++ $(macflag) -o <exectuable> <source files> $(maclib)
#
# For example:
#
# 	  g++ $(macflag) -o a1 main.o Panel.o Button.o CuWindow.o Tester.o $(maclib)
#
# When you are compiling your object files:
#
#	  g++ $(macflag) -c <source file> $(macinclude)
#
# macinclude is used to include the X11 library, if you have installed it using XQuartz.
# maclib is used to link the X11 library, if you have installed it using XQuartz.
# macflag is used to enable C++11 features, which are required for this assignment.

# macflag    = -std=c++11 				
# macinclude = -I /opt/X11/include 
# maclib     = -L /opt/X11/lib 

# Put your Makefile instructions below.

# all: test

# test: Tester.o RGB.o Button.o CuWindow.o Panel.o Tester.o main.o
# 	g++ -o test Tester.o RGB.o Button.o CuWindow.o Panel.o main.o -lX11

# RGB.o: RGB.cc defs.h RGB.h
# 	g++ -c RGB.cc 

# Button.o: Button.cc defs.h Button.h
# 	g++ -c Button.cc 

# CuWindow.o: CuWindow.cc defs.h CuWindow.h
# 	g++ -c CuWindow.cc 

# Panel.o: Panel.cc defs.h Panel.h
# 	g++ -c Panel.cc 

# Tester.o: Tester.cc defs.h Tester.h
# 	g++ -c Tester.cc

# main.o: main.cc defs.h Tester.h CuWindow.h
# 	g++ -c main.cc 

# clean:
# 	rm -f test *.o

all: test

test: Tester.o RGB.o Button.o CuWindow.o Panel.o main.o
	g++ -o test Tester.o RGB.o Button.o CuWindow.o Panel.o main.o -lX11

RGB.o: RGB.cc defs.h RGB.h
	g++ -c RGB.cc 

Button.o: Button.cc defs.h Button.h
	g++ -c Button.cc 

CuWindow.o: CuWindow.cc defs.h CuWindow.h
	g++ -c CuWindow.cc 

Panel.o: Panel.cc defs.h Panel.h
	g++ -c Panel.cc 

Tester.o: Tester.cc defs.h Tester.h
	g++ -c Tester.cc

main.o: main.cc defs.h Tester.h CuWindow.h
	g++ -c main.cc 

clean:
	rm -f test *.o
