#include <iostream>
using namespace std;
#include <bits/stdc++.h>

// bfs is same as printing lvl wise in binary tree !
void bfs(vector<bool> &vis,vector<vector<int>> graph,int src, vector<int>& ansBfs ){
    queue<int> q;
    vis[src] = 1;
    q.push(src);
    while (!q.empty()){
        // Remove
        int front_node = q.front();
        q.pop();
        // Print or add in the main ans vector
        ansBfs.push_back(front_node);

        // adding the nbrs of the current node in the queue
        for (auto adjNode : graph[front_node]){
            if (vis[adjNode] == 0){
                q.push(adjNode);
                vis[adjNode] = 1;
            }
        }
    }
}

void dfs(int node, vector<int> &vis, vector<vector<int>> graph, vector<int> &ans){
    ans.push_back(node);
    vis[node] = 1;
    for (auto adjNode : graph[node]){
        if (vis[adjNode] == 0){
            dfs(adjNode, vis, graph, ans);
        }
    }
}
vector<int> dfsOfGraph(int n, vector<vector<int>> graph){
    vector<int> ansDfs;
    vector<int> vis(n + 1, 0);

    // Loop for nodes and connected components
    for (int i = 1; i <= n; i++){
        if (vis[i] == 0){
            dfs(i, vis, graph, ansDfs);
        }
    }
    return ansDfs;
}

vector<int> bfsOfGraph(int n, vector<vector<int>> graph){
    // Creating the visited vector
    vector<bool> vis(n,false);
    vector<int> ansBfs;

// Looping for all the components
    for(int i = 0; i < n; i++){
        if(vis[i] == false){
            bfs(vis,graph,i,ansBfs);
        }
    }
    return ansBfs;
}

int main()
{

}