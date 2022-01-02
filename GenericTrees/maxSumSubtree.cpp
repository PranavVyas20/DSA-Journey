#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"TreeNode.h"

class mPair{
    public:
    int maxSum;
    TreeNode* maxNode;
};

// Travel and solve method;
int maxSum = INT_MIN;
int returnSumFindMaxSum(TreeNode* root){
    int childSum = 0;
    if(root->children.size() == 0){
        return root->data;
    }
    for(int i = 0; i < root->children.size(); i++){
        childSum += returnSumFindMaxSum(root->children[i]);
    }
    if (childSum + root->data > maxSum){
        maxSum = childSum;
    }
    return childSum+root->data;
}

// Using the pair class method
// Cant be done with this method !!!!
mPair maxSumSubtree(TreeNode* root){
    if(root->children.size() == 0){
        mPair bPair;
        bPair.maxSum = root->data;
        bPair.maxNode = root;
        return bPair;
    }
    for(int i = 0; i < root->children.size(); i++){
        mPair cPair = maxSumSubtree(root->children[i]);
    }
}