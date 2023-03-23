#pragma once
#include <iostream>
using namespace std;
struct Appointment{
    int hours;
    int mins;
};
class Person{
private:
    string name; //data member stores name of either a mechanic or customer
    int ID; //data member stores ID of either a mechanic or customer
    int age; //data member stores age of either a mechanic or customer
public:
    Person(); //constructor initialises all data members of class
    virtual void setID(int); //setter function for ID
    const virtual int getID(); //getter function for ID
    void setAge(int); //setter function for age
    const int getAge(); //getter function for age
    void setName(string); //setter function for name
    const string getName(); //getter function for name
    const void printinfo(); //displays the infrmation of a person whether mechanic or customer
};

