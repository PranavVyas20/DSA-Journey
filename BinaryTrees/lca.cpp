#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

int m_lca = 0;
// Traverse and find some results for every node
bool lca(binaryTreeNode* root,int d1,int d2){
    if(root == NULL){
        return false;
    }
    bool self = root->data == d1 || root->data == d2;
    bool isLeft = lca(root->left,d1,d2);
    bool isRight = lca(root->right,d1,d2);

    if( (self  && isLeft) || (self  && isRight)  || (isLeft  && isRight) ){
      m_lca = root->data;
    }
    return self || isLeft || isRight;
    

}