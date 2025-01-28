#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Student {
		
	public:
		//constructor
		Student(string name = "unknown", string num = "-1", float g = 0.0f);
		//copy constructor
		Student(Student&);
		
		
		// return true if student is on the honour roll
		bool honourRoll();
		bool lessThan(Student&);
		bool lessThan(string);
		bool equals(string );
		void print();
	
	private:
		string name;
		string number;
		float gpa;
	
};
#endif