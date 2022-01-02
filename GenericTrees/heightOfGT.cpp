#include<iostream>
using namespace std;
#include"TreeNode.h"

int heightOfGT(TreeNode* root){
    // -1 (int terms of edges and 0 in terms of nodes!!)
    int height = -1;
    for(int i = 0; i < root->children.size(); i++){
        int childHeight = heightOfGT(root->children[i]);
        if(childHeight > height){
            height = childHeight;
        }
    }
    return height+1;
}