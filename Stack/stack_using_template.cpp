#include<iostream>
using namespace std;
template<typename T>

class stackUsingArray{
    T *dataArray ;
    int nextIndex;
    int capacity;

    public:
    stackUsingArray(){
         dataArray = new T[4];
         nextIndex = 0;
         capacity = 4;
    }

    // returns the total no's of elements present in the stack
    int size(){
        return nextIndex;
    }

    bool isEmpty(){
        return nextIndex == 0;
    }

    void push(T element){
        if(nextIndex == capacity){
           T* newDataArray = new T [2 * capacity];
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

    T pop(){
        nextIndex--;
         if (nextIndex < 0){
            cout << "stack empty" << endl;
            return 0;
        }
        return dataArray[nextIndex];
    }

    T top(){
        if (isEmpty()){
            cout << "stack empty" << endl;
            return 0; 
        }
        return dataArray[nextIndex - 1];
    }
};
int main (){
stackUsingArray <char> s;
s.push(100);
s.push(102);
s.push(103);
s.push(104);

// s.push('a');
// s.push('b');

cout << s.top() << endl;
cout << s.pop() << endl;
cout << s.top();

}