//
//  Customer.cpp
//  ASSIGNMENT 3
//
//  Created by macbook on 17/03/2023.
//

#include <stdio.h>
#include "Customer.h"
#include <iostream>
using namespace std;
Customer::Customer(){MechanicID=-1;A.hours=0;A.mins=0;}
void Customer::setMechanicID(int i){MechanicID=i;}
int Customer::getMechanicID(){return MechanicID;}
int Customer::getHr() const {return A.hours;}
int Customer::getMin() const {return A.mins;}
void Customer::setAppointment(Appointment a){A=a;}
Appointment Customer::getAppointment(){return A;}
bool Customer::operator==(const Customer &c){
    if(A.hours==c.getHr())
        return true;
    else
        return false;
}
bool Customer::operator>(const Customer &c){
    if(A.hours>c.getHr())
        return true;
    if(A.hours==c.getHr() && A.mins>c.getMin())
        return true;
    return false;
}
bool Customer::operator<(const Customer &c){
    if(A.hours<c.getHr())
        return true;
    if(A.hours==c.getHr() && A.mins<c.getMin())
        return true;
    return false;
}   
