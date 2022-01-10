#include<iostream>
using namespace std;

class Node{
// Data members
public:
int data;
Node* next;

// Constructor
Node(int data){
    this -> data = data;
    next = NULL;
  }
};

void print_nodes(Node* head){
    while(head != NULL){
        cout << head -> data << " " ;
        head = head -> next;
    }
}

int main (){
// Creating nodes statically
Node n1(10);
Node *head = &n1;

Node n2(20);
Node n3(30);
Node n4(40);
Node n5(50);

n1.next = &n2;
n2.next = &n3;
n3.next = &n4;
n4.next = &n5;

print_nodes(head);
}