#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

int length_LL(Node* head){
    int length = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp->next_address;
        length ++;
    }
    return length;
}

Node* bubble_Sort_LL(Node* head){
int len = length_LL(head);

for (int i = 0; i < (len); i++){
    Node* current = head;
    Node* pre = NULL;

    while(current->next_address!=NULL){
        if (current->data > (current->next_address)->data){
            // basically checking if in first iteration 
            // the first element if greater than its next 
            // because its a special case because the head will be changed
            if (pre == NULL){  
                Node* nxt = current->next_address; 
                current->next_address = nxt->next_address;//
                nxt->next_address = current;
                head = nxt;
                pre = nxt;
            }
            //
            else{
                Node* nxt = current->next_address;
                pre->next_address = current->next_address;
                current->next_address = nxt->next_address;
                nxt->next_address = current;
                pre = pre->next_address;
            }
        }
        else{
            pre = current;
            current = current->next_address;
        }
    }
}
    return head;

}

int main (){
Node* h1 = take_input();
h1 = bubble_Sort_LL(h1);
print_linked_list(h1);

}