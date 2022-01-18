#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

int idx = 0;
binaryTreeNode* treeHelper(int postorder[], int si , int ei,int size){
    if(idx < 0 || postorder[idx] < si || postorder[idx] > ei ){
        return NULL;
    }
    binaryTreeNode* currentRoot = new binaryTreeNode(postorder[idx]);
    idx --;
    binaryTreeNode* m_right = treeHelper(postorder, currentRoot->data, ei,size);
    binaryTreeNode* m_left = treeHelper(postorder, si , currentRoot->data,size);
    
    currentRoot->left = m_left;
    currentRoot->right = m_right;
    return currentRoot;
}
binaryTreeNode *constructTree (int post[], int size)
{
idx = size-1;
return treeHelper(post,INT_MIN,INT_MAX,size-1);
}