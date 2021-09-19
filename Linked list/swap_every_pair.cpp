#include<iostream>
using namespace std;
#include"linked_list_1.cpp"

Node* swap_every_pair(Node* head){
    Node* t1 = head;
    Node* t2 = t1->next_address;
    Node* t3 = NULL;
    int count  = 0;

    if (t2->next_address == NULL){
        head = t2;
        t2->next_address = t1;
        t1->next_address = NULL;
        return head;
    }

    while(t1 != NULL && t2 != NULL){
        if (count == 0){
            t1->next_address = t2->next_address;
            t2->next_address = t1;
            head = t2;
            t3 = t1;
            count ++;
        }
        else{
            if (t2->next_address == NULL){
                t3->next_address = t2;
                t2->next_address = t1;
                t1->next_address = NULL;
                break;
            }
            t1->next_address = t2->next_address;
            t2->next_address = t1;
            t3->next_address = t2;
            t3 = t1;
        }
    t1 = t1->next_address;
    t2 = t1->next_address;
    }
    return head;
}
int main (){
Node* h1 = take_input();
h1 = swap_every_pair(h1);
print_linked_list(h1);

}