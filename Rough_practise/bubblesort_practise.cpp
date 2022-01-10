#include<iostream>
using namespace std;

void bubble_sort(int array[],int n){
    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - 1 - i; j++){
            if (array[j] > array[j+1]){
                swap(array[j],array[j+1]);
            }
        }
    }
}
int main (){
    
int arr[5] = {2,3,5,1,6};

int size = sizeof(arr)/sizeof(arr[0]);

bubble_sort(arr,size);

// printting the array
cout << "array after sorting " << endl;
for (int i = 0; i < size; i++){
    cout << arr[i] << " ";
}

}