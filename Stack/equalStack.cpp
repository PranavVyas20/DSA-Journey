#include<iostream>
#include<stack>
using namespace std;

int arraySum(int arr[],int size){
    int sum = 0;
    for (int i = 0; i< size; i++){
        sum = sum + arr[i];
    }
    return sum;
}

int maxHeight(stack<int> s1,stack<int> s2, stack<int> s3){
    int arr1[],int size1,int arr2[],int size2,int arr3[],int size3
int s1 = arraySum(arr1,size1);
int s2 = arraySum(arr2,size2);
int s3 = arraySum(arr3,size3);

int maxx = max(s1,s2,s3);

if (maxx == s1){

}
}
int main (){
stack <int> st1;
stack <int> st2;
stack <int> st3;

int n1,n2,n3;
cin >> n1 >> n2 >> n3;

int array1[n1];
int array2[n2];
int array3[n3];

// taking the input in the arrays
for (int i = 0; i < n1; i++){
    // cin >> array1[i];
    st1.push(array1[i]);
}

for (int i = 0; i < n2; i++){
    // cin >> array2[i];
    st2.push(array2[i]);
}

for (int i = 0; i < n3; i++){
    // cin >> array3[i];
    st3.push(array3[i]);
}

// // printing the arrays 
// for (int i = 0; i < n1; i++){
//     cout << array1[i] << " ";
// }
// cout << endl;

// for (int i = 0; i < n2; i++){
//     cout << array2[i] << " ";
// }
// cout << endl;

// for (int i = 0; i < n3; i++){
//     cout << array3[i] << " ";
// }
// cout << endl;


}