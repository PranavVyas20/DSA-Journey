#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    unordered_map<string,int> hm;
    // Insertion:
    // Map_name["key"] = val
    hm["india"] = 135;
    hm["india"] = 136;
    hm["china"] = 200;
    
    // get an item:
    // if the item is not present then it gets added with val = 0
    // cout << hm["key"] ;// or :

    // if the item is not present then error!
    // cout << hm.at("key");

    // if the given key is present or not ?
    // Count can be either 0 or 1!
    // 0 -> not present
    // 1 -> present
    cout << hm["india"];

}