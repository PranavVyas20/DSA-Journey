#include<iostream>
using namespace std;
#include<bits/stdc++.h>

vector<int> findClosestElements(vector<int> arr,int k,int x){
    vector<int> ans;
    priority_queue<pair<int,int>>maxPq;
    // Traversing the array and creating pair<abs(diff),arr[i]> and pushing them in the heap
    for(int i = 0; i < arr.size(); i++){
        pair<int,int> p (abs(x-arr[i]),arr[i]);
        maxPq.push(p);
        if(maxPq.size() > k){
            maxPq.pop();
        }
    }
    while(maxPq.size() > 0 ){
        ans.push_back(maxPq.top().second);
        maxPq.pop();
    }
    return ans;

}