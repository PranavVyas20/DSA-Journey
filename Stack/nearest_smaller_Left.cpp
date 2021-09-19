#include<iostream>
using namespace std;
#include<bits/stdc++.h>

void nearest_smaller_Left(int arr[],int n){
    stack<int> s;
    vector<int> v;
    v.push_back(-1);
    s.push(arr[0]);

    for (int i = 1; i < n; i++){
        if (arr[i] > s.top()){
            v.push_back(s.top());
            s.push(arr[i]);
        }
        else{
            while(s.empty() == false && arr[i] < s.top()){
                s.pop();
            }
            if (s.empty() == true){
                v.push_back(-1);
            }
            else{
                v.push_back(s.top());
            }
            s.push(arr[i]);
        }
    }
    for (int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
}
int main (){
int arr[5] = {2,5,25,4,11};
nearest_smaller_Left(arr,5);
}