#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/*
bipartite graph is possible if the graph coloring is possible using two colors such that 
vertices in a set are colored with the same color.
Note that it is possible to color a cycle graph with even cycle using two colors.
*/
bool bfs(vector<vector<int>> graph,vector<int>& vis,int src){
    queue<int> q;
    q.push(src);
    vis[src] = 1; 

    while(!q.empty()){
        int frontNode = q.front();
        q.pop();

        for(auto adjNode:graph[frontNode]){
            if(vis[adjNode] == -1){ // not colored and not visited 
                vis[adjNode] = 1-vis[frontNode];
                q.push(adjNode);

            }else if (vis[adjNode] == vis[frontNode]){ // already visited and same color as of the src node
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> & graph){
    // -1 -> not visited
    vector<int>vis(graph.size(),-1);

    for(int i = 0; i<graph.size(); i++){
        if(vis[i] == -1){  // not visited
            if(!bfs(graph,vis,i)) {
                return false;
            }
        }
    }
    return true;
}
int main(){

}