#include<iostream>
using namespace std;

int partition(int arr[],int si,int ei){

    int pivot = arr[si];
    int c = 0;
    // calculating the no of elements smaller than pivot
    for (int i = 0; i <= ei; i++){
        if (arr[i] < pivot){
            c ++;
        }
    }

    // placing the pivot element to its correct place
    swap(arr[si],arr[c]);
    int i = si;
    int j = ei;
  
    while(i < c && j > c){
        if (arr[i] < pivot){
            i++;
        }
        else if (arr[j] > pivot){
            j--;
        }
        else {
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
    } 
   return c;
}


void quick_sort(int arr[],int si,int ei){
if (si >= ei){
    return;
}
int pivot_point = partition(arr,si,ei);
quick_sort(arr,si,pivot_point-1);
quick_sort(arr,pivot_point+1,ei);
}


int main (){
int test_array[] = {5,9,8,3,2,7,1};

quick_sort(test_array,0,6);

for (int i = 0; i < 7; i++){
    cout << test_array[i] << " ";
}

}