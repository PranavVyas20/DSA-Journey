#include<iostream>
using namespace std;

int main (){
int n = 3;
int s1 = 4;
int s2 = 5;
int s3 = 4;


int arr[n][max(s1,s2,s3)];

int temp = min(s1,s2,s3);

for (int i = 0; i < n; i++){
    if (i == 0){
        temp = min(s1,s2,s3);
    }
    else{
        temp = max(s1,s2,s3);
    }
    for (int j = 0; j < temp; j++){
       cin >>  arr[i][j];
    }
}

for (int i = 0; i < n; i++){
    if (i == 0){
        temp = min(s1,s2,s3);
    }
    else{
        temp = max(s1,s2,s3);
    }
    for (int j = 0; j < temp; j++){
       cout <<  arr[i][j] << " ";
    }
    cout << endl;
}

}