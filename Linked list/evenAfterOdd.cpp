#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

int find_length(Node* head){
    Node* temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp -> next_address;
        count ++;
    }
    return count;
}

Node* even_after_odd(Node* head){
    Node* temp = head;
    Node* even_head = NULL;
    Node* even_tail = NULL;
    Node* odd_head = NULL;
    Node* odd_tail = NULL;
    int len = find_length(head);

    for (int i = 0; i < len; i++){
        if ((temp -> data) % 2 == 0){
            if (even_head == NULL){
                even_head = even_tail = temp;
            }
            else{
                even_tail->next_address = temp;
                even_tail = temp;
            }
        }
        else{
            if (odd_head == NULL){
                odd_head = odd_tail = temp;
            }
            else{
                odd_tail->next_address = temp;
                odd_tail = temp;
            }
        }
        temp = temp->next_address;
    }
    if (even_head == NULL || odd_head == NULL){
        print_linked_list(head);
    }
    else{
        odd_tail->next_address = NULL;
        even_tail->next_address = odd_head;
        print_linked_list(even_head);
    }
   
    
}
int main (){

Node* newHead = take_input();
even_after_odd(newHead);


}