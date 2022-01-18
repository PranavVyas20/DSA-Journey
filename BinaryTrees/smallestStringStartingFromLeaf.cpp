#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

    string ansString = "";
    
    void helperFunction(binaryTreeNode* root,string psf){
        if(root == NULL){
            return;
        }
        else if (root->left == NULL && root->right == NULL){
            ansString = min(ansString,char('a'+ root->data) + psf);
        }
        helperFunction(root->left, char('a'+root->data) + psf);
        helperFunction(root->right, char('a'+root->data) + psf);
        
    }
    
    string smallestFromLeaf(binaryTreeNode* root) {
        helperFunction(root,"");
        return ansString;
    }