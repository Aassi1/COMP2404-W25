#ifndef CALENDAR_H
#define CALENDAR_H

#define MAX_ARRAY 365
#include <iostream>
#include <string>
#include "Date.h"

/*
* A very simple data structure to store and retrieve Dates.
* Later we would associate these Dates with events scheduled on that day
*/
class Calendar{

    public:
        Calendar();

        
        ~Calendar();

        /*
        * If the array is full, return false.
        * Otherwise, make a new Date with the
        * given year, month and day
        * and add it in order by lessThan
        * and return true.
        */
        bool addDate(int y, int m, int d, string e);

        /*
        * If the index is out of bounds,
        * return nullptr. Otherwise return the 
        * Date pointer found at the given index
        */
        Date* getDate(int index);

        /*
        * Return true if the date is found and removed,
        * otherwise return false
        */
        bool removeDate(int y, int m, int d);

        void print();

    private:
        //statically allocated array of pointers 
        Date* dates[MAX_ARRAY];
        int numDates;

};



#endif