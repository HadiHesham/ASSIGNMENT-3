//
//  Mechanic.cpp
//  ASSIGNMENT 3
//
//  Created by macbook on 18/03/2023.
//

#include <stdio.h>
#include "Mechanic.h"
#include <iostream>
using namespace std;
Mechanic::Mechanic(){
    m=new Appointment ();
    counter = 0;
}
bool Mechanic::isAvailable(Appointment l) const {
    for(int i=0;i<counter;i++)
        if(l.hours==m[i].hours && l.mins==m[i].mins)
            return false;
    return true;
}
void Mechanic::setappointment(Appointment a){
    m[counter]=a;
    counter++;
}
Appointment Mechanic::getAppointment(int c) {
    return (*(m+c));
}
Mechanic::~Mechanic(){
    delete [] m;
}
