#include<iostream>
using namespace std;

int partition(int array[],int si,int ei){

int x = array[si];
int count = 0;
// Finding the number of elements that are smaller than x
for (int i = 0; i <= ei; i++){
    if (array[i] < x){
        count ++;
    }
}

// placing the 'x' on the correct position
// starting index mein hamesha 0 aaye is not necessary
swap(array[si],array[count]);

// placing all the elements smaller than x to the left and elements larger than x 
// to the right
int i = si,j = ei;
while(i < count && j >= count + 1){
    if (array[i] < x){
        i++;
    }
    else if (array[j] > x){
        j--;
    }
    else{
        swap(array[i],array[j]);
        i++;
        j--;
    }
}
return count;
}

void quick_sort(int array[],int si,int ei){
    if (si >= ei){
        return;
    }
    int my_partition =  partition(array,si,ei);
    quick_sort(array,si,my_partition - 1);
    quick_sort(array,my_partition + 1,ei);

}

int main (){
int test_array[] = {1,3,2,4,5,6,7,8};
quick_sort(test_array,0,7);

// printting the array for debugging
for (int i = 0; i <  8; i++){
    cout << test_array[i] << " ";
}

}