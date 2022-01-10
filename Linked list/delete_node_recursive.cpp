#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

Node* delete_node_rec(Node* head,int pos){
    if (head == NULL){
        return head;
    }
    else if (pos == 0){
        Node* new_head = head -> next_address;
        delete(head);
        head = new_head;
        return head;
    }
    else{
        Node* x = delete_node_rec(head -> next_address,pos - 1);
        head -> next_address = x;
        return head;

    }
}
int main (){
Node* my_head = take_input();
my_head = delete_node_rec(my_head,2);
print_linked_list(my_head);

}