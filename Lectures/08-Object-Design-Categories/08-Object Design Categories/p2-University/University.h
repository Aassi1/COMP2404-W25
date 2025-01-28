#ifndef UNIVERSITY_H
#define UNIVERSITY_H

#include <iostream>
#include <string>
#include "List.h"

using namespace std;

class University {
		
	public:
		//constructors
		University(string name);
		~University();
		
		bool addStudent(string name, string number, float gpa);
		bool removeStudent(string name);
		void removeUpTo(string name);
		
		void print();
		void getStudents(List** students);		
		void getHonourRoll(List& honours);

	private:
		string name;
		List students;
		
	
};
#endif