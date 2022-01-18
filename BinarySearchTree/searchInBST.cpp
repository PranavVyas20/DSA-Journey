#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"bst.h"

    binaryTreeNode* ansNode = NULL;
    
    void helperFn(binaryTreeNode* root,int val){
        if(root == NULL){
            return ;
        }
        else if(val == root->data){
            ansNode = root;
            return;
        }
        if(val < root->data){
            helperFn(root->left,val);
        }
        else if(val > root->data){
            helperFn(root->right,val);
        }
    }
    binaryTreeNode* searchBST(binaryTreeNode* root, int val) {
        helperFn(root,val);
        return ansNode;
    }

int main(){
    
}