#include<iostream>
using namespace std;
#include<bits/stdc++.h>

bool dfs(vector<vector<int>> graph, vector<int> &color,int src){
    if(color[src] ==-1)color[src] = 1; // aate hi color krdo 

    for(auto adjNode:graph[src]){
        if(color[adjNode] == -1){ // not visited not colored
            color[adjNode] = 1 - color[src];
            if(!dfs(graph,color,adjNode)){
                return false;
            }
        }else if(color[src] == color[adjNode]){
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> & graph){
    // -1 -> not visited
    vector<int>vis(graph.size(),-1);

    for(int i = 0; i<graph.size(); i++){
        if(vis[i] == -1){  // not visited
            if(!dfs(graph,vis,i)) {
                return false;
            }
        }
    }
    return true;
}