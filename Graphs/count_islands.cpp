#include<iostream>
using namespace std;
#include<bits/stdc++.h> 

// Loop on the whole matrix 
// if [i][j] is land 
// then let it expand to its max 
// with four calls ie up down left and right
// when these calls are finished that means an island exist and increase the count (islands)

int islandCount = 0;
// function to expand a vertex to its max
void numIslandsHelper(vector<vector<char>> grid,vector<vector<bool>>&vis,int i,int j){
    // Base cases (bhot sare lol xdddddd lmaooooooo)
    if(i < 0 || j <= 0 || i >= grid.size() || j >= grid.size() ||
         grid[i][j] == '0' || vis[i][j] == true ){
             return;
    }
    vis[i][j] = true;
    numIslandsHelper(grid,vis,i,j-1); // left call
    numIslandsHelper(grid,vis,i,j+1); // right call
    numIslandsHelper(grid,vis,i-1,j); // up call
    numIslandsHelper(grid,vis,i+1,j); // down call
}
int numIslands(vector<vector<char>>& grid){
// creating the vis matrix
// size = grid.size and every element will be a vector<bool>
vector<vector<bool>> vis(grid.size(),vector<bool>(grid[0].size(),false));

    for(int i = 0; i < grid.size(); i++){
        for(int j = 0; j < grid[i].size(); j++){
            if(grid[i][j] == '1' && vis[i][j] == false) {  // 1 = land , 0 = water
                numIslandsHelper(grid,vis,i,j);
                islandCount++;
            }
        }
    }
    return islandCount;
}