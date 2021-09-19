#include<iostream>
#include"linked_list_1.cpp"

int find_len(Node* head){
    int count = 0;
    Node* temp = head;
    while(temp != NULL){
        temp = temp -> next_address;
        count ++;
    }
    return count;
}


void print_reverse(Node* head){
    Node* temp = head;
    int len = find_len(head);
    int c = len -1;

    for (int i = 0; i < len -1; i++){
        
        for (int j = 0; j < c; j++){
            temp = temp -> next_address;
        }
        cout << temp -> data << " ";
        c--;
        temp = head;
    }
    cout << head -> data;
}
using namespace std;
int main (){
    Node* myhead = take_input();
print_reverse(myhead);

}