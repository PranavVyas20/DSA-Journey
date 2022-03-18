#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// visited not needed
vector<vector<int>> ans;
void allPathsHelper(vector<vector<int>>adj,int src,int des,vector<int> psf){
        psf.push_back(src);
        if(src == des){
            ans.push_back(psf);
            return;
        }
        for(int adjNode:adj[src]){
            allPathsHelper(adj,adjNode,des,psf);
        }
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    vector<int> psf;
    allPathsHelper(graph,0,graph.size()-1,psf);
    return ans;
}
int main(){

}