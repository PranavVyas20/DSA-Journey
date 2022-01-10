#include<iostream>
#include"linked_list_1.cpp"
using namespace std;


int length_recursive(Node* head){
    Node* temp  = head;
    // base case
    if (temp -> next_address == NULL){
        return 1;
    }

    int smaller = length_recursive(temp -> next_address);
    return smaller + 1;
}
int main (){
Node* my_head = NULL;
my_head = take_input();
cout << length_recursive(my_head);


}