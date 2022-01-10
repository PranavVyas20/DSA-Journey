#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

int find_length(Node* head){
  int count = 0;
  Node* temp = head;
  while(temp != NULL){
        temp = temp -> next_address;
        count ++;
  }
  return count;
}

Node* odd_even(Node* head){
  int len = find_length(head);
  cout << "len = " << len << endl;
  Node* temp = head;
  Node* start = head;
  Node* end = head;
  int temp_count = 0;
  
  for (int i = 0; i < len - 1; i++){
    end = end -> next_address;   // now end pointind to the last node of the list
  }

  for (int i = 0; i < len - 1; i++){
   
    if ((temp -> data) % 2 == 0){ // checking condition if the node is even or odd

      for (int i = 0; i < temp_count - 1; i++){ // loop for taking the pointer 'start' to 
        start = start -> next_address;            // just before the temp
      }
      start -> next_address = temp -> next_address;
      end -> next_address = temp;
      temp -> next_address = NULL;
      end = end -> next_address;
      temp = start -> next_address;
    }
    else{
       temp  = temp -> next_address;
       temp_count++;
    }
   
  }

}

int main (){
Node* myhead = take_input();

print_linked_list(myhead);

cout << endl;

myhead = odd_even(myhead);

print_linked_list(myhead);
}