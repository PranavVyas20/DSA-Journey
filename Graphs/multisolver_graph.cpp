#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int longestPathWeight = INT_MIN;
int smallestPathWeight = INT_MAX;
vector<int> smallestPath;
vector<int> longestPath;

void multiSolverGraph(vector<pair<int,int>>adj[],vector<int>&vis,int start,int end,vector<int>psf,int wsf){
    psf.push_back(start);
    if(start == end){
        if(wsf < smallestPathWeight){
            smallestPathWeight = wsf;
            smallestPath = psf;
        }
        if(wsf > longestPathWeight){
            longestPathWeight = wsf;
            longestPath = psf;
        }
        return;
    }
    vis[start] = 1;
    for(auto adjNode:adj[start]){
        // adjNode is a pair !! 
        // pair<node,weight> !!
        if(vis[adjNode.first] == 0){
            multiSolverGraph(adj,vis,adjNode.first,end,psf,wsf+adjNode.second);
        }
    }
    vis[start] = 0;
}

int main(){
    int noOfNodes = 5;
    int noOfEdges = 7;
    // pair<adjNode,weight> !!
    // vector<vector<pair<int,int>>> graph = { {}

    // }
}