#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void topKFrequent(vector<int> & nums,int k){
    unordered_map<int,int> hm;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
    vector<int> ans;

    // Storing the freq V/S arr[i] in the hm;
    for(int i = 0; i < nums.size(); i++){
        hm[nums[i]]++;
    }

    // Traversing the hm and pushing in minHeap;
    for(auto i = hm.begin(); i != hm.end(); i++){
        minHeap.push(make_pair(i->second,i->first));
        if(minHeap.size() > k){
            minHeap.pop();
        }
    }
    while(!minHeap.empty()){
        ans.push_back(minHeap.top().second);
        minHeap.pop();
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}
int main(){
    vector<int> v = {1,1,2,2,2,3};
    topKFrequent(v,2);
}
