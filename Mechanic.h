//
//  Mechanic.h
//  ASSIGNMENT 3
//
//  Created by macbook on 17/03/2023.
//

#ifndef Mechanic_h
#define Mechanic_h
#include <iostream>
#include "Person.h"
using namespace std;
#endif /* Mechanic_h */
class Mechanic : public Person{
private:
    int counter; //data member to access last element of array m of type Appointment
    Appointment *m; //pointer for dynamic array of type Appointment
public:
    Mechanic(); //constructor to intialise data members and make a dynamic array
    bool isAvailable(Appointment) const; //fuction to check if a mechanic is available (is busy or not) at a certain time
    void setappointment(Appointment); //setter function for Appointment
    Appointment getAppointment(int); //getter function for Appointment
    ~Mechanic(); //destructor to return burrowed memory space for the dynamic array back to the heap
};
