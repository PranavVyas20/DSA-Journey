#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// observation - add two of the min elements in the array at a time and carry one doing so !
// Hence find k = 2 min elements in the array using HEAP!!
void minCost(vector<int> cost){
    int final_cost = 0;
    priority_queue<int,vector<int>,greater<int>> minHeap;

// emptying all the elements of arr in the min heap
    for(int i = 0; i < cost.size(); i++){
        minHeap.push(cost[i]);
    }

// >=2 (until only one element in heap, think about it bruhhhh)
    while(minHeap.size() >= 2){
        int first_min = minHeap.top();
        minHeap.pop();

        int second_min = minHeap.top();
        minHeap.pop();

        final_cost = final_cost + first_min + second_min;
        minHeap.push(first_min+second_min);
    }
    cout << "final cost: " << final_cost << endl;
}
int main(){
    vector<int> c = {4, 2, 7, 6, 9};
    minCost(c);
}