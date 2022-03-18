#include<iostream>
using namespace std;
#include<bits/stdc++.h>

bool hasPathHelper(vector<int> adj[],vector<int> &vis,int start,int end){
    if(start == end){
        return true;
    }
    vis[start]= 1;

    for(auto adjNode:adj[start]){
        if(vis[adjNode] == 0){
            bool hasPathNbr = hasPathHelper(adj,vis,adjNode,end);
            if(hasPathNbr){
                return true;
            }
        }
    }  
    return false;
}
bool validPath(int n, vector<vector<int>> edges,int start,int end){
    // Creating the adjacency list
    // Cant use vector of vector here! 
    vector<int> adj[n];
    // Creating the visited vector
    vector<int> vis(n,0);

    for(int i = 0; i < edges.size(); i++){
        // edge is there bw u->v as well as v->u !k
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    return hasPathHelper(adj,vis,start,end);
}
int main(){

}