#include<iostream>
using namespace std;

void merge_arrays(int arr[],int sii,int eii){
    int mid = (sii + eii) / 2;
    int size = eii  + 1;
     int final[size];
     int i = sii, j = mid + 1, k = 0;

    while(i <= mid && j <= eii){
        if (arr[i] < arr[j]){
            // cout << arr[i] << "  <  " << arr[j] << endl;
            final[k] = arr[i];
            i++;
            k++;
        }
        else{
            // cout << arr[i] << "  >  " << arr[j]  << endl;
            final[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        final[k] = arr[i];
        i++;
        k++;

    }
    while(j <= eii){
        final[k] = arr[j];
        j++;
        k++;
    }
   
int m = 0;
for (int i = sii; i <= eii; i++){
    arr[i] = final[m];
    m++;
} 

}

void merge_sort(int arr[],int si,int ei){
    if (si >= ei){
        return;
    }
     int mid = (si + ei)/ 2;
     merge_sort(arr,si,mid);
     merge_sort(arr,mid + 1,ei);
   
  merge_arrays(arr,si,ei);

  
}
int main (){
int test_array[10] = {4,3,6,2,8,1,5,7,10,9};
merge_sort(test_array,0,9);


for (int i = 0; i < 10; i++){
    cout << test_array[i] << " ";
}

} 