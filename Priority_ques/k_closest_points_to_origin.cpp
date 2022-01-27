#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void kClosest(vector<vector<int>> points,int k){
    // distance and points vector will be pushed in the max heap!
    priority_queue<vector<int>> maxHeap;
    vector<vector<int>> ans;

    for(int i = 0; i < points.size(); i++){
        int distance = pow(points[i][0],2) + pow(points[i][1],2);
        int x = points[i][0];
        int y = points[i][1];

        maxHeap.push({distance,x,y});
        if(maxHeap.size() > k){
            maxHeap.pop();
        }
    }
    while(!maxHeap.empty()){
        vector<int> top = maxHeap.top();
        ans.push_back({top[1],top[2]});
        maxHeap.pop();
    }
}
int main(){
vector<vector<int>> point = { {3,3},{5,-1}, {-2,4}};
kClosest(point,2);
}