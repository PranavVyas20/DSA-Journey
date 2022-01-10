#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

void intersection(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* new_head = NULL;
    Node* new_tail = NULL;

    while(temp1 != NULL){
        while(temp2 != NULL){
            if (temp1->data == temp2->data){
                if (new_head == NULL){
                    new_head = new_tail = new Node(temp1->data);
                    break;
                }
                else{
                    Node* second_node = new Node(temp1->data);
                    new_tail->next_address = second_node;
                    new_tail = second_node;
                    new_tail->next_address = NULL;
                    break;
                }
            }
            temp2 = temp2->next_address;
        }
        temp2 = head2;
        temp1 = temp1->next_address;
    }
    print_linked_list(new_head);
}
