#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

Node* insert_recursion(Node* head, int data,int pos){
    if (head == NULL || pos == 0){
        Node* newNode = new Node(data);
        newNode->next_address = head;
        head = newNode;
        return head;
    }
    head->next_address = insert_recursion(head->next_address,data,pos - 1);
}
int main (){
Node* myHead = take_input();
print_linked_list(myHead);
cout << endl;
print_linked_list(insert_recursion(myHead,100,5));

}