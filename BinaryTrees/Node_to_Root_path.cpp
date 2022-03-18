#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include "BinaryTree.h"

// Check weather the keyData is found in left or right child
// add the node data only when it is found in any of the above child
vector<int> ans;
bool nodeToRootPath(binaryTreeNode *node, int keyData){
    if (node == NULL){
        return false;
    }
    if (node->data == keyData){
        ans.push_back(node->data);
        return true;
    }

    bool foundInLeftChild = nodeToRootPath(node->left, keyData);
    if (foundInLeftChild){
        ans.push_back(node->data);
        return true;
    }
    bool foundInRightChild = nodeToRootPath(node->right, keyData);
    if (foundInRightChild){
        ans.push_back(node->data);
        return true;
    }
    // if not found in leftChild nor in the rightChild then return false
    return false;
}

int main()
{
}