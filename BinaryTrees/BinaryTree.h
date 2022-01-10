using namespace std;
#include<iostream>

class binaryTreeNode{
    public:
    int data;
    binaryTreeNode* left;
    binaryTreeNode* right;

    // Constructor
    binaryTreeNode(int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
