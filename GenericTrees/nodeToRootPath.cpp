#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"TreeNode.h"

vector<int> nodeToRootPath(TreeNode* root,int key){
    if(root->data == key){
        vector<int> bv;
         bv.push_back(root->data);
         return bv;
    }
    for(int i = 0; i < root->children.size(); i++){
        vector<int> cv = nodeToRootPath(root->children[i],key);
        if(!cv.empty()){
            cv.push_back(root->data);
            return cv;
        }
    }
    vector<int> thv;
    return thv;
}
int main(){
    vector<int> re;
    cout << re.size();
}