#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

class mPair{
    public:
    bool isBst;
    int size;
    int min;
    int max;
};

mPair maxBSTSubtreeSize(binaryTreeNode* root){
    if(root == NULL){
        mPair bPair;
        bPair.isBst = true;
        bPair.size = 0;
        bPair.min = INT_MAX;
        bPair.max = INT_MIN;
        return bPair;
    }
    mPair leftPair = maxBSTSubtreeSize(root->left);
    mPair rightPair = maxBSTSubtreeSize(root->right);

    mPair ans;
    // Checking if the current node is a bst as a node
    ans.isBst = (leftPair.isBst && rightPair.isBst) 
    // Checking if the current node is a bst as a tree
                    && (root->data >= leftPair.max && root->data <= rightPair.min);
    // Returning the min and max of the current node as the parent node will be needing it to further calculate
    // the reslut
      
    ans.min = min(root->data,min(leftPair.min,rightPair.min));
    ans.max = max(root->data,max(leftPair.max,rightPair.max));

    if(ans.isBst){
        // If the current node is bst then return its size
        ans.size = leftPair.size + rightPair.size + 1;
    }
    // If not bst then the size of the last bst will be returned
    else if (leftPair.size > rightPair.size){
        // Now how do we know that left pair was a bst ?

        // Because agar wo bst ni hota to line 33 execute hoti.
        // All in all if the current node is not bst then we always have the size of the previous bst!
        // Thanks to recursion
        ans.size = leftPair.size;
    }
    else{
        ans.size = rightPair.size;
    }
    return ans;
}
void printTree(binaryTreeNode* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " ";
    printTree(root->left);
    printTree(root->right);
}
int main(){
    binaryTreeNode* root = new binaryTreeNode(50);
    binaryTreeNode* root2 = new binaryTreeNode(25);
    binaryTreeNode* root3 = new binaryTreeNode(12);
    binaryTreeNode* root4 = new binaryTreeNode(37);
    binaryTreeNode* root5 = new binaryTreeNode(30);
    binaryTreeNode* root6 = new binaryTreeNode(40);
    binaryTreeNode* root7 = new binaryTreeNode(75);
    binaryTreeNode* root8 = new binaryTreeNode(62);
    binaryTreeNode* root9 = new binaryTreeNode(60);
    binaryTreeNode* root10 = new binaryTreeNode(77);
    binaryTreeNode* root11 = new binaryTreeNode(87);

    root->left = root2;
    root->right = root7;
    root2->left = root3;
    root2->right = root4;
    root4->left = root5;
    root4->right = root6;
    root7->left = root8;
    root7->right = root11;
    root8->left = root9;
    root8->right = root10;
    // printTree(root);
    mPair ar = maxBSTSubtreeSize(root);
    cout << ar.size;

}