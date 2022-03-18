#include<iostream>
using namespace std;
#include<bits/stdc++.h>
                                                                 // pair<node,parent>
bool detectCycleHelper(vector<vector<int>> graph,vector<bool> &vis,int node,int parent){
    vis[node] = true;

    for(auto adjNode:graph[node]) {
        if(vis[adjNode] == false){
            if(detectCycleHelper(graph,vis,adjNode,node)){
                return true;
            }
            // adjNode is visited but not through the parent that means there is a cycle
        }else if(adjNode != parent){
            return true;
        }
    }
    return false;
}

bool detectCycle(vector<vector<int>> graph){
    // Creating the visited vector
    vector<bool> vis(graph.size(),false);
    for(int i = 0; i < graph.size(); i++){
        if(vis[i] == false){
            if(detectCycleHelper(graph,vis,i,-1)){
                return true;
            }
        }
    }
    return false;
}
int main(){

}