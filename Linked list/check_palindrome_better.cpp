#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

int find_Length(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp!= NULL){
        temp = temp->next_address;
        count ++;
    }
    return count;
}

Node* reverse_linked_list(Node* head){
    Node* temp = head;
    if (temp->next_address == NULL){
        return temp;
    }
    Node* smaller_head = reverse_linked_list(head->next_address);
    head->next_address->next_address = head;
    head->next_address = NULL;
    head = smaller_head;
    return head;
}

bool check_palindrome(Node* head){
if(head->next_address == NULL || head == NULL){
    return false;
}
Node* travel_node = head;
Node* new_head = NULL;

// travelling to the middle node
int length = find_Length(head);
// cout << "lenght:" << length << endl;
for (int i = 0; i < (length - 1) / 2; i++){
   
    travel_node = travel_node->next_address;
}
    // cout << "travel node1 data: " << travel_node->data << endl;

new_head = travel_node->next_address;
travel_node->next_address = NULL;
travel_node = head;

Node* reversed_head = reverse_linked_list(new_head);
Node* travel_node2 = reversed_head;
// print_linked_list(travel_node2);

// now comparing the nodes to check for palindrome
while(travel_node!=NULL && travel_node2!=NULL){
    // cout << "data 1: " << travel_node->data << " data2: " << travel_node2->data << endl;
    if (travel_node->data!=travel_node2->data){
        // cout << "no";
        return false;
    }
    travel_node = travel_node->next_address;
    travel_node2 = travel_node2->next_address;
}
// cout << "yes";
return true;

}
int main (){
Node* myHead = take_input();
cout << check_palindrome(myHead);


}