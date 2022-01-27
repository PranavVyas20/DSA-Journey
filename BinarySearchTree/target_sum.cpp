#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"bst.h"

    bool isElementPresent(binaryTreeNode* node,int key){
        if(node == NULL){
            return false;
        }
        if(key < node->data){
            return isElementPresent(node->left,key);
        }else if(key > node->data){
            return isElementPresent(node->right,key);
        }else{
            return true;
        }
    }
int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    binaryTreeNode* root = createBST(v,0,6);
    cout << isElementPresent(root,0);
}