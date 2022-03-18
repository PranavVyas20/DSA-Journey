 #include<iostream>
using namespace std;
#include<bits/stdc++.h>

// Using BFS
bool helper_cycle_detect(vector<vector<int>> adj, vector<int> vis,int start,int n){
    // pair<node,parent>
    queue<pair<int,int>> q;
    vis[start] = 1;

    q.push(make_pair(start,-1));
    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second; 

        for(auto adjNode : adj[node]){
            if(vis[adjNode] == 0){
                vis[adjNode] = 1;
                q.push(make_pair(adjNode,node));
            }
            // Condition for having a cycle!!
            // matlab ki aap adjNode pr a chuke ho but wo apka parent bhi ni hai !!! 
            // that means aap phle dusri side se idhar a chuke , hence cycle hai bc!
            else if (vis[adjNode] == 1 && parent != adjNode){
                return true;
            }
        }
        return false;
    }
}

bool cycleDetect(vector<vector<int>> adj,int N){
    vector<int> vis(N+1,0);
    // Loop for all the components and nodes 
    // but first checking first if they are visited or not 
    for(int i = 1; i <= N; i++){
        if(vis[i] == 0){
            if(helper_cycle_detect(adj,vis,i,N)) return true;
        }
    }
    return false;
}
int main(){
    
}