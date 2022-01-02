#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

bool pathSum(binaryTreeNode* root,int target){
    if(root == NULL){
        return false;
    }
    if(!root->left && ! root->right){
        return target-root->data == 0;
    }
    bool left = pathSum(root->left,target-root->data);
    bool right = pathSum(root->right,target-root->data);
    return left||right;
}