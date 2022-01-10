#include <iostream>
using namespace std;

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


