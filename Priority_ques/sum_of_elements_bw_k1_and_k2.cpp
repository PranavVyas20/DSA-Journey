#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int kSmallestNum(vector<int> v,int k){
    priority_queue<int> maxheap;
    for(int i = 0; i < v.size(); i++){
        maxheap.push(v[i]);
        if(maxheap.size() > k){
            maxheap.pop();
        }
    }
    return maxheap.top();
}
int sumElementsBwK1K2(vector<int> v,int k1,int k2){
    int sum = 0;
    int first = kSmallestNum(v,k1);
    int second = kSmallestNum(v,k2);

    for(int i = 0; i < v.size(); i++){
        if(first <= v[i] <= second){
            sum += v[i];
        }
    }
    return sum;
}