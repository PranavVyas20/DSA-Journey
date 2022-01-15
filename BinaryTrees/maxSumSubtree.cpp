#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

// Travel and solve 
//  Do post order traversal of the binary tree. At every node, 
// find left subtree value and right subtree value recursively. 
// The value of subtree rooted at current node is equal
// to sum of current node value,left node subtree sum and right node subtree sum. 
// Compare current subtree sum with overall maximum subtree sum so far.

int maxSum = INT_MIN;
int maxSumSubtree(binaryTreeNode* node){
    if(node == NULL){
        return 0;
    }
    int ls = maxSumSubtree(node->left);
    int rs = maxSumSubtree(node->right);

    if(ls + rs + node->data > maxSum){
        maxSum = ls + rs + node->data;
    }
    // above can be written as : maxSum = max(maxSum,ls + rs + node->data);
    return ls + rs + node->data;
}