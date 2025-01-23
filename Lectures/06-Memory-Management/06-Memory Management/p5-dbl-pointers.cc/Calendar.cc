#include "Calendar.h"

Calendar::Calendar(){
    numDates = 0;
}

Calendar::~Calendar(){
    // Delete all Dates we are storing.
    // This will prevent memory leaks
    for (int i = 0; i < numDates; ++i){
        delete dates[i];
    }
    
}

bool Calendar::addDate(int y, int m, int d, string e){
   if (numDates >= MAX_ARRAY)return false;

   Date * date = new Date(y, m, d, e);

   int index = numDates;

   while (index > 0){
        if (dates[index-1]->lessThan(*date)){
            break;
        }
        dates[index] = dates[index-1];
        --index;
   }

   dates[index] = date;
   ++numDates;

   return true;
}

bool Calendar::removeDate(int y, int m, int d){
    Date date(y, m, d);

    int index = 0;

    while (index < numDates){
        if (date.equals(*dates[index])){
            break;
        }
        ++index;
    }

    if (index == numDates) return false;

    delete dates[index];

    --numDates;

    while(index < numDates){
        dates[index] = dates[index+1];
        ++index;
    }

    return true;   
}


bool Calendar::getDate(int index, Date** date){
    if (index < 0 || index >= numDates) return false;

    *date = dates[index];

    return true;

    
}

void Calendar::print(){
    cout<<"Printing calendar:"<<endl;

    for (int i = 0 ; i < numDates; ++i){
        dates[i]->print();
    }
}