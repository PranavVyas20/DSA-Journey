#include<iostream>
#include <array>
using namespace std;

void display_array(int arr[],int size){
    for (int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}
void binary_search(int arr[],int size,int key){
    int start = 0; 
    int end = size - 1;
    while(end > start){

        int mid = (start + end) / 2;
        
        if (arr[mid] == key){
            cout << "found at " << mid ;
            return;
        }
        else if (key > arr[mid]){
            start = mid + 1;
        }
        else if (key < arr[mid]){
            end  = mid - 1;
        }
    }
    cout << "not found";
}
void selection_sort(int arr[],int size){
for (int i = 0; i < size - 1; i++){
    for (int j = i; j < size; j++){
        if (arr[i] > arr[j]){
            swap(arr[i],arr[j]);
        }
    }
}
display_array(arr,size);

}

void bubble_sort(int array[],int size){
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - 1 - i; j++){
            if (array[j] > array[j + 1]){
                 swap(array[j],array[j + 1]);
            }
        }
    }
    display_array(array,size);
}

void insertion_sort(int array[],int size){
for (int i = 1; i < size; i++){
    int current = array[i];
    int j;
    for (j = i - 1; j >= 0; j--){
        if (current < array[j]){
            array[j + 1] = array[j];
        }
        else{
            break;
        }
    }
    array[j + 1] = current;
}
display_array(array,size);
}











void merge_arrays(int array_1[],int array_2[],int array3[]){
int i = 0;
int j = 0;
int k = 0;
// int size_1 = (sizeof(array_1) / array_1[0]);
// int size_2 = (sizeof(array_2) / array_2[0]);

// int sorted_array [13];

while (i < 5 && j < 8){   // why not use OR 
    if (array_1[i] < array_2[j]){
         array3[k] = array_1[i];
         cout << array3[k] << " ";
         i++;
         k++;   
    }
    else {
        array3[k] = array_2[j];
         cout << array3[k] << " ";

        j++;
        k++;
    }
}
    while (i < 5){
        array3 [k] = array_1[i];
         cout << array3[k] << " ";

        i++;
        k++;
    }
      while (j < 8){
        array3 [k] = array_2[j];
         cout << array3[k] << " ";

        j++;
        k++;
    }
}
int main (){
    int my_array[5] = {1,2,3,4,5};
    binary_search(my_array,5,3);
    // cout << endl;
    // int test_array[5] = {5,9,8,1,2};
    // selection_sort(test_array,5);



    // int a1[5]  = {2,5,12,18,20};
    // int a2[8] = {7,9,11,15,25,28,30,35};
    // int sorted_array [13];
    // merge_arrays(a1,a2,sorted_array);

    // // for (int i = 0; i < 13; i ++){
    // //     cout << sorted_array [i] << " ";
    // // }




   
    // bubble_sort(my_array,5);

    // int array_size = (sizeof(my_array)) / 4;
    // selection_sort(my_array,array_size);

    
    // insertion_sort(my_array,5);
}