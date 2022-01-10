#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// Not giving the output idk why FUCKKKKKKKKKKKKK!!!!!!!
void nearest_smaller_Right(int arr[],int n){
    stack<int> s;
    vector<int> v;
    s.push(arr[n-1]);
    v.push_back(-1);
    
    for (int i = n-2; i >= 0; i--){
        cout << "a" <<" ";
        if (arr[i] > s.top()){
            v.push_back(s.top());
            s.push(arr[i]);
        }
        else{
            while(arr[i] < s.top() && s.empty() == false){
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
nearest_smaller_Right(arr,5);

}