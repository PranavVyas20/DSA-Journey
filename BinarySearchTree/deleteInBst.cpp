#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"bst.h"


// Have to handle 3 cases :
// 1) -> When the current root has 0 child ie a 'leaf node'{
    // return null and connect it to the parent
// }
// 2) -> when the current root has only one child ie left or right child only{
    // return that single child and connect to the parent
// }
// 3) -> when the current root has both the child{
//     find max in its left subtree and replace the node to be deleted with it
//     then delete the max node that was found ( dont worry it wont have 2 child lol lmao xdddddd)
// } 

 int findMax(binaryTreeNode* node){
        if(node->right == NULL){
            return node->data;
        }
        int max = findMax(node->right);
        return max;
    }
    binaryTreeNode* deleteNode(binaryTreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
            if(key < root->data){
                root->left = deleteNode(root->left,key);
            }
            else if(key > root-> data){
                root->right = deleteNode(root->right,key);
            }
        // key == root.val
            else{
        //  2 child case
            if(root-> left != NULL && root->right != NULL){
                int lmax = findMax(root->left);
                root->data = lmax;
                root->left = deleteNode(root->left,lmax);
                return root;
            }
            // has only left child case
            else if(root -> left!= NULL){
                return root->left;
            }
            // has only right child case
            else if(root->right!= NULL){
                return root-> right;
            }
            // has 0 child case
            else{
                return NULL;
            }
        }
        return root;
    }