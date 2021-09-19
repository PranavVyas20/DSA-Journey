#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

Node* union_linked_list(Node* head1,Node* head2){
    Node* newHead = head1;
    Node* last_node = head1;
    Node* tmp1 = head1;
    Node* tmp2 = head2;
    int i = 0;


    while(last_node ->next_address != NULL){
        last_node = last_node->next_address;
    }

    while(tmp2 != NULL){
        
        while(tmp1 != NULL){
            if (tmp1->data == tmp2->data){
                i = 1;
                break;
            }
            tmp1 = tmp1->next_address;
        }
         
        if (i != 1){
            last_node->next_address = tmp2;

            last_node = last_node->next_address;
            tmp2 = tmp2->next_address;
            last_node->next_address = NULL;
        }
           
        else{
        tmp2 = tmp2->next_address;
        }
        tmp1 = head1;
        i = 0;
    }
    return head1;
}
int main (){
Node* myHead1 = take_input();
Node* myHead2 = take_input();
Node* final_head = union_linked_list(myHead1,myHead2);
print_linked_list(final_head);

}