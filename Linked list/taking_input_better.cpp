#include <iostream>
#include "linked_list_1.cpp"
using namespace std;

Node *input_data()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *my_node = new Node(data);
        if (head == NULL)
        {
            head = my_node;
            tail = my_node;
        }
        else
        {
            tail -> next_address = my_node;
            tail = tail -> next_address;
        }
        cin >> data;
    }
    return head;
}
int main()
{
}