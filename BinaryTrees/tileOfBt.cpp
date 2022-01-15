#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include "BinaryTree.h"

class mPair{
public:
    int sum;
    int tilt;
    mPair(int sum,int tilt){
        this->sum = sum;
        this->tilt = tilt;
    }
};

// Pair class method
mPair findTiltHelper(binaryTreeNode *node){
    if(node == NULL){
        mPair bPair(0,0);
        return bPair;
    }
    mPair leftPair = findTiltHelper(node->left);
    mPair rightPair = findTiltHelper(node->right);

    int nodeTilt = abs(leftPair.sum - rightPair.sum) + leftPair.tilt + rightPair.tilt;
    int nodeSum = leftPair.sum+rightPair.sum+node->data;
    mPair mainPair(nodeSum,nodeTilt);
    return mainPair;

}

// Travel and solve strategy
int tilt = 0;
int findTiltReturnSum(binaryTreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftSum = findTiltReturnSum(root->left);
    int rightSum = findTiltReturnSum(root->right);

    tilt += abs(leftSum - rightSum);
    return leftSum + rightSum + root->data;
}

int main()
{
}

