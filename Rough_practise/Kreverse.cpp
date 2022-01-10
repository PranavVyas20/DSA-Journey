#include<iostream>
using namespace std;

void binary_search(int arr[],int size,int key){
    int start = 0;
    int end = size - 1;
    int mid = (start + end) / 2;

    while(end > start){
        if (arr[mid] == key){
            cout << "found at " << mid;
            return;
        }
        else if (arr[mid] > key){
            start = mid + 1;
        }
        else if (arr[mid] < key){
            end = mid - 1;
        }
    }
    cout << "element not found" ;
    return;
}
int main (){
int test_array[5] = {1,2,4,7,9};
binary_search(test_array,5,9);

}