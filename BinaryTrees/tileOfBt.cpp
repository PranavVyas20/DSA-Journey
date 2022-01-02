#include <iostream>
using namespace std;
#include <bits/stdc++.h>
#include "BinaryTree.h"

class mPair
{
public:
    int sum;
    int tilt;
    mPair(int sum,int tilt){
        this->sum = sum;
        this->tilt = tilt;
    }
};

// Pair class method
mPair findTiltHelper(binaryTreeNode *root){
    if(root == NULL){
        mPair bPair(0,0);
        return bPair;
    }
    mPair leftPair = findTiltHelper(root->left);
    mPair rightPair = findTiltHelper(root->right);

    int rootTilt = abs(leftPair.sum - rightPair.sum) + leftPair.tilt + rightPair.tilt;
    int rootSum = leftPair.sum+rightPair.sum+root->data;
    mPair mainPair(rootSum,rootTilt);
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
    cout << abs(3 - 4);
}

