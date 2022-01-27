#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// Check every element if its the starting of an sequence( ie usse chota koi mojud to nhi in the HashMap)
void longestSubsequence(vector<int> v){
    int lss = 0;

    unordered_map<int,bool> hm;
    // insert all the values in the hm
    for(int i = 0; i < v.size(); i++){
        hm[v[i]] = true;
    }
    // first loop on the vector to find if the smaller exists of the v[i]
    for(int i = 0; i < v.size(); i++){
        // if smaller found in hm
        if(hm.find(v[i] - 1) != hm.end()){
            hm[v[i]] = false;
        }
    }
    // final loop on the hm to count the max sequence
    for(int i = 0; i < v.size(); i++){
        // if starting of the sequence:
        if(hm[v[i]] == true){
            int temp = v[i];
            int t = 1;

            while(hm.find(temp+t) != hm.end()){
                t++;
            }
            lss = max(lss,t);
        }
    }
    cout << lss << " max";
}
int main(){
longestSubsequence({10,5,9,1,11,8,6,15,3,12,2});
}