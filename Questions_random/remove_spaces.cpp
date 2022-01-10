#include<iostream>
using namespace std;

string remove_spaces(string str){
    int n = str.length();
  
    string str_2;
    int i = 0;

    while(i < n){
        while(i < n && str[i] == ' '){
            i++;
        }
          if (i >= n){
        break;
    }
    int j = i +1;

    while(j < n && str[j] != ' '){
        j++;
    }

    string temp_sub = str.substr(i,j-i);
   

    if (str_2.length()== 0){
        str_2 = temp_sub;
    }
    else{
        str_2 = str_2 + ' ' + temp_sub;
    }
    i = j;
    }

// length of the new strnig without spaces
    int len_without_spaces = str_2.length();

// now copying the elements of new string (wihout spaces ) to the original string
    for (int i = 0; i < n; i++){
        // if all the elemnts of the new string has been copied but still in the original
        // string there are elements left, then replace them wiht space
        if (i >= len_without_spaces){
            str[i] = ' ';
        }
        // copying the elements of the new string to the original string
        else{
        str[i] = str_2[i];
        }
    }
   return str;
}

int main (){
string test = "  the sky is blue     hu";
cout << remove_spaces(test);
}