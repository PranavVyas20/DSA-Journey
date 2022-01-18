#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"bst.h"

    int mSum = 0;
    void helperFn(binaryTreeNode* root,int low,int high){
        if(root == NULL){
            return;
        }
        if(root->data >= low && root->data <= high){
            mSum+=root->data;
        }
        helperFn(root->left,low,high);
        helperFn(root->right,low,high);
    }
    int rangeSumBST(binaryTreeNode* root, int low, int high) {
        helperFn(root,low,high);
        return mSum;
    }

    int main(){
        
    }