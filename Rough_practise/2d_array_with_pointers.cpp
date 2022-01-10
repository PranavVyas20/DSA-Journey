#include<iostream>
using namespace std;


int print_fibonacci(int num){
    
    if (num <= 2){
      
        return num;
    }
   int a = print_fibonacci(num - 1);
   int b =  print_fibonacci(num - 2);
   return a + b;
}

int main (){
    int num2 = 5;
 for (int i = 1 ; i <= num2; i++){
       cout << print_fibonacci(i) << " ";
   }
 

                                        


}