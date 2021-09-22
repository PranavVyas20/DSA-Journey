#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int mah(vector<int> arr){
// Finding the NSR and storing it in an vector "NSR"
    stack<int> s1;
    vector<int> NSR;
    int n = arr.size();
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
    // for (int i = 0; i < NSR.size(); i++){
    //     cout << NSR[i] << " ";
    // }
    cout << endl;

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
    //   for (int i = 0; i < NSR.size(); i++){
    //     cout << NSL[i] << " ";
    // }
    cout << endl;

    // Creating the width array and storing elements in it
    //width_v[i] = NSR[i] - NSL[i]) - 12
    // and then multiplying width_v[i] * arr[i] to find the area made by each item in arr[]
    vector<int> width_v;
    for (int i = 0; i<n; i++){
        width_v.push_back(((NSR[i] - NSL[i]) - 1) * arr[i]);
        // cout << width_v[i] << " ";
    }
    // Now the last step i.e finding the max out of all the areas from the width_v 
    return *max_element(width_v.begin(),width_v.end());
}

void max_area(vector<vector<int>> mat,int r,int c){
int max = 0;
     vector<int> temp(r,0);
    for (int i = 0; i < r; i++){
       for (int j = 0; j < c; j++){
        // temp.push_back(mat[i][j]);
        if (mat[i][j] == 0){
            temp[j] = 0;
        }
        else{
        temp[j] = temp[j] + mat[i][j];
        }
        cout << temp[j] << " ";
    }
        int temp2 = mah(temp);
        if (temp2 > max){
            max = temp2;
        }
  }
    cout << "max area: " << max;
}

int main (){
int r = 4;
int c= 4;
// cout << mah(arr2);
int matrix[r][c] = { {0,1,1,0},
                     {1,1,1,1},
                     {1,1,1,1},
                     {1,1,0,0} };
// Putting the elements of the arryay in an vector (2d)
vector<vector<int>> m;
for (int i = 0; i < r; i++){
    vector<int> v1;
    for (int j = 0; j < c; j++){
        v1.push_back(matrix[i][j]);
        // cout << v1[j] << " ";
    }
    m.push_back(v1);
}
max_area(m, r, c);


}