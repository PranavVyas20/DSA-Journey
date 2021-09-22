#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int rainwater_trap_II(int arr[],int n){
     // It will store the greatest element to the left of each 'i' of arr[]
    vector<int> gl;
     // It will store the greatest element to the right of each 'i' of arr[]
    vector<int> gr;
    // Final vector, it will store the amount of water on top each building
    vector<int> water;

    // Fillin the gl vector by comparing elements with arr[]
    int max = arr[0];
    gl.push_back(max);

    for (int i = 1; i < n; i++){
        if (arr[i] > max){
            max = arr[i];
            gl.push_back(max);
        }
        else{
            gl.push_back(max);
        }
    }

    // Fillin the gr vector by comparing elements with arr[]
    max = arr[n-1];
    gr.push_back(max);
    
    for (int i = n-2; i>= 0; i--){
        if (arr[i] > max){
            max = arr[i];
            gr.push_back(max);
        }
        else{
            gr.push_back(max);
        }
    }
    
    // Amount of water on top of each building ie water[i] = min(gl[i] - gr[i]) - arr[i];
     int finalSum = 0;
     for (int i = 0; i < n; i++){
         water.push_back(min(gl[i],gr[i]) - arr[i]);
         cout << water[i] << " ";
         finalSum+=water[i];
     }
     cout << endl;
     cout << "final sum: ";
     return finalSum;
}
int main (){
int arr[8] = {2,1,3,0,0,2,0,4};
cout << rainwater_trap_II(arr,8);

}