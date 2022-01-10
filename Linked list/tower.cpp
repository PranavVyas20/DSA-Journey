#include<iostream>
using namespace std;

// 3 rings
void TOH(int n,char a,char b, char c){
    if (n == 0){
        return;
    }
    TOH(n-1,a,c,b);
    cout << "taking " << n << " from " << a << " to " << c << endl;
    TOH(n-1,b,a,c);
}
int main (){
TOH(9,'a','b','c');

}