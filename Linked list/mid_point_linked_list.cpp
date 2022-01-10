#include"linked_list_1.cpp"
#include<iostream>
using namespace std;

int find_length(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!= NULL){
        temp = temp->next_address;
        count++;
    }
    return count;
}
int midpoint(Node* head){
Node* temp = head;
int length = find_length(head);
if (length % 2 == 0){
    for (int i = 0; i < (length-1) / 2; i++){
        temp = temp->next_address;
    }
    return temp->data;
}
else{
    for (int i = 0; i < length / 2; i++){
        temp = temp->next_address;
    }
    return temp->data;
}

}
int main (){
Node* myhead = take_input();
cout << midpoint(myhead);

}