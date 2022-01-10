#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

Node* merge_LL(Node* head1,Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* new_head = NULL;
    Node* new_tail = NULL;

    while(temp1 != NULL && temp2 != NULL){
        if (temp1->data < temp2->data){
            if (new_head == NULL){
                Node* new_Node = new Node(temp1->data);
                new_head = new_tail = new_Node;
                temp1 = temp1->next_address;
                // new_tail = new_tail->next_address;
                new_tail->next_address = NULL;
            }
            else{
                Node* new_Node2 = new Node(temp1->data);
                new_tail->next_address = new_Node2;
                temp1 = temp1->next_address;
                new_tail = new_tail->next_address;
                new_tail->next_address = NULL;
            }
        }
        else{
            if (new_head == NULL){
                Node* new_Node = new Node(temp2->data);
                new_head = new_tail = new_Node;
                temp2 = temp2->next_address;
                // new_tail = new_tail->next_address;
                new_tail->next_address = NULL;
            }
            else{
                Node* new_Node2 = new Node(temp2->data);
                new_tail->next_address = new_Node2;
                temp2 = temp2->next_address;
                new_tail = new_tail->next_address;
                new_tail->next_address = NULL;
            }
        }
    }
    while(temp1 != NULL){
        Node* newnode = new Node(temp1->data);
        new_tail->next_address = newnode;
        temp1 = temp1->next_address;
        new_tail = new_tail->next_address;
        new_tail->next_address = NULL;
        }
    while(temp2 != NULL){
        Node* newnode = new Node(temp2->data);
        new_tail->next_address = newnode;
        temp2 = temp2->next_address;
        new_tail = new_tail->next_address;
        new_tail->next_address = NULL;
        }
        
    return new_head;
}

int main (){
Node* h1 = take_input();
Node* h2 = take_input();
Node* h3 =   merge_LL(h1,h2);
print_linked_list(h3);

}