#include<iostream>
#include"linked_list_1.cpp"
using namespace std;

int find_node(Node* head,int key,int index){
    // will return -1 if the key is not present in the list || man le last node pr pohoch gye or ye bhi key ni hai
    // then again it will call find_node(head.next) now in this case head.next will be null........... ab samjha ?
    if (head == NULL){
        return -1;
    }
    // base case as well as apna kaam 
    if (head->data == key){
        return index;
    }
    return find_node(head->next_address,key,index+1);
}
int main (){
int key;
Node* myhead = take_input() ;
cout << endl << "enter key data: " ;
cin >> key;
cout << find_node(myhead,key,0);

}