#include <iostream>
#include "linked_list_1.cpp"
using namespace std;

void print_linked_list(Node *head)
{
    Node *temp = head;
    while (temp  != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next_address;
    }
}
Node *input_data()
{
    int data;
    cin >> data;
    Node *head = NULL;
    while (data != -1)
    {
        Node *my_node = new Node(data);
        if (head == NULL)
        {
            head = my_node;
        }
        else
        {
            Node *temp_head = head;
            while (temp_head -> next_address != NULL)
            {
                temp_head = temp_head->next_address;
            }
            temp_head->next_address = my_node;
        }
        cin >> data;
    }
    return head;
}

int main()
{
    Node *head2 = input_data();
    print_linked_list(head2);
}