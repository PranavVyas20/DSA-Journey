#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"TreeNode.h"

void preorder(TreeNode* root){
    for(int i = 0; i < root->children.size(); i++){
        preorder(root->children[i]);
    }
    cout << root->data << " ";
}

void lvlOrderTraversal(TreeNode* root){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* front = q.front();
        q.pop();

        // Print 
        cout << front->data << " ";
        // add the children
        for(int i = 0; i < front->children.size(); i++){
            q.push(front->children[i]);
        }
    }
}

void lvlOrderTraversalII(TreeNode* root){
    vector<vector<int>> v;
    vector<int> v1;
    vector<int> v2;

    queue<TreeNode*> mq;
    queue<TreeNode*> cq;

    mq.push(root);
    while(!mq.empty()){
        // Remove
        TreeNode* front = mq.front();
        mq.pop();

        // Print 
        cout << front->data << " ";

        // add the children
        for(int i = 0; i < front->children.size(); i++){
            cq.push(front->children[i]);
        }
        // if the mq is empty that means one level complete so 
        // give a new line
        if(mq.empty()){
            // cout << endl;
            mq=cq;
            while(!mq.empty()){
                mq.pop();
            }
            mq=cq;
            while(!cq.empty()){
                cq.pop();
            }
        }

    }

}

void lvlOrderTraversalIII(TreeNode* root){
    queue<TreeNode*> q;
    vector<vector<int>> v;
    q.push(root);

    while(!q.empty()){
        vector<int> v2;
        int size = q.size(); 
        for(int i = 0; i < size; i++){
            TreeNode* front = q.front();
            q.pop();

            v2.push_back(front->data);
            for(int j = 0; j < front->children.size(); j++){
                q.push(front->children[j]);
            }
        }
        v.push_back(v2);
    }

    for(int i = 0; i < v.size(); i++){
        for(int j = 0; j < v[i].size(); j++){
            cout << v[i][j] << " ";
        }
    }

}

int main(){
    TreeNode* root  = new TreeNode(10);
    root->children.push_back(new TreeNode(20));
    root->children.push_back(new TreeNode(30));
    root->children[0]->children.push_back(new TreeNode(40));
    root->children[1]->children.push_back(new TreeNode(50));
    lvlOrderTraversalIII(root);

}