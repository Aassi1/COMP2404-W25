#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

class View {
		
	public:
    	void mainMenu(int&);
		void getStudentInfo(string& name, string& number, float& gpa);
		void getStudentName(string& name);
		void printStudents(List &);
			
};
#endif