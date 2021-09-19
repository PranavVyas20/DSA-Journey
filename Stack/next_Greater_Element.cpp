#include<iostream>
using namespace std;
#include <bits/stdc++.h>

void nextGreater(int arr[],int size){
stack<int> s;
vector<int> v;
s.push(arr[size-1]);
v.push_back(-1);

for (int i = size - 2; i >= 0; i--){
    if (arr[i] < s.top()){
        v.push_back(s.top());
        s.push(arr[i]);
    }
    else{
        while(s.size() > 0 && arr[i] > s.top()){
            s.pop();
        }
        if (s.empty() == true){
            v.push_back(-1);
        }
        else {
            v.push_back(s.top());
        }
        s.push(arr[i]);
    }
}
reverse(v.begin(),v.end());
// Print the vector
for (int i = 0; i < size; i++){
    cout << v[i] << " " ;
}

}
int main (){
int myArr[5] = {4,25,2,5,7};
nextGreater(myArr,5);

}