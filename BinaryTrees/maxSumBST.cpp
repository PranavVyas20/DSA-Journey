#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

// Same exactly as maxBSTSubtree.
class mPair{
    public:
    int m_min;
    int m_max;
    int m_sum;
    bool m_isBst;
};

mPair helper(binaryTreeNode* root){
    if(root == NULL){
        mPair bPair;
        bPair.m_min = INT_MAX;
        bPair.m_max = INT_MIN;
        bPair.m_sum = 0;
        bPair.m_isBst = true;
        return bPair;
    }
    mPair leftPair = helper(root->left);
    mPair rightPair = helper(root->right);
    mPair ansPair;
    ansPair.m_isBst = (leftPair.m_isBst && rightPair.m_isBst) && 
                      (root->data > leftPair.m_max && root->data < rightPair.m_min);
    ansPair.m_min = min(root->data,min(leftPair.m_min,rightPair.m_max));
    ansPair.m_max = max(root->data,max(leftPair.m_max,rightPair.m_max));

    if(ansPair.m_isBst){
        ansPair.m_sum = root->data + leftPair.m_sum + rightPair.m_sum;
    }
    else if(leftPair.m_sum > rightPair.m_sum){
        ansPair.m_sum = leftPair.m_sum;
    }
    else{
        ansPair.m_sum = rightPair.m_sum;
    }
    return ansPair;
}