#include <iostream>
#include "Person.h"
using namespace std;
Person::Person():name(""),ID(0),age(0){}
const void Person::printinfo(){
    cout<<name<<endl;
    cout<<ID<<endl;
    cout<<age<<endl;
}
void Person::setID(int i){
    ID=i;
}
const int Person::getID(){ 
    return ID;
}
void Person::setName(string n){ 
    name=n;
}
const string Person::getName(){ 
    return name;
}
void Person::setAge(int a){ 
    age=a;
}
const int Person::getAge(){ 
    return age;
}
