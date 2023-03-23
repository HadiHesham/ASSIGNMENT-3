//
//  Customer.h
//  ASSIGNMENT 3
//
//  Created by macbook on 17/03/2023.
//

#ifndef Customer_h
#define Customer_h


#endif /* Customer_h */
#include <iostream>
#include "Person.h"
using namespace std;
class Customer : public Person{ //child class inherits from person class and type of inheritance is public
private:
    int MechanicID; //stores Mechanic ID of the mechanic the customer is assigned to
    Appointment A; //stores the appointment time of the customer
public:
    Customer(); //constructor to intialise data members
    void setMechanicID(int); //setter function for MechanicID
    int getMechanicID(); //getter function for MechanicID
    int getHr() const; //getter function for hour of struct appointment
    int getMin() const; //getter function for min of struct appointment
    virtual void setAppointment(Appointment); //setter function for A data member of Appointment data type
    virtual Appointment getAppointment(); //getter function for A data member return Appointment data type
    bool operator<(const Customer &); //overloaded operator < compares appointment times of 2 customer classes
    bool operator>(const Customer &); //overloaded operator > compares appointment times of 2 customer classes
    bool operator==(const Customer &); //overloaded operator == compares appointment times of 2 customer classes
};
