#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

class mPair{
    public:
    int m_min;
    int m_max;
    bool isBst;
    mPair(int m_max,int m_min,bool isBst){
        this -> m_max = m_max;
        this -> m_min = m_min;
        this -> isBst = isBst;
    }
};

// Pair class method
mPair isBST(binaryTreeNode * root){
    if(root == NULL){
        mPair bPair(INT_MIN,INT_MAX,true);
        return bPair;
    }
    mPair leftPair = isBST(root->left);
    mPair rightPair = isBST(root->right);
    bool ans_isBST = (leftPair.isBst && rightPair.isBst) 
    && (root->data > leftPair.m_max && root->data < rightPair.m_min);
    int ans_max = max(root->data,max(leftPair.m_max,rightPair.m_max));
    int ans_min = min(root->data,min(leftPair.m_min,rightPair.m_min));
    mPair ans(ans_max,ans_min,ans_isBST);
    return ans;
    
}
// Using the range method (Striver)
bool isBST(binaryTreeNode* root,int minVal,int maxVal){
    if(!root){
        return true;
    }
    if(root->data >= maxVal || root->data <= minVal) return false;
    return isBST(root->left,INT_MIN,root->data) && isBST(root->right,root->data,INT_MAX);
}