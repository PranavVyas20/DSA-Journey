#include<iostream>
using namespace std;


int string_length(char str[]){
   if (str[0] == '\0'){
         return 0;
   }

   int small = string_length(str + 1);
   return small + 1;
}

int main (){

char s[100];

cout << string_length(s);
}