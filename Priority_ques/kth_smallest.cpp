#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int kSmallest(vector<int> v,int k){
    priority_queue<int> pq;
    for(int i = 0; i < v.size(); i++){
        pq.push(v[i]);
        if(pq.size() > k){
            pq.pop();
        }
    }
    return pq.top();
}
int main(){
vector<int> v = {7,10,4,3,20,15};
cout << kSmallest(v,3);
}