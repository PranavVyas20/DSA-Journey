#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// Simply traverse the graph with dfs 
// Keep adding each node in a  vector
// Do this for every node
// when one node is done expanding then add the uper wala vector to a new vector<vector>> 

vector<vector<int>> ans;
void getComponetsHelper(vector<int>adj[],vector<int> &vis, int start,vector<int> &ansDfs){
    ansDfs.push_back(start);
    vis[start] = 1;

    for(auto adjNode:adj[start]){
        if(vis[adjNode] == 0){
            // go to neighbour of the 'adjNode'
            getComponetsHelper(adj,vis,adjNode,ansDfs);
        }
    }
}
void getComponents(int n,vector<vector<int>>graph){
    vector<int> vis(n,0);
    vector<int> dfsAns;
    vector<vector<int>> finalDfsAns;
    vector<int>adj[n];
    // Creating the adj list
    for(int i = 0; i < graph.size(); i++){
        int u = graph[i][0];
        int v = graph[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            getComponetsHelper(adj,vis,i,dfsAns);
        }
        finalDfsAns.push_back(dfsAns);
    }
}




