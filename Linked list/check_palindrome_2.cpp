#include<iostream>
#include"Linked_list_1.cpp"
using namespace std;

void check_palindrome(Node* head){
    string answer = "";
    Node* temp = head;
    while (temp != NULL)
    {
        answer = answer + to_string(temp -> data);  
        temp = temp -> next_address;
    }
    cout << "string formed of linked list data = " << answer << endl;
    int string_len = answer.length();
    cout << "length of the string formed = " << string_len << endl;
    int i = 0;
    int j = string_len - 1;
    int mid = string_len / 2;

    while(i < mid && j >= mid){
        if (answer[i] != answer[j]){
            cout << "no its not a palindrome";
            return;
        }
        i++;
        j--;
    }
    cout << "its a palindrome";
    
}
int main (){
Node* my_head = take_input();
check_palindrome(my_head);

}