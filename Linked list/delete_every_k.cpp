#include<iostream>
using namespace std;
#include"linked_list_1.cpp"

Node* delete_k(Node* head,int m,int n){
    Node* temp = head;
    Node* last_node = head;

    while(true){
        for (int i = 0; i < m-1; i++){
            last_node = last_node->next_address;
        }
        temp = last_node->next_address;
        if (temp == NULL || temp->next_address == NULL){
             last_node->next_address = NULL;
                return head;
            }

        for (int j = 0; j < n; j++){
            temp = temp->next_address;
            if (temp == NULL || temp->next_address == NULL){
                last_node->next_address = NULL;
                return head;
            }
        }
        last_node->next_address = temp;
        last_node = temp;
}
}

int main (){
Node* my_head = take_input();
my_head = delete_k(my_head,3,2);
print_linked_list(my_head);

}
