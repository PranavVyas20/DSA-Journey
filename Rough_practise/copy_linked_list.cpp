#include"linked_list_1.cpp"
#include<iostream>
using namespace std;

Node* copy_list(Node* head){
Node* new_head = NULL;
Node* new_tail = NULL;
Node* temp = head;

while(temp!=NULL){
if (new_head == NULL){
        Node* new_Node = new Node(temp->data);
        new_head = new_tail = new_Node;
        temp = temp->next_address;
}
else{
    Node* second_node = new Node(temp->data);
    new_tail->next_address = second_node;
    new_tail = new_tail->next_address;
    new_tail->next_address = NULL;
    temp = temp->next_address;
}
}
return new_head;

}

int main(){
Node* myHead = take_input();
Node* newl = copy_list(myHead);
print_linked_list(newl);


}
