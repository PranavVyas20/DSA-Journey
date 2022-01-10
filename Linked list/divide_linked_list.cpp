#include <iostream>
#include "linked_list_1.cpp"
using namespace std;

Node* reverse_list(Node* head){
if (head == NULL || head->next_address == NULL){
    return head;
}
Node* new_head = reverse_list(head->next_address);
(head->next_address)->next_address = head;
head->next_address = NULL;
head = new_head;
return new_head;

}

void divide_list(Node *head){
    Node *h1 = head;
    Node *h2 = head -> next_address;
    Node *t1 = head;
    Node *t2 = head -> next_address ;
    
    while (t1 != NULL && t2 != NULL){
        t1->next_address = t2->next_address;
        t1 = t1->next_address;

        if (t1 == NULL){
            break;
        }

        t2->next_address = t1->next_address;
        t2 = t2->next_address;

    }
   
   Node* new_head1 = reverse_list(h1);
   print_linked_list(new_head1);
   cout << endl;

   Node* new_head2 = reverse_list(h2);
   print_linked_list(new_head2);
   

}

int main()
{
    Node *myhead = take_input();
    divide_list(myhead);
}
