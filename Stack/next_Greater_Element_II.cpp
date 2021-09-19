#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Wirh circular Array
// e.g [1,2,3,4,5]<-->[1,2,3,4,5]

void nextGreater(int arr[],int n){
    stack<int> s;
    vector<int> v;
    s.push(arr[n - 1]);
    // No need to push (-1)) beacuse its a fuckin circular array !!
    // v.push_back(-1);

    for (int i = (2*n)-2; i >= 0; i--){

    if (arr[i % n] < s.top()){
        if (i < n){
        v.push_back(s.top());
        }
        s.push(arr[i % n]);
    }
    else{
        while(s.size() > 0 && arr[i % n] >= s.top()){
            s.pop();
        }
        if (s.empty() == true){
             if (i < n){
            v.push_back(-1);
        }
        }
        else {
            v.push_back(s.top());
        }
        s.push(arr[i % n]);
    }
}
for (int i = 0; i < n; i++){
    cout << v[i] << " ";
}
}

int main (){
int myArr[5] = {25,11,2,5,7};
nextGreater(myArr,5);

}