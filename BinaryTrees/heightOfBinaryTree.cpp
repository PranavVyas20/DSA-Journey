#include"BinaryTree.h"
#include<iostream>
using namespace std;

// height = -1 (in case of edges)
// height = 0 (in case of nodes)
int heightOfBT(binaryTreeNode* root){
    if(root == NULL){
        return -1;
    }

    int leftHeight = heightOfBT(root->left);
    int rightHeight = heightOfBT(root->right);

    return max(leftHeight,rightHeight) + 1;
}