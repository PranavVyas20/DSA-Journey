#include<iostream>
using namespace std;
#include<bits/stdc++.h>

vector<int> ans;
void bfs(int node,vector<vector<int>> graph,vector<int> & vis){
    queue<int> q;
    q.push(node);
    vis[node] = true;
    while(!q.empty()){
        // vis[node] == true;
        int front = q.front;
        ans.push_back(front);
        q.pop();

        for(int adjNode:vis[node]){
            q.push(adjNode);
            vis[adjNode] = true;
        }
    }
}

vector<int> bfsTraversal(vector<vector<int>> graph){
    vector<bool> vis(graph.size(),false);
    for(int i = 0; i < graph.size(); i++){
        if(vis[i] == false){
            bfs(i,graph,vis);
        }
    }
    return ans;
}

void dfs(int node,vector<vector<int>> graph, vector<bool>&vis){
    vis[node] = true;
    ans.push_back(node);

    for(int adjNode:graph[node]){
        if(vis[adjNode] == false){
            dfs(adjNode,graph,vis);
          }
    }
}

bool isBipartiteHelper(int node,vector<vector<int>> graph,vector<int>&color){
    if(color[node] == -1){
        color[node] = 1;
    }

    for(auto adjNode:graph[node]){
        if(graph[adjNode] == -1){
            graph[adjNode] = 1 - graph[node];
            bool isBi = isBipartiteHelper(adjNode,graph,color);
            if(!isBi){
                return false;
            }
        }else if(graph[adjNode] == graph[node]){
            return false;
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>graph){
    vector<int> color(graph.size(),-1);
    for(int i = 0; i < graph.size(); i++){
        if(color[i] == -1){
            if(!isBipartiteHelper(i,graph,color)){
                return false;
            }
        }
    }
    return true;    
}

bool isBipartiteHelperBfs(vector<vector<int>> graph,int node,vector<int>&color){
    queue<int> q;
    if(color[node] == -1){
        color[node] = 1;
    }
    q.push(node);
    while(!q.empty()){
        int frontNode = q.front();
        q.pop();
        for(auto adjNode:graph[frontNode]){
            if(color[adjNode] == -1){
                color[adjNode] = 1 - color[frontNode];
                q.push(adjNode);
            }
            else if(color[adjNode] == color[frontNode]){
                return false;
            }
        }
    }
    return true;
}


// Detect cycle (bfs)
bool detectCycleHelper(int node, vector<bool> &visited,vector<vector<int>> graph){
    pair<int,int> p;
    queue<p> q;
    p.first = node;
    p.second = -1;
    q.push(p);
    vis[node] = true;

    while(!q.empty()){
        int currentNode = q.front().first;
        int parent = q.front().second;

        for(auto adjNode:vis[node]){
            if( vis[adjNode] == false){
                q.push(make_pair{adjNode,currentNode};
                vis[adjNode] = true;
            }
            else if(parent != currentNode){
                return true;
            }
        }
    }
    return false;
}

bool detectCycleDfsHelper(int node,vector<bool> & vis,int parent){
    if(vis[node] == false){
        vis[node] = true;
    }

    for(auto adjNode:vis[node]){
        if(vis[adjNode] == false){
            if(!detectCycleDfsHelper(adjNode,vis,node)){
                return false;
            }
        }
        else if(adjNode != parent){
            return true
        }
    }
    return true;
}

vector<vector<int>> components;
void getConnectedComponentsHelper(vector<vector<int>> graph,vector<bool>&vis,int src,vector<int> &psf){
    psf.push_back(src);
    vis[src] = true;

    for(auto adjNode:graph[src]){
        if(vis[adjNode] == false){
            getConnectedComponentsHelper(graph,vis,adjNode,psf);
        }
    }
}

vector<vector<int>> getComponents(vector<vector<int>> graph,vector<bool>&vis,int src,vector<int> psf){
    vector<int> psf;
    vector<bool> vis;
    for(int i = 0; i < graph.size(); i++){
        if(vis[i] == false]){
            getConnectedComponentsHelper(graph,vis,i,psf);
        }
        components.push_back(psf);
    }
}