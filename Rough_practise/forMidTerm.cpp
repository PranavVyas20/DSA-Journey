#include<iostream>
using namespace std;

void display_array(int arr[],int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " " ;
    }
    cout << endl;
}

// int main (){
// int arr[6] = {4,3,6,7,2,1};
// int size = 6;
// selection_sort(arr,6);
// }


void bubble_sort(int arr[],int size){
    for (int i = 0; i < size - 1 ; i++){
        for (int j = 0; j < size - 1-i ; j++){
            if (arr[j] > arr[j + 1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
    display_array(arr,size);
}
void insertion_sort(int arr[],int size){

    for (int i = 1; i < size; i++){

        int current_element = arr[i];

        int j = i-1;

        for (j; j >= 0; j--){

            if (current_element < arr[j]){
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
        }
        arr[j+1] = current_element;
    }
    display_array(arr,size);

}

int partition(int arr[],int si,int ei){
    int x = arr[si];
    int count = 0;
    int final_array[ei + 1];

    for (int i = 0; i <= ei; i++){
        if (arr[i] < x){
            count ++;
        }
    }
    swap(arr[si],arr[count]);

    int i = si;
    int j = ei;
    int k = 0;

    while(i < count && j >= count + 1){
        if (arr[i] < x){
            i++;
        }
        else if (arr[j] > x){
            j++;
        }
        else{
            swap(arr[i],arr[j]);
            i++;
            k++;
        }
    }
    return count;
}
void quick_sort(int arr[],int si,int ei){
    if (si >= ei){
        return;
    }
    int pivot_point = partition(arr,si,ei);
    quick_sort(arr,si,pivot_point);
    quick_sort(arr,pivot_point + 1,ei);
}


int main (){
int arr[6] = {1,3,5,7,9,11};
int size = 6;

// selection_sort(arr,6);
// binarySearch(arr,6,3);
// bubble_sort(arr,6);
// insertion_sort(arr,size);
// quick_sort(arr,0,5);
// display_array(arr,6);


}