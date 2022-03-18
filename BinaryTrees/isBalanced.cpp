#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<BinaryTree.h>

/* can be done either by travel and solve or with pari class method
a binary tree in which the left and right subtrees of every node differ in height
by no more than 1.
And this property should be true for all the nodes in the given tree !
*/

bool isBalancedAns = true;

int isBalanced(binaryTreeNode* node){
    if(node == NULL){
        return 0;
    }
    int leftChildHeight = isBalanced(node->left);
    int reightChildHeight = isBalanced(node->right);

// Condition for being balanced (checking at every node)
    isBalancedAns = abs(leftChildHeight - reightChildHeight) >= 1;
    // Calculating current node height and returning it 
    int selfHeight = max(leftChildHeight,reightChildHeight) + 1;
    return selfHeight;    
}






