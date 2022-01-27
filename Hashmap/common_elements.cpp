#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// Duplication not allowed
void commonElements(vector<int> v1,vector<int> v2){
    vector<int> ans;
    unordered_map<int,int> hm;
    for(int i = 0; i < v1.size(); i++){
        hm[v1[i]]++;
    }
    for(int i = 0; i < v2.size(); i++){
        if( hm.count(v2[i]) > 0 ){
            ans.push_back(v2[i]);
            hm.erase(v2[i]);
        }
    }
    for(int a:ans){
        cout << a << " ";
    }
}
int main(){
    commonElements({1,2,3,4,5},{2,3,4,1,1,115});
}