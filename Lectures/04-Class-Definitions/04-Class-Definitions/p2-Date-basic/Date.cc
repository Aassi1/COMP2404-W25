
#include "Date.h"


Date::Date(int y, int m, int d){
	setDate(y,m,d);
}

Date::Date(){
	setDate(1901,1,1);
}

Date::Date(Date& d){
	setDate(d.year,d.month,d.day);
}


//setters
void Date::setDay(int d){
	// Here, we are checking for some values that are not valid
	int max = getMaxDay();
	if (d>max) d=max;
	if (d<1) d=1;
	day = d;
}

void Date::setMonth(int m){
	// Here, we are checking for some values that are not valid
	if (m > 12) m = 12;
	if (m < 1) m = 1;
	month = m;
}

void Date::setYear(int y){
	// Here, we are checking for some values that are not valid
	if (y < 1901) y = 1901;
	year = y;
}


void Date::setDate(int y, int m, int d){
	setMonth(m);
	setDay(d);
	setYear(y);
}

void Date::setDate(Date& d){
	setDate(d.year, d.month, d.day);
}

string Date::getMonthName(){
	string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	string smonths[12]={"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul","Aug", "Sep", "Oct", "Nov", "Dec"};
	
	return months[month-1];
}

//other


void Date::print(){
	cout << getMonthName()<<" "<<day<<", "<<year<<endl;
}


int Date::getMaxDay(){
	switch(month){
		case 4:
		case 6:
		case 9:
		case 11: 			return 30;
		case 2:				return 28;
		default:			return 31;
	}
}

