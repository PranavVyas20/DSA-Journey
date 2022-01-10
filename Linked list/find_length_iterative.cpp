#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

int find_length(Node* head){
    Node* temp = head;
    int length = 0;
    while(temp != NULL){
        temp = temp -> next_address;
        length++;
    }
    return length;
}

int main(){
Node* my_head = NULL;
my_head = take_input();

cout << find_length(my_head);
}