#include<iostream>
using namespace std;
#include<bits/stdc++.h>

/*
1. You are given a number n (representing the number of students). Each student will have an id from 0 to n - 1.
2. You are given a number k (representing the number of clubs)
3. In the next k lines, two numbers are given separated by a space. The numbers are ids of students belonging to same club.

You have to find in how many ways can we select a pair of students such that both students are from different clubs.

Can be easily done through the get Components !!
First create components, students in one components represents - students in one club

*/
int totalWays = 0;

void perfect_friends_helper(vector<vector<int>> graph,vector<int> &vis,vector<int>&tmpAns,int start){
    tmpAns.push_back(start);
    vis[start] = 1;

    for(auto adjNode:graph[start]){
        if(vis[adjNode] == 0){
            perfect_friends_helper(graph,vis,tmpAns,adjNode);
        }
    }
}

int perfectFriends(vector<vector<int>> graph){
    // Visited vector
    vector<int> vis(graph.size(),0);
    vector<int> tmpAns;
    // final ans vector
    vector<vector<int>> components;

    for(int i = 0; i < graph.size(); i++){
        if(vis[i] == 0){
            perfect_friends_helper(graph,vis,tmpAns,i);
            components.push_back(tmpAns);
        }
    }
    // calculating the total no of ways
    // multiply every component with each other and keep adding the result 
    for(int i = 0; i < components.size(); i++){
        for(int j = i+1; j < components.size(); i++){
            totalWays += components[i].size() * components[j].size();
        }
    }

}

