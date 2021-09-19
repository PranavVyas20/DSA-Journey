#include<iostream>
#include<stack>
using namespace std;

void isBalanced(string str){
    stack<char> s;

    for (int i = 0; i < str.length(); i++){
        if (str[i] == '(' || str[i] == '{' || str[i] == '['){
            s.push(str[i]);
        }
        else if (str[i] == ')'){
            if (s.top() == '('){
                s.pop();
            }
            else{
                cout << "not balanced";
                return;
            }
        }
        else if (str[i] == '}'){
            if (s.top() == '{'){
                s.pop();
            }
            else{
                cout << "not balanced";
                return;
            }
        }
        else if (str[i] == ']'){
            if (s.top() == '['){
                s.pop();
            }
            else{
                cout << "not balanced";
                return;
            } 
        }
    }
    if (s.empty() == true){
        cout << "balanced";
    }
    else{
        cout << "not balanced" ;
    }

}
int main (){
string test = "()[]{}";
isBalanced(test);


}