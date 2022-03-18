#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include<BinaryTree.h>

/* Approach 1 - can be done with 'k level down' and 'node to root path'

vector<binaryTreeNode> ntrp;
vector<binaryTreeNode> kld;
vector<binaryTreeNode> ans;
void nodeToRootPath(binaryTreeNode* node,int data){
    if(node == null){
        return;
    }
    if(node->data == data){
        ntrp.push_back(node);
        return true;
    }
    bool foundInLeftSubtree = nodeToRootPath(node->left,data);
    if(foundInLeftSubtree){
        ntrp.push_back(node);
        return;
    }
    bool foundInRightSubtree = nodeToRootPath(node->right,data);
    if(foundInRightSubtree){
        ntrp.push_back(node);
        return;
    }
    return false;
}

void kLvlDown(binaryTreeNode* node, int k,int blocker){
    if(node == NULL || k < 0 || node == blocker){
        return;
    }
    if(k == 0){
        ans.push_back(node);
    }
    kLvlDown(node->left,k-1,blocker);
    kLvlDown(node->right,k-1,blocker);
}
vector<int> kLvlFar(binaryTreeNode* node,int data,int k){
    nodeToRootPath(node,data);
    vector<node> path = ntrp;
    for(int i = 0; i < path.size(); i++){
        kLvlDown(path[i],k-1, i==0 ? NULL:path[i-1]);
    }
}

// Approach 2 - Using kDown and node to root path (without using the extra array space)

 int distanceKHelper(TreeNode* node,int target, int k,vector<int> &ans){
    if(node == NULL){
        return -1;
    }
    if(node->val == target){
        kDown(node,k,NULL,ans);
        return 1;
    }
    int ld = distanceKHelper(node->left,target,k,ans);
    if(ld != -1){
        kDown(node,k-ld,node->left,ans);
        return ld+1;
    }
    int rd = distanceKHelper(node->right,target,k,ans);
    if(rd != -1){
        kDown(node,k-rd,node->right,ans);
        return rd+1;4
    }
    return -1;
}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    vector<int> finalAns;
    int a = distanceKHelper(root,target->val,k,finalAns);
    return finalAns;
}
/*