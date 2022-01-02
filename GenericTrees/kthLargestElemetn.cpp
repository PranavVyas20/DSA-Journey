#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"TreeNode.h"

int kthLargest(TreeNode* root,int k){
    int kth = INT_MIN;
    if(k == 1 || root->children.size() == 0){
        return root->data;
    }
    for(int i = 0; i < root->children.size(); i++){
        int rec = kthLargest(root->children[i],k-1);
        if(rec > kth){
            kth = rec;
        }
    }
    return kth;
}