#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"


class diaPair{
    public:
    int height;
    int diam;
};

int heightOfBT(binaryTreeNode* root){
    if(root == NULL){
        return -1;
    }
    int leftH = heightOfBT(root->left);
    int rightH = heightOfBT(root->right);
    return max(leftH,rightH) + 1;
}

int diameter(binaryTreeNode* root){
    if(root = NULL){
        return 0;
    }
    int leftDia = diameter(root->left);
    int rightDia = diameter(root->right);

    int diaThroughRoot = heightOfBT(root->left) + heightOfBT(root->right) + 2;

    int diam = max(max(leftDia,rightDia),diaThroughRoot);
    return diam;
}

// Pair class method
diaPair diameter2(binaryTreeNode* root){
    if(root == NULL){
        diaPair bPair;
        bPair.diam = 0;
        bPair.height = -1;
        return bPair;
    }
    
    diaPair leftPair = diameter2(root->left);
    diaPair rightPair = diameter2(root->right);

    int diaThroughRoot = leftPair.height + rightPair.height + 2;
    int diam = max( max(leftPair.height,rightPair.height),diaThroughRoot);

    diaPair dPair;
    dPair.diam = diam;
    dPair.height = max(leftPair.height,rightPair.height) + 1;
    return dPair;
}