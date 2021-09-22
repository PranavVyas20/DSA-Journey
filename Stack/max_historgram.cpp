#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int max_Histogram(int arr[],int n){
// Finding the NSR and storing it in an vector "NSR"
    stack<int> s1;
    vector<int> NSR;
    s1.push(n-1);
    NSR.push_back(-1);

    for (int i = n-2; i >= 0; i--){
        if (arr[s1.top()] < arr[i]){
            NSR.push_back(s1.top());
            s1.push(i);
        }
        else{
            while(s1.empty() == false && arr[i] <= arr[s1.top()]){
                s1.pop();
            }
            if (s1.empty() == true){
                NSR.push_back(n);
            }
            else{
                NSR.push_back(s1.top());
            }
            s1.push(i);
        }
    }
    reverse(NSR.begin(),NSR.end());

    // Finding NSL and storing it in an vector 'NSL'
    stack<int> s2;
    s2.push(0);
    vector<int> NSL;
    NSL.push_back(-1);

    for (int i = 1;i < n; i++){
        if (arr[s2.top()] < arr[i]){
            NSL.push_back(s2.top());
            s2.push(i);
        }
        else{
            while(s2.empty() == false && arr[s2.top()] >= arr[i]){
                s2.pop();
            }
            if (s2.empty() == true){
                NSL.push_back(-1);
            }
            else{
                NSL.push_back(s2.top());
            }
            s2.push(i);
        }
    }

    // Creating the width array and storing elements in it
    //width_v[i] = NSR[i] - NSL[i]) - 1
    // and then multiplying width_v[i] * arr[i] to find the area made by each item in arr[]
    vector<int> width_v;
    for (int i = 0; i<n; i++){
        width_v.push_back(((NSR[i] - NSL[i]) - 1) * arr[i]);
        // cout << width_v[i] << " ";
    }
    // Now the last step i.e finding the max out of all the areas from the width_v 
    return *max_element(width_v.begin(),width_v.end());

}
using namespace std;
int main (){
// int arr[7] = {6,2,5,4,5,1,6};
int arr2[5] = {1,2,5,6,1};

cout << max_Histogram(arr2,5);

}