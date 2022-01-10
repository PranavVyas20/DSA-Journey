// not circular array
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void nearest_greater_Left(int arr[],int n){
    stack<int> s;
    s.push(arr[0]);
    vector<int> v;
    v.push_back(-1);

    for (int i = 1; i < n; i++){
        if (arr[i] < s.top()){
            v.push_back(s.top());
        }
        else{
            while (s.empty() == false && arr[i] > s.top()){
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

int main()
{
    int marr[5] = {2, 5, 25, 4, 11};
    nearest_greater_Left(marr, 5);
}