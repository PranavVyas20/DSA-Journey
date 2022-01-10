#include<iostream>
using namespace std;
#include"linked_list_1.cpp"

Node* last_be_first(Node* head){
    Node* last_node = head;
    Node* temp = head;
    
    if (head->next_address == NULL){
        return head;
    }
    while(last_node->next_address->next_address != NULL){
        last_node = last_node->next_address;
    }
    head = last_node->next_address;
    last_node->next_address = NULL;
    head->next_address = temp;
    return head;

}
int main (){
Node* my_head = take_input();
my_head = last_be_first(my_head);
print_linked_list(my_head);

}