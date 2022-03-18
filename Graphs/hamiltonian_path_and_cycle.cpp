#include<iostream>
using namespace std;
#include<bits/stdc++.h>

vector<vector<char>>ans;
void dfsGraph(vector<vector<int>> graph,vector<bool>&vis,int src,vector<char> ansDfs,int orgSrc){

   vis[src] = true;
   ansDfs.push_back('0' + src);

   // Checking the base condition  
   // if we are on the last node
   if(ansDfs.size() == graph.size()){
        for(auto node:graph[orgSrc]){
            if(node == orgSrc){
                ansDfs.push_back('*');
                ans.push_back(ansDfs);
                vis[src]=false;
                return;
            }
        }
    ansDfs.push_back('.');
    ans.push_back(ansDfs);
    return;
}

   for(auto adjNode:graph[src]){
       if(!vis[adjNode]){
           dfsGraph(graph,vis,src,ansDfs,orgSrc);
       }
   }
   vis[src] = false;
   return;
}

vector<vector<char>> hamiltonPath_and_cycle(vector<vector<int>> graph){
    vector<bool>vis(graph.size(),false);
    vector<char>ansDfs;
    for(int i = 0; i < graph.size(); i++){
        if(vis[i] == false){
            dfsGraph(graph,vis,i,ansDfs,i);
        }
    }
}