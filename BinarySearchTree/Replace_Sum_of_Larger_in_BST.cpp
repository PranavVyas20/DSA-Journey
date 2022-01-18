#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"bst.h"

int sumTill = 0;
void inorderReverse(binaryTreeNode* node){
    if(node == NULL){
        return;
    }
    inorderReverse(node->right);
    int orgData = node->data;
    node->data = node->data + sumTill;
    sumTill+=node->data;
    cout << node->data << " ";
    inorderReverse(node->left);
}
int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    binaryTreeNode* root = createBST(v,0,6);
    inorderReverse(root);


}