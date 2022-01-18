#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"bst.h"

binaryTreeNode* insertIntoBST(binaryTreeNode* root, int val) {
    if(root == NULL){
        binaryTreeNode* newBstNode = new binaryTreeNode(val);
        return newBstNode;
    }
    if(val < root->data){
        binaryTreeNode* newNode = insertIntoBST(root->left,val);
        root->left = newNode;
    }
    else if(val > root->data){
        binaryTreeNode* newNode = insertIntoBST(root->right,val);
        root->right = newNode;
    }
    return root;
}