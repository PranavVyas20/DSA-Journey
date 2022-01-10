#include<iostream>
using namespace std;

string reverse_string(string str){
    string final_string;
    int i = 0;
    int n = str.length();

    while(i < n){
        while (i < n && str[i] == ' '){
            i++;
        }
        
        // Checking i beacuse agar kahi uper wale loop se > n ho gya to 
        // we can exit the loop 
          if (i >= n){
                break;
            }
         
        int j = i + 1;

        while (j < n && str[j] != ' '){
            j++;
        }
       
        string sub = str.substr(i,j - i);
     

        if (final_string.length() == 0){
            final_string = sub;
        }
        else{
            final_string = sub  + " "  +  final_string;
        }
            i = j; // or i = j + 1
    }

   return final_string;
}
int main (){
    
string stri = "sun is the blue   y " ;    

cout << reverse_string(stri);
// cout << stri;


}