#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <iostream>
#include <string>

class View;
class University;

using namespace std;

class Controller {
		
	public:
			
		void launch();
		
	
	private:
		void init(University&);
		void addStudent();
		void removeStudent();
		void printStudents();
		void removeUpTo();
		void printHonourRoll();

		View*       	view;
		University* 	uni;
	
};
#endif