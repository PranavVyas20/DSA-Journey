#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

    int sum = 0;
    void helperFunction(binaryTreeNode* root,string psf){
        if(root == NULL){
            return;
        }
        else if(root->left == NULL && root->right == NULL ){
            psf+= to_string(root->data);
            sum = sum + stoi(psf);
            return;
        }

        helperFunction(root->left,psf+to_string(root->data));
        helperFunction(root->right,psf+to_string(root->data));
    }
    
int sumNumbers(binaryTreeNode* root) {
        helperFunction(root,"");
        return sum;
    }
int main(){
    // sumNumbers();

}