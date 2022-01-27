#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

class mPair{
    public:
    int state;
    binaryTreeNode* node;

    mPair(int state,binaryTreeNode* node){
        this->state = state;
        this->node = node;
    }
};

void traverseIterative(binaryTreeNode* root,string pre,string post,string in){
    stack<mPair> st;
    mPair bPair(1,root);
    st.push(bPair);

    while(st.size() > 0){
        mPair stTop = st.top();

        if(stTop.state == 1){
            // add
            pre+=to_string(stTop.node->data);
            // increment state;
            stTop.state++;
            // go to left but check for null first!
            if(stTop.node->left!=NULL){
            st.push(mPair(1,stTop.node->left));
            }
        }
        else if(stTop.state == 2){
            in+=to_string(st.top().node->data);
            stTop.state++;
            if(stTop.node->right!=NULL){
                st.push(mPair(1,stTop.node->right));
            }
        }
        else if(stTop.state == 3){
            post+=to_string(stTop.node->data);
            st.pop();
        }
    }
    cout << "pre: " << pre << endl;
    cout << "in: " << in << endl;
    cout << "post: " << post << endl;
}