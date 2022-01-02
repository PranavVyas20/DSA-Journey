#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

vector<string> ans;
void leafToRootPath(binaryTreeNode* root,string str){
    if(root == NULL){
        return ;
    }
    if(!root->left && !root->right){
        ans.push_back(str+to_string(root->data));
    }
    leafToRootPath(root->left,str+to_string(root->left->data)+"->");
    leafToRootPath(root->right,str+to_string(root->right->data)+"->");
}