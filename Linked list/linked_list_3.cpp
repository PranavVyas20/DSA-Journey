#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next_address;

    Node(int data){
        this -> data = data;
        this ->next_address = NULL;
    }
};

    void print_linked_list(Node *head){
    while(head != NULL){
        cout << head -> data << " ";
        head = head -> next_address;
    }
}

int main (){
// creating nodes dynamically

    Node *n1 = new Node(10);
    Node *head = n1;

    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    Node *n5 = new Node(50);

    // saving the address
    n1 -> next_address = n2;
    n2 -> next_address = n3;
    n3 -> next_address = n4;
    n4 -> next_address = n5;

    print_linked_list(head);

}