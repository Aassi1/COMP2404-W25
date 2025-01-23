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
    if (numDates >= MAX_ARRAY) return false;

    Date* date = new Date(y, m, d, e);

    int index = 0;
    //finds the right index for date
    while (index < numDates){
        if(date->lessThan(*dates[index])){
            break;
        }
        ++index;
    }

    for (int i = numDates; i > index; --i){
        dates[i] = dates[i-1];
    }

    dates[index] = date;

    ++ numDates;

    return true;    
}

bool Calendar::removeDate(int y, int m, int d){
    Date date(y,m,d);

    int index = 0;
    //finds the right index for date
    while (index < numDates){
        if(date.equals(*dates[index])){
            break;
        }
        ++index;
    }

    if (index == numDates) return false;

    delete dates[index];


    while (index < numDates-1){
        dates[index] = dates[index+1];
        ++index;
    }
    --numDates;
    return true;
}
 Date* Calendar::getDate(int index){
    if (index < 0 || index >= numDates) return nullptr;
    return dates[index];
}

void Calendar::print(){
    cout<<endl<<"Printing all dates: "<<endl;

    for (int i =0; i < numDates; ++i){
        dates[i]->print();
    }
    
}