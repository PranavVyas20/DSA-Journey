#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

Node* swap_nodes(Node* head,int i,int j){
    Node* pre_1 = NULL;
    Node* pre_2 = NULL;
    Node* current_1 = NULL;
    Node* current_2 = NULL;
    Node* temp = head;

// handling the case when element to be swapped are 0th and 1st;
  if ((i == 0 && j ==1) || (i==1 && j==0)){
    cout << "entered " << endl;

    // initialising the pointers to 0th element and 1st element
    current_1 = temp;
    current_2 = current_1 -> next_address;

    // Connecting the correct nodes
    pre_2 = current_2 -> next_address;
    current_2 ->next_address = current_1;
    current_1 -> next_address = pre_2;
    head = current_2;
    return head;
  }

// handling the case when the nodes to be swapped are adjacent to each other
  else if (i-j == 1 || i-j == -1){
      int minn = min(i,j);
      for(int i = 0; i < minn-1; i++){
          temp = temp -> next_address;
      }
      // Initiallising the pointers to ith and jth and pre nodes
      pre_1 = temp;
      current_1 = pre_1 -> next_address;
      current_2 = current_1 -> next_address;

      // connecting the nodes 
      pre_1 -> next_address = current_2;
      current_1 -> next_address = current_2 -> next_address;
      current_2 -> next_address = current_1;
      return head;
  }
  
  // handling the case when i or j == 0
  else if (i==0 || j==0){
    
      int maxx = max(i,j);
      for (int k=0; k < maxx - 1; k++){
          // cout << temp -> data << " " ;
          temp = temp -> next_address;
      }

    // initiallising the pointer on the ith and jth node
    // these are correct - checked via debugging
    current_1 = head;
    pre_2 = temp;
    current_2 = temp -> next_address;
   
    // Connecting the nodes
    pre_2 -> next_address = current_1;
    pre_1 = current_2 -> next_address;

    current_2 -> next_address = current_1 ->next_address;
    current_1 -> next_address = pre_1;

    head = current_2;
    return head;
      
  }

  else{
    // first loop to reach the i - 1 th node
    for (int k = 0; k < i-1; i++){
    temp = temp -> next_address;
    }
    pre_1 = temp;
    current_1 = temp -> next_address;

    // second loop to reach j-1 th node
    temp = head;
    for (int k = 0; k < j-1; k++){
         temp = temp -> next_address;
    }
    pre_2 = temp;
    current_2 = temp -> next_address;
     
    // connecting the correct nodes
    pre_1 -> next_address = current_2;
    pre_2 -> next_address = current_1;

    Node* c1_next = current_1 -> next_address;

    current_1 -> next_address = current_2 -> next_address;
    current_2 -> next_address = c1_next;
    return head;
  }

}

int main (){
Node* my_head = take_input();
cout << "original list:" << endl;
print_linked_list(my_head);
cout << endl;
cout << "after swapping:" << endl;
my_head = swap_nodes(my_head,3,0);
print_linked_list(my_head);

}