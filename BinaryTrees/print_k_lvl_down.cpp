#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<BinaryTree.h>

vector<int> ans;
void printKLvl(binaryTreeNode* node,int k){
    if(node == NULL || k < 0){
        return;
    }
    if(k == 0){
        ans.push_back(node->data);
        return
    }
    printKLvl(node->left,k-1);
    printKLvl(node->right,k-1);
}