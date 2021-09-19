#include<iostream>
#include<array>
using namespace std;



int size_of(int arr[]){
    int count = 0;
    int i = 0;
  for (int i:arr){
      count ++;
  }
    return count;
}







int* merge_sort(int final_arr[],int low,int high){
    if (low == high){
        int temp_arr[1];
        temp_arr[0] = final_arr[low];
        return temp_arr;
    }

    int mid = (low + high)/2;
    int temp1[] = merge_sort(final_arr,low,mid);

}







void merge_arrays(int array1[],int array2[],int size1,int size2){
    int i = 0,j = 0,k = 0;
    int c = size1 + size2;
    int array3[c];

    while (i < size1 || j < size2 ){
        if (array1[i] < array2[j]){
            array3[k] = array1[i];
            i++;
            k++;
        }
        else{
            array3[k] =  array2[j];
            j++;
            k++;
        }
    }
    while (i < size1){
        array3[k] = array1[i];
        i++;
        k++;
    }
    while(j < size2){
        array3[k] = array2[j];
        j++;
        k++;
    }

    for (int i = 0; i < 13; i++){
        cout << array3[i] << " ";
    }
}





int main (){

    int a[5] = {2,5,12,18,20};
    int b[8] = {7,9,11,15,25,28,30,36};
    int size1 = (sizeof(a))/sizeof(a[0]);
    int size2 = (sizeof(b))/sizeof(b[0]);
    // merge_arrays(a,b,size1,size2);
   cout << size_of(a);
}





// Merge sort in C++

#include <iostream>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  
  // Create L ← A[p..q] and M ← A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
  }
}

// Print the array
void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

// Driver program
int main() {
  int arr[] = {6, 5, 12, 10, 9, 1};
  int size = sizeof(arr) / sizeof(arr[0]);

  mergeSort(arr, 0, size - 1);

  cout << "Sorted array: \n";
  printArray(arr, size);
  return 0;
}















