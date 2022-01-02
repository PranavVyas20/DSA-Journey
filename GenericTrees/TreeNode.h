#include<vector>
#include<iostream>
using namespace std;


class TreeNode{
    public:
    int data;
    vector<TreeNode*> children;

    TreeNode(int data){
    this ->data = data;
   }
};

