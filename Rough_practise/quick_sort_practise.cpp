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
    int mid  = (si + ei) / 2;
    if (si >= ei){
        return;
    }
    int my_partition =  partition(array,si,ei);
    quick_sort(array,si,my_partition - 1);
    quick_sort(array,my_partition + 1,ei);

}

int main (){
int test_array[] = {5,7,-2,4,1,3};
quick_sort(test_array,0,5);
// partition(test_array,0,5);
// printting the array for debugging
for (int i = 0; i <  6; i++){
    cout << test_array[i] << " ";
}

}