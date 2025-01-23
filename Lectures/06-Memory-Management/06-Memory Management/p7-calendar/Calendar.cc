#include "Calendar.h"

Calendar::Calendar(){

}

Calendar::~Calendar(){
    // Delete all Dates we are storing.
    // This will prevent memory leaks

    
    
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

 Date* Calendar::getDate(int index){
    return dates[index];
}

void Calendar::print(){
    cout<<endl<<"Printing all dates: "<<endl;
    

    
}