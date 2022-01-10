#include<iostream>
using namespace std;

template<typename T>
class node{
    public:
    T data;
    node<T> *next;

    node(T data){
        this->data = data;
        next = NULL;
    }
};

template<typename T>
class stackUsingLL{
       node<T> *head;
       int size;

    public:
    // Constructor
    stackUsingLL(){
        head = NULL;
        size = 0;
    }

    void push(T element){
        node<T> *new_node = new node<T>(element);

        if (head == NULL){
            head = new_node;
        }
        else{
            new_node->next = head;
            head = new_node;
        }
        size++;
    }

    bool isEmpty(){
        return head == NULL;
    }

    T top(){
        return head->data;
    }

    void pop(){
        if(isEmpty()){
            cout << "stack empty" << endl;
            return;
        }
        node<T> *temp = head->next;
        cout << head->data << " popped" << endl;
        delete(head);
        head = temp;   
        size --;
    }

     // return the no of elements present in the stack
    int getSize(){
        return size;
    }
};

int main (){
stackUsingLL<int> s;

s.push(10);
s.push(20);
s.push(30);
s.push(40);

cout << "size " << s.getSize() << endl;

 cout << s.top () << endl;
 s.pop() ;
 s.pop() ;
 s.pop() ;
 s.pop() ;
 s.pop();

cout << "size " << s.getSize() << endl;

cout << s.top() << endl;


}