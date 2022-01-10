#include<iostream>
using namespace std;

void merge_arrays(int array[],int si,int ei){
    int size = ei + 1;
    int mid = (si + ei) / 2;
    int i = si;
    int j = mid + 1;
    int k = 0;
    int temp_array[size];

    while (i <= mid && j <= ei){
        if (array[i] < array[j]){
            temp_array[k] = array[i];
            i++;
            k++;
        }
        else{
            temp_array[k] = array[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        temp_array[k] = array[i];
        i++;
        k++;
    }
    while(j <= ei){
        temp_array[k] = array[j];
        j++;
        k++;
    }

int m = 0;
    for (int i = si; i <= ei; i++){
        array[i] = temp_array[m];
        m++;
    }
}

void merge_sort(int array[],int si,int ei){
    int mid = (si + ei) / 2;
    if (si == ei){
        return;
    }
    merge_sort(array,si,mid);
    merge_sort(array,mid + 1,ei);

    merge_arrays(array,si,ei);
}

int main (){
int test_array[10] = {4,3,6,2,8,1,5,7,10,9};
merge_sort(test_array,0,9);


for (int i = 0; i < 10; i++){
    cout << test_array[i] << " ";
}

}