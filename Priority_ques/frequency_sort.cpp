#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void frequencySort(vector<int> & nums){
    unordered_map<int,int> hm;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
    vector<int> ans;

    // saving the freq V/S element in the hm;
    for(int i = 0; i < nums.size(); i++){
        hm[nums[i]]++;
    }
    // Traversing the hm and pushing in the minHeap
    for(auto i = hm.begin();i != hm.end();i++){
        minHeap.push(make_pair(i->second,i->first));
    }
    while(!minHeap.empty()){
        int freq = minHeap.top().first;
        int element = minHeap.top().second;
        for(int i = 0; i < freq; i++){
            ans.push_back(element);
        }
        minHeap.pop();
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}
int main(){
    vector<int> arr= {1,1,2,2,2,3};
    frequencySort(arr);
}