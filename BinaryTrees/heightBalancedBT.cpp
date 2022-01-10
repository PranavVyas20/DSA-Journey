#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

class mPair{
    public:
    int height;
    bool isBalanced;
    mPair(int height,bool isBalanced){
        this -> height = height;
        this -> isBalanced = isBalanced;
    }
};

bool isBalanced = true;
int returnHeightFindisBalanced(binaryTreeNode* root){
    if(root == NULL){
        return 0;
    }
    int leftHeight = returnHeightFindisBalanced(root->left);
    int rightHeight = returnHeightFindisBalanced(root->right);
    if( abs(leftHeight - rightHeight) > 1 ){
        isBalanced = false;
    }
    int nodeHeight = max(leftHeight,rightHeight) + 1;
    return nodeHeight;
}

mPair isBalancedII(binaryTreeNode* root){
    if(root == NULL){
        mPair dPair(0,true);
        return dPair;
    }
    mPair leftPair = isBalancedII(root->left);
    mPair rightPair = isBalancedII(root->right);

    mPair currentPair(0,true);
    currentPair.height = max(leftPair.height,rightPair.height) + 1;
    // Below line means that the current node is balanced as a 'Node'
    currentPair.isBalanced = abs(leftPair.height - rightPair.height) <= 1
    // Now the below line means that the current node is balanced as a 'SubTree' 
                            && leftPair.isBalanced && rightPair.isBalanced;
    return currentPair;


}


