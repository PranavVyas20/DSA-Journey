#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

int idx = 0;
binaryTreeNode* treeHelper(vector<int> preorder, int si, int ei){
    if(idx >= preorder.size() || preorder[idx] > ei || preorder[idx] < si){
        return NULL;
    }
    binaryTreeNode* currentRoot = new binaryTreeNode(preorder[idx]);
    idx++;
    binaryTreeNode* m_left = treeHelper(preorder ,si ,currentRoot->data);
    binaryTreeNode* m_right = treeHelper(preorder ,currentRoot->data,ei);

    currentRoot->left = m_left;
    currentRoot->right = m_right;
    return currentRoot;

}
