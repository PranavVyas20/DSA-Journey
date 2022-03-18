#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// Tilt of a binary tree
int treeTile = 0;
int findTilt(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    int leftSum = findTilt(root.left);
    int rightSum = findTilt(root.right);
    int currentTilt = abs(leftSum - rightSum);
    treeTilt+=currentTilt;
    currentSUm = leftSum+rightSum+root.data;
    return currentSum;
}

// Is bst
class mPair{
    int max;
    int min;
    bool isBst;
}

// is balanced tree using the pair class method
bool isBalanced = true;
class mPair{
    int height; 
    bool isBal;
    mPair(int height,bool isBal){
        this -> height = height;
        this -> isBal = isBal;
    }
}
mPair isBalancedHelper(treenode* node){
    if(node == NULL){
        mPair bPair(-1,true);
        return mPair;
    }
    mPair lp = isBalancedHelper(node.left);
    mPair rp = isBalancedHelper(node.right);
    mPair ansPair(0,true);
    ansPair.height = max(lp.height,rp.height) + 1;
    ansPair.isBal = abs(lp.height - rp.height) <= 1
                      && (lp.isBal && rp.isBal);
    return ansPair;
}

// using the 'Travel and change starategy'
bool isBal = true;
int isBalancedHelper(treenode* node){
    if(node == NULL){
        return 0;
    }
    int lh = isBalancedHelper(node.left);
    int rh = isBalancedHelper(node.right);
    int diff = abs(lh-rh);
    if(diff >= 1){
        isBal = true;
    }else{
        isBal = false;
    }
    return max(lh,rh) + 1;  
}

// maxBst
