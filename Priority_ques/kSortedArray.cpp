#include<iostream>
using namespace std;
#include<bits/stdc++.h>

vector<int> kSortedSrray(vector<int> v,int k){
    cout << "enter";
    priority_queue<int,vector<int>,greater<int>> pq;
    vector<int> ans;

    for(int i = 0; i < v.size(); i++){
        pq.push(v[i]);

        if(pq.size() > k){
            int top = pq.top();
            v.push_back(top);
            pq.pop();
        }
    }
    while(!pq.empty()){
        ans.push_back(pq.top());
        pq.pop();
    }
    // Printing the ans vector
return ans;

}


int main(){
    cout << "hello";
    vector<int> v1{1,2,3,4,6,5,7,};
    vector<int> v2 = kSortedSrray(v1,2);
    for(int i = 0; i < v2.size(); i++){
        cout << v2[i] << " ";
    }
}