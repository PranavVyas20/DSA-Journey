#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

binaryTreeNode* constructTreeHelper(vector<int>& inorder, vector<int>& postorder ,int inS ,int inE ,int pstS ,int pstE){
    int idx = inS;
    while(postorder[pstE] != inorder[idx]){
        idx++;
    }
    binaryTreeNode* currentRoot = new binaryTreeNode(postorder[pstE]);

    int lInS = inS;
    int lInE = idx - 1;
    int lPstS = pstS;
    int lPstE = lInE - lInS + lPstS;//

    int rInS = idx + 1;
    int rInE = inE;
    int rPstS = lPstE + 1;
    int rPstE = pstE-1;//

    binaryTreeNode* mLeft = constructTreeHelper(inorder,postorder,lInS,lInE,rPstS,rPstE);
    binaryTreeNode* mRight = constructTreeHelper(inorder,postorder,rInS,rInE,rPstS,rPstE);

    currentRoot->left = mLeft;
    currentRoot->right = mRight;
    return currentRoot;
}