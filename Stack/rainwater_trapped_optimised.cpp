#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// Optimised solution i.e without using those 2 arrays 
// Algo:
// maxLeft = arr[0]
// maxRight = arr[n-1]
// min(maxLeft,maxRight) se apan individual water height find out krte hai for each
// 'i' in arr[]
int rainwater_optimised(int arr[],int n){
    int ml = arr[0];
    int mr = arr[n-1];
    vector<int> water;
    // l = frst element of arr[]
    int l = 1;
    // r = second last element of the arr[]
    int r = n-2;
    int sum = 0;

    while(l <= r){
        // since ml is smaller so we will find the individual water height for each 'i'
        // from left hand side
        if (ml < mr){
            // If our arr[i] > ml than we change ml to that arr[i]
            if (ml < arr[l]){
                  ml = arr[l];
                  //It means that building wont store any water above it
                  // so we dont update our 'sum'
            }
            else{
                // Here we find the amount of water on building 'i' by ml - arr[l]
                sum+=ml-arr[l];
            }
            l++;
        }
        //For the handling the case when  ml >= mr
        else{
            if (mr < arr[r]){
                // Same as above i.e this building wont have any water stored above it
                // And we change our mr to that building
                 mr = arr[r];
            }
            else{
                sum += mr-arr[r];
            }
            r--;
        }
    }
    cout << "sum: ";
    return sum;
}
int main (){
    int arr[7] = {4,2,0,6,2,5,4};
    cout << rainwater_optimised(arr,7);


}