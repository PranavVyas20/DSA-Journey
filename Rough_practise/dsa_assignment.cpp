/* C++ program to implement basic stack
operations */
#include <bits/stdc++.h>

using namespace std;

#define MAX 1000

class Stack {
	int top;

public:
	int a[MAX]; // Maximum size of Stack

	Stack() { top = -1; }
	bool push(int x);
	bool isEmpty();
};

bool Stack::isEmpty()
{
	return (top < 0);
}

bool Stack::push(int x)
{
	if (top >= (MAX - 1)) {
		cout << "Stack Overflow";
		return false;
	}
	else {
		a[++top] = x;
		cout << x << " pushed into stack\n";
		return true;
	}
}

bool areBracketsBalanced(string expr)
{ 
    stack<char> s;
    char x;
 
    
    for (int i = 0; i < expr.length(); i++)
    {
        if (expr[i] == '(' || expr[i] == '['
            || expr[i] == '{')
        {
            s.push(expr[i]);
            continue;
        }
 

        if (s.empty())
            return false;
 
        switch (expr[i]) {
        case ')':
             
            x = s.top();
            s.pop();
            if (x == '{' || x == '[')
                return false;
            break;
 
        case '}':
 
            x = s.top();
            s.pop();
            if (x == '(' || x == '[')
                return false;
            break;
 
        case ']':
 
            x = s.top();
            s.pop();
            if (x == '(' || x == '{')
                return false;
            break;
        }
    }
 
    return (s.empty());
}
 
int main()
{
    string expr = "{(}}[]";
    cout << "given expression: " << expr << endl;
 
    if (areBracketsBalanced(expr))
        cout << "Balanced";
    else
        cout << "Not Balanced";
}







