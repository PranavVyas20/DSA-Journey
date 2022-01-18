#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

binaryTreeNode* createBST(vector<int> v,int si, int ei){
    if(si > ei ){
        return NULL;
    }
    int midIndexRoot = (ei + si) / 2 ; // size / 2;
    binaryTreeNode* currentRoot = new binaryTreeNode(v[midIndexRoot]);
    binaryTreeNode* m_left = createBST(v,si,midIndexRoot - 1);
    binaryTreeNode* m_right = createBST(v,midIndexRoot+1,ei);
    currentRoot->left = m_left;
    currentRoot->right = m_right;
    return currentRoot;
}