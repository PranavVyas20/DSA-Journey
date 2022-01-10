#include<iostream>
#include<vector>
#include"TreeNode.h"
using namespace std;

// Basic algo:
// Calculate deepest child height and second deepest child height at every node 
// We calculate diameter but return height
int dia = 0;
int findDiaReturnheight(TreeNode* root){
    int dch = -1;
    int sdch = -1;

    for(int i = 0 ; i < root->children.size(); i++){
        int childHeight = findDiaReturnheight(root->children[i]);
        if(childHeight > dch){
            sdch = dch;
            dch = childHeight;
        }
        else if(childHeight > sdch){
            sdch = childHeight;
        }
    }

// 
    if(dch+sdch+2 > dia){
        dia = dch+sdch+2;
    }
    dch+=1;
    return dch;
}
int main(){

}