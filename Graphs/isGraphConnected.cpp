#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// Can be done easily through 'Get components' question
// if no of components > 1 then the graph is not connected 
// ie find the size of 'ans' vector at last 

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
    // Giving mauka to all nodes to expand
    for(int i = 0; i < n; i++){
        if(vis[i] == 0){
            getComponetsHelper(adj,vis,0,dfsAns);
        }
        finalDfsAns.push_back(dfsAns);
    }

    if(ans.size() > 1){
        cout << "graph is not connected";
    }else{
        cout << " graph is connected";
    }
}
