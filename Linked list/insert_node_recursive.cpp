#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

Node* insert_node_rec(Node* head,int data,int pos){
    // if the list is empty then simply return
    if (head == NULL){
        return head;
    }
    // this is the case which we have to handle 
    // basically if we want to insert the node at 0th positon
    else if (pos == 0){
        Node* new_node = new Node(data);
        new_node -> next_address = head;
        head = new_node;
        return head;
    }
    // this part is handled by recursion now
    else{
        Node* x = insert_node_rec(head -> next_address,data,pos - 1);
        head -> next_address = x;
        return head;
    }
}

int main (){
Node* my_head = take_input();
my_head = insert_node_rec(my_head,100,7);
print_linked_list(my_head);

}