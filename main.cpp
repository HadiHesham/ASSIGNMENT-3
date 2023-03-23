#include <iostream>
#include "Person.h"
#include "Customer.h"
#include "Mechanic.h"
#include "Q.h"
#include <fstream>
using namespace std;
void sort1(Customer c[],int size){ //function that sorts the array in ascending order of appointments of customers, takes array and size as parameter
    Customer temp; //used for swapping
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            if(c[i]>c[j]){ //use of overloaded constructor which compares the appointment times of customers
                temp=c[i]; //then part of if sorts the array ascendingly based on appointment times by swapping array elements
                c[i]=c[j];
                c[j]=temp;
            }
        }
    }
}
int main(){
    ifstream w;
    w.open("Mechanics.txt"); //opens mechanics.txt which stores the mechanics and their information and busy times
    int numofMechancics; //variiable stores number of mechanics
    w>>numofMechancics; //inserts number of mechanics from file into variable numofMechanics
    Mechanic m[numofMechancics]; //declared array mechanics of size of number of mechanics stored in variable numofMechanics
    string n; // variable stores name of mechanic or customer
    int age,ID; //variables store age and ID of mechanic or customer
    int i=0; //variable to access mechanics array elements
    while(!w.eof()){ //loop to insert the mechanics information and their busy times
        w>>n>>age>>ID; //inserta the mechanics information in variables
        m[i].setName(n); //sets the name of mechanic
        m[i].setAge(age); //sets the age of mechanic
        m[i].setID(ID); //sets the ID of mechanic
        int numofappointment; //variable to store number of appointments
        w>>numofappointment; //inserts number of appointments each mechanic has in variable numofappointments
        for(int j=0;j<numofappointment;j++){ //loops around number of appointments
            Appointment a;
            w>>a.hours>>a.mins; //stores each appointment time in variable of type appointment
            m[i].setappointment(a); //function to set the appointment
        }
        i++; //increments i so we can access the next array index to store next mechanic in it
    }
    w.close(); //closes mechanics.txt file
    ifstream f;
    f.open("Customers.txt"); //opes customers.txt file
    int numofCustomers; //variiable stores number of customers
    f>>numofCustomers; //inserts number of customers from file into variable numofCustomers
    Customer c[numofCustomers]; //declared array customers of size of number of customers stored in variable numofCustomers
    Q<string> s(numofCustomers); //declared class queue of queue size of number of customers
    int count=0; //variable to access mechanics array elements
    Appointment a; //variable to store appointment times
    for(int i=0;i<numofCustomers;i++){ //loop to insert the customers information and the appointment time they want
        count=0; //counter to loop on array of mechanics
        bool available=false; //bool variable thst exits the while loop if mechanic is available
        f>>n>>age>>ID>>a.hours>>a.mins; //inserts the customer information in variables and the appointment time they want
        c[i].setName(n); //sets the name of customer
        c[i].setAge(age); //sets the age of customer
        c[i].setID(ID); //sets the ID of customer
        while(available==false && count<3) { //loop to search for the first available mechanic in specified time by customer
            if(m[count].isAvailable(a)==true){ //use function isAvailable that takes appointment as parameter and checks whether or not mechanic is availabe at this time
                c[i].setMechanicID(m[count].getID()); //if available, sets the appointment using a setter function
                c[i].setAppointment(a);
                available=true; //set available to true to exit the loop
            }
            count++; //increments count to check all mechanics
        }
        if (available==false) // if available bool variable is still false then there is no mechanic available in the time the customer wants
            cout<<c[i].getName()+": "+"no mechanic is available at requested time"<<endl;
    }
    sort1(c,numofCustomers); //calls the sort function to sort array of customers in ascending order of time
    string l; //stores the string that will be enqueued into the queue
    for(int i=0;i<numofCustomers;i++){ //loops around the array elements of customer array to access each customer
        if(c[i].getMechanicID()!=-1){ //ignores customers who dont have an appointment since all mechanics were busy in the time they requested
            l=c[i].getName()+" has an appointment at "+to_string(c[i].getHr())+":"+to_string(c[i].getMin())+" with "+m[c[i].getMechanicID()].getName();
            s.push(l); //enqueues the string that consist of the customer name, their appointment time and the name of their assigned mechanic
        }
    }
    f.close(); //closes the customers.txt file
    s.DisplayQueue(); //displayes the queue elements
}
