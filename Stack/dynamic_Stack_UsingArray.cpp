#include<iostream>
using namespace std;

// Now we dont have to worry about the size of our array
// beacuse we are increasing our array size in every push function
class stackUsingArray{
    int *dataArray ;
    int nextIndex;
    int capacity;

    public:
    stackUsingArray(){
         dataArray = new int[1];
         nextIndex = 0;
         capacity = 1;
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
           int* newDataArray = new int [capacity * 2];
           for (int i = 0; i < capacity; i++){
               newDataArray[i] = dataArray[i];
           }
           capacity *= 2;
           delete [] dataArray;
           dataArray = newDataArray;
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

int main (){
    
stackUsingArray s1;

s1.push(10);
s1.push(20);
s1.push(30);
s1.push(40);
s1.push(50);
s1.push(60);

cout << s1.top() << endl;
cout << s1.pop() << endl;
cout << s1.pop() << endl;
cout << s1.pop() << endl;
cout << s1.top() << endl;
cout << s1.isEmpty();




}