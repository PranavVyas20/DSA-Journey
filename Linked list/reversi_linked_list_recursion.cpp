#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

Node* reverse_list(Node* head){
if (head == NULL || head->next_address == NULL){
    return head;
}
Node* new_head = reverse_list(head->next_address);
Node* temp = new_head;
while(temp -> next_address != NULL){
    temp = temp->next_address;
}
temp->next_address = head;
head->next_address = NULL;
return new_head;

}
int main (){
Node* myhead = take_input();
myhead = reverse_list(myhead);
print_linked_list(myhead);


}