#include<iostream>
using namespace std;

class stackUsingArray{
    int *dataArray ;
    int nextIndex;
    int capacity;

    public:
    stackUsingArray(int totalSize){
         dataArray = new int[totalSize];
         nextIndex = 0;
         capacity = totalSize;
    }

    // returns the total no's of elements present in the stack
    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(int element){
        if(nextIndex == capacity){
            cout << "stack full" << endl;
            return;
        }  
        dataArray[nextIndex] = element;
        nextIndex++;
    }

    int pop(){
        nextIndex--;
         if (nextIndex < 0){
            cout << "stack empty" << endl;
            return -1;
        }
        return dataArray[nextIndex];
    }

    int top(){
        if (isEmpty()){
            cout << "stack empty" << endl;
            return -1; 
        }
        return dataArray[nextIndex - 1];
    }
};

