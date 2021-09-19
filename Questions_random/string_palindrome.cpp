#include <iostream>
using namespace std;

void string_palindrome(string str)
{
    int n = str.length();
    int mid = n / 2;
    int i = 0;
    int j = n - 1;
    
    while (i < mid && j >= mid)
    {
        if (str[i] != str[j])
        {
            cout << "no";
            return;
        }
        i++;
        j--;
    }
    cout << "yes";
}
int main()
{
    string test_string = "aba";
    string_palindrome(test_string);
}