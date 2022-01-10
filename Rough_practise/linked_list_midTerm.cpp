#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next ;

    node(int data){
        this -> data = data;
        next = NULL;
    }
};
void print_list(node* head){
    node* temp = head;
    while (temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    } 
}

node* insert_beginning(node* head,int new_data){
    node* new_node = new node(new_data);
    new_node -> next = head;
    head = new_node;
    return head;
}

void insert_end(node* head,int new_data){
    node* temp = head;
    node* new_node = new node(new_data);
    while(temp -> next != NULL){
        temp = temp -> next;
    }
    temp ->next = new_node;

}
int main (){

    node n1(10);
    node* head = &n1;
    node n2(20);
    node n3(30);
    node n4(40);
    node n5(50);

    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    n5.next = NULL;

    insert_end(head,200);    
    print_list(head);

}