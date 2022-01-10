#include<iostream>
using namespace std;

void fibonacci(int n){
int n1 = 0;
int n2 = 1;
int sum = 0;

for (int i = 0; i < n; i++){
    cout << sum << " ";
    n1= n2;
    n2 = sum;
    sum = n1 + n2;

  }
}

int main (){

fibonacci(6);

}










