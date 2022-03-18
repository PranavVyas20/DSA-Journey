#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// Consists of Nodes and Edges
// How do we store them ?
// Create an array(its index represents particular node) of vectors
//                                                 (the edges will be stored in the vector)
// for example lets u = 5(nodes) and v = 6(edges):
class Edge{
    public:
    int des;
    int wt;
    Edge(int des,int wt){
        this->des = des;
        this->wt = wt;
    }
};

int main(){
    int n = 7;// nodes 
    int m = 8;// edges

    vector<Edge>graph[7];

    for(int i = 0; i < m; i++){
        int src,des;
        cin >> src >> des;

        // Creating the adjacency matrix for undirected graph and unweighted graph.
        graph[src].push_back(Edge(des,0));
        graph[des].push_back(Edge(src,0));
    }
}