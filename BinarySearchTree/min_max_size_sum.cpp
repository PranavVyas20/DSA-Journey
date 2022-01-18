#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// #include"BinaryTree.h"
#include"bst.h"

int m_max = 0;
int m_min = 0;
int m_size = 0;
int m_sum = 0;

void findMaxBst(binaryTreeNode* Node){
    if(Node == NULL){
        return;
    }
    m_max = Node->data;
    findMaxBst(Node->right);
}

void findMinBst(binaryTreeNode* node){
    if(node == NULL){
        return;
    }
    m_min = node->data;
    findMinBst(node->left);
}



int main(){
    vector<int> v = {1,2,3,4,5,6,7};
    binaryTreeNode* root  = createBST(v,0,6);
    // traverseBstPreorder(root);
    findMaxBst(root);
    cout << m_max;
}