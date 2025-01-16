
#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>

using namespace std;

class Date {
		
	public:
		//constructor
		Date(int year, int month, int day);
		Date();
		Date(Date&);
		
		//setters
		void setDay( int);
		void setMonth(int);
		void setYear(int);
		void setDate(int, int, int);
		void setDate(Date&);
		
		
	
		string getMonthName();
		
		//other
		void print();
	
	private:
		//functions
		int getMaxDay();	
	
		//variables
		int day;
		int month;
		int year;

};
#endif
