#include<iostream>
using namespace std;
#include<bits/stdc++.h>
#include"BinaryTree.h"

binaryTreeNode* constructBT(vector<int> preoreder,vector<int> inorder,int in_si,int in_ei,int p_si,int p_ei){
     // base case
     if(in_si > in_ei){
         return NULL;
     }
     int idx = in_si;
     // calculating the mid point in the preoder vector
     while(preoreder[p_si] != inorder[idx]){
         idx++;
     }
      int lInS = in_si;//.
     int lInE = idx -1;//.
     int lPreS = p_si + 1;//.
     int lPreE = lInE-lInS + lPreS; //.


     int rPreS = lPreE + 1;
     int rPreE = p_ei;
     int rInS = idx + 1;
     int rInE = in_ei;

     binaryTreeNode* currentRoot = new binaryTreeNode(preoreder[p_si]);
     binaryTreeNode* left = constructBT(preoreder ,inorder ,lInS ,lInE ,lPreS ,lPreE);
     binaryTreeNode* right = constructBT(preoreder,inorder ,rInS ,rInE ,rPreS ,rPreE);//
     currentRoot->left = left;
     currentRoot->right = right;
     return currentRoot;
}