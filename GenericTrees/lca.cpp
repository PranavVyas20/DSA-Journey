#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"TreeNode.h"

// NodeToRoot function (returns a vector)
vector<int> helperFn(TreeNode* root,int key){
    if(root->data == key){
        vector<int> bv;
        bv.push_back(root->data);
        return bv;
    }
    for(int i = 0; i < root->children.size(); i++){
        vector<int> cv = helperFn(root->children[i],key);
        if(!cv.empty()){
            cv.push_back(root->data);
            return cv;
        }
    }
    vector<int> ev;
    return ev;
}
int lca(TreeNode* root,int k1,int k2){
    vector<int> v1 = helperFn(root,k1);
    vector<int> v2 = helperFn(root,k2);
    
}