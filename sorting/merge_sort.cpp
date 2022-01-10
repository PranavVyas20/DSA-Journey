#include<iostream>
using namespace std;

void merge_arrays(int array[],int si,int ei){
    
    cout << "merge arrays called , si =  " << si << endl;
    int mid = (si + ei) / 2;
    int i = si;
    int j = mid +1;
    int k = 0;
    int temp_final_array[ei+1];

    while(i <= mid && j <= ei){
        if (array[i] < array[j]){
            temp_final_array[k] = array[i];
            i++;
            k++;
        }
        else{
            temp_final_array[k] = array[j];
            j++;
            k++;
        }
    }
    while(i <= mid){
        temp_final_array[k] = array[i];
        i++;
        k++;
    }
    while(j <= ei){
        temp_final_array[k] = array[j];
        j++;
        k++;
    }

    ///  why this step we did
    int m = 0;
    for (int z = si; z <= ei; z++){
        cout << "z = " << z  << " "<< "m " << m << " " << endl;
        array[z] = temp_final_array[m];
        m++;
    }

    
}

void merge_sort(int array[],int si,int ei){
    int mid = (si + ei) / 2;
    if (si >= ei){
        return;
    }
    merge_sort(array,si,mid);
    merge_sort(array,mid + 1,ei);
    merge_arrays(array,si,ei);
}

int main (){

int array[] = {5,7,-2,4,1,3};

merge_sort(array,0,5);

for (int i = 0; i < 6; i++){
    cout << array[i] << " ";
}

}