#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"  

binaryTreeNode* constructTree(vector<int> inorder, int si, int ei){
    if(si > ei ){
        return NULL;
    }
    int midIndexRoot = (ei + 1) / 2 ; // size / 2;
    binaryTreeNode* currentRoot = new binaryTreeNode(inorder[midIndexRoot]);
    binaryTreeNode* m_left = constructTree(inorder,si,midIndexRoot - 1);
    binaryTreeNode* m_right = constructTree(inorder,midIndexRoot+1,ei);
    currentRoot->left = m_left;
    currentRoot->right = m_right;
    return currentRoot;
}