#include<iostream>
using namespace std;
#include<bits/stdc++.h>

// My initial solution working though but not good i guess lol
// void stock_span(int price[],int n){
//     stack<int> s;
//     s.push(price[0]);
//     int prePop = 0;
    
//     for (int i = 1; i < n; i++){
//         int popped = 0;
//         int totalPop = 0;
       
//         if (price[i] < s.top()){
//             s.push(price[i]);
//             cout << 1 << endl;
//         }
//         else{
//             while(price[i] > s.top() && s.empty() == false){
//                 s.pop();
//                 popped++;
//             }
//             s.push(price[i]);
//             totalPop = prePop+popped;
//          cout << price[i] << " ngl " <<  totalPop +1 << endl;
//         }
//         prePop+=popped;
//     }
// }

void stock_span_II(int price[],int n){
    // stack of indices of nge's rather than elments
   vector<int> v;
   v.push_back(1);
   stack<int> s;
   s.push(0);

    for (int i = 1; i < n; i++){
        if (price[s.top()] > price[i]){
            s.push(i);
            v.push_back(1);
        }
        else{
            while(s.size() > 0 && price[i] >= price[s.top()]){
                s.pop();
            }
            if (s.size() == 0){
                v.push_back(i+1);
            }
            else{
                v.push_back(i-s.top());
            }
        }
         s.push(i);
    }
    for(int i = 0; i < n; i++){
        cout << v[i] << " ";
    }
}
int main (){
int arr[7] = {100,80,60,70,75,85,110};
stock_span_II(arr,7);

}