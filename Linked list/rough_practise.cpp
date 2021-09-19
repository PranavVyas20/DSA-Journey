#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

void test(Node* head){
 Node* p1 = head;
 Node* p2 = head->next_address;
 Node* p2_start = p2;

 while((p2->next_address)->next_address !=NULL){
p1->next_address = p2->next_address;
p1 = p2->next_address;

p2->next_address = p1->next_address;
p2 = p1->next_address;

 }
 p1->next_address = NULL;
 p2->next_address = NULL;
 print_linked_list(head);
 cout << endl;
 print_linked_list(p2_start);
}
int main (){
Node* my = take_input();
test(my);


}