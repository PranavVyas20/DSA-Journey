#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

Node* reverse_linked_list(Node* head){
    if (head -> next_address == NULL|| head == NULL){
        return head;
    }
    Node* smaller_head = reverse_linked_list(head -> next_address);
    // bhot dimag lagane wala step 
    // example list - 1 2 3 4 5 
    // after making the call
    // list - [1] [5 4 3 2] 
    // smaller head = 5 but still head = 1 and head.next = 2
    // so head.next.next = head     => 2 ka next mein original head dalna
    (head -> next_address) -> next_address = head;
    head -> next_address = NULL;
    head =  smaller_head;
    return head;
}

int main (){
    Node* myhead = take_input();
    myhead = reverse_linked_list(myhead);
    print_linked_list(myhead);
   
}