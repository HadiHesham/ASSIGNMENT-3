#pragma once
#include <iostream>
using namespace std;
template <class T>
class Q{
private:
    T *que; //pointer for dynamic array of type T (accepts any data type)
    int front; //data member stores the index/place in circular queue where the enqueued element will be stored
    int rear; //data member stores the index/place in circular queue where the dequeued element will be retrieved from
    int count; //data member stores number of elements in circular queue
    int size; //data member stores size of circular queue (maximum number of elements to be stored in queue) and will be used to declare size of circular queue
public:
    Q(int); //constructor to intialise data members and make a dynamic array for the circular queue, takes size of circular queue as parameter
    bool isEmpty(); //checks if circular queue is empty
    bool push(T); //enques an elements in the circular queue based on first in first out
    bool pop(const T &); //deques an element from circular queue based on first in first out
    void DisplayQueue(); //displays the elements of circular queue based on first in first out
    ~Q(); //destructor to return burrowed memory space for the dynamic array for circular queue back to the heap
};
template <class T>
Q<T>::Q(int s){
    front=0;
    rear=-1;
    size=s;
    que=new T [size];
    count=0;
}
template <class T>
bool Q<T>::isEmpty(){
    if(count==0)
        return true;
    else
        return false;
}
template <class T>
bool Q<T>::push(T v){
    rear=(rear+1)%size;
    *(que+rear)=v;
    count++;
    return true;
    cout<<"Queue is full"<<endl;
    return false;
}
template <class T>
bool Q<T>::pop(const T &x){
    if(Q::isEmpty()==false){
        x=*(que+front);
        count--;
        front=(front+1)%size;
        return true;
    }
    cout<<"Queue is empty"<<endl;
    return false;
}
template <class T>
void Q<T>::DisplayQueue(){
    int f;
    if(Q::isEmpty()==false){
        for (int i = 0; i < count; i++) {
            f=(front+i)%size;
            cout<<*(que+f)<<endl;
        }
    }
    else
        cout<<"Queue is empty"<<endl;
}
template <class T>
Q<T>::~Q(){delete [] que;}

