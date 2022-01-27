#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main(){
    string str = "abracadabra";

    unordered_map<char,int> hm;
    for(int i = 0; i < str.size(); i++){
        // Searches for char 'a' if present -> increment its value
        //                      if not present -> inserts it and increment its value
        hm[str[i]]++;
    }
    int maxFreq = 0;
    char ch;
    for(pair<char,int> p:hm){
        if(p.second > maxFreq){
            maxFreq = p.second;
            ch= p.first;
        }
    }
    cout << ch  << " : " << maxFreq;
}