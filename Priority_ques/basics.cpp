#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    vector<int> v = {3,2,3,1,2,4,5,5,6};

    // Max heap !! - Priority queue;
    // Max element at the top:
    priority_queue<int, vector<int>> pq;
    // Min heap - Priority queue;
    // Min element at top
    priority_queue<int,vector<int>, greater<int>> pq_min;

    for(int i = 0; i < v.size(); i++){
        pq.push(v[i]);
        pq_min.push(v[i]);
    }

    while(!pq_min.empty()){
        cout << pq_min.top() << " ";
        pq_min.pop(); 
    }
    
}