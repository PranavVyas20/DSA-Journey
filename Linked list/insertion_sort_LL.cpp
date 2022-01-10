// we basically check if the next of current node is lesser than current node
// then we place the next of currnt node to its correct postion
#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

Node*  insertion_Sort_LL(Node* head){
    // creating a dummy node
    // it will be place before the head
    Node* start = new Node(-1);

    start->next_address = head;
    // a pointer pointing to the dummy node

    Node* start_ptr = start;
    Node* current = head;

    while(current->next_address != NULL){
        if (current->next_address->data < current->data){
            // saving the node next to current
            Node* temp = current->next_address;
            // VIMP step here we are traversing 'start' till its data value is
            // less than the 'temp' node value
            //then we basically connect "pre" and "temp" node
             while((start->next_address)->data < temp->data){
                start = start->next_address;
            }
            // Nothing much just making the connections
            current->next_address = temp->next_address;
            temp->next_address = start->next_address;
            start->next_address = temp;
            // VIMP step!! basically taking "start" to its initial position
            // ie "head" node se pehle
            start = start_ptr;
        }
        else{
            current = current->next_address;
        }
    }
    // since start data is -1 we dont want that 
    // hence the real linked list starts from next of "start"
    head = start->next_address;
    return head;
}
int main (){
    Node* h1 = take_input();
   h1 = insertion_Sort_LL(h1);
   print_linked_list(h1);
  

}