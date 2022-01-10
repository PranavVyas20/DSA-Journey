#include"linked_list_1.cpp"
#include<iostream>
using namespace std;

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


void check_palindrome(Node* head)
{
    int len = len_ll(head);
    cout << "len " << len << endl;   // 1 2 2 1
    int mid = len/2;                 // i = 0th element and j will traverse till 
                                     // its corresponding to be checked ie 3rd element
    cout << "mid " << mid << endl;  // in this case (for i == 0)
    Node* temp_i = head;            // for i = 1st element       j = second last element ie 2nd element

    for (int i=0; i<=mid; i++)
    {
        Node* temp_j = temp_i; // by doing this temp_i and temp_j is on the same node
        for (int j=0; j<len-i-i-1; j++)
        {
            cout << "value j = " << j << endl;
            cout << "value i = " << i << endl;
            temp_j = temp_j -> next_address;       // here the temp_j pointer is traversing to the corresponding element
            cout<<"Tempj data="<<temp_j->data<<"address"<<endl;
            cout<<"Tempi data="<<temp_i->data<<"address"<<endl;
        }
        cout << "j data = " << temp_j->data << endl;
        cout << "i data = " << temp_i->data << endl;
        if(temp_i->data != temp_j->data) // comparing the data of both nodes
        {
            cout << "data i = " << temp_i -> data << " " << "data j = " << temp_j -> data << endl;
            cout << "no";
            return;
        }
        temp_i = temp_i -> next_address;  // traverding the temp_i 
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
