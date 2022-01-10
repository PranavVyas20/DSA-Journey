#include"linked_list_1.cpp"
#include<iostream>
using namespace std;

void print_reverse(Node* head){
    Node* temp = head;
    if (temp -> next_address == NULL){
        cout << temp -> data << " ";
        return;
    }
    print_reverse(temp->next_address);
    cout << head->data << " ";
}
int main (){
Node* myhead = take_input();
print_reverse(myhead);

}