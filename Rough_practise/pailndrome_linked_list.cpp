#include<iostream>
using namespace std;

// ignore these plsss 
class Node
{
  // Data members
public:
  int data;
  Node *next_address;

  // Constructor
  Node(int data)
  {
    this->data = data;
    next_address = NULL;
  }
};

Node* insert_node(Node *head, int position, int data){
    // cout << "insert method called" << endl;
    // cout << "pos " << position << " " << "data " << data << endl;
    Node *new_node = new Node(data);
    int i = 0;
    Node *temp = head;

// hadnling the case when pos is 0

   if (position == 0){
       new_node -> next_address = head;
       head = new_node;
       return head;
   }
// Traversing head to get to the position - 1 th node
    while (temp != NULL && i < position - 1){
        temp = temp -> next_address;
        i++;
    }

    if (temp != NULL){
    Node *next_temp = temp -> next_address;
    temp -> next_address = new_node;
    new_node -> next_address = next_temp;
    }
   return head;
}

void print_linked_list(Node *head){
    Node *temp = head;
    while (temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next_address;
    }
}

Node *take_input(){
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while (data != -1){
        Node *new_node = new Node(data);

        if (head == NULL){
            head = new_node;
            tail = new_node;
        }
        else{
            tail -> next_address = new_node;
            tail = tail -> next_address;
        }
        cin >> data;
    }
    return head;
}

Node* delete_node(Node* head,int pos){
     int i = 0;
     Node* temp = head;

//
     if (pos == 0){
       head = temp -> next_address;
       delete(temp);
       return head;
     }

     while( i < pos - 1){
         temp = temp -> next_address;
         i++;
     }
     // connecting nodes skipping the ith node to be deleted
     Node* a = temp -> next_address;
     Node* b = a -> next_address;

     temp -> next_address = b;

     // actually deleting the ith node
     delete(a);
    return head;

     
}

// function for calculating length of list
int len_ll(Node* my_len_head)
{
    Node* temp = my_len_head;
    int count = 0;
    while(temp != NULL)
    {
        temp = temp -> next_address;
        count ++;
    }
    return count;
}








// Main function 
void check_palindrome(Node* head)
{
    int len = len_ll(head);
    int mid = len/2;
   
   
    Node* temp_i = head;
    for (int i=0; i<mid; i++)
    {
        Node* temp_j = temp_i;
        for (int j=0; j<len -i-i-1; j++)
        {
            temp_j = temp_j->next_address;
        }
        if(temp_i->data != temp_j->data)
        {
            cout << "data i = " << temp_i->data << " " << " data j = " << temp_j->data << endl;
            cout << "no";
            return;
        }
        temp_i = temp_i->next_address;
    }
    cout << "yes" ;
}
int main ()
{
Node* myhead = take_input();
print_linked_list(myhead) ;
cout << endl;
check_palindrome(myhead);
}