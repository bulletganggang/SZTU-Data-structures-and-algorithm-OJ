#include<iostream>
#include<string>
using namespace std;

int main()
{
    string a;        
    cin >> a;
    int len = a.size();
    char s[105];
    int top = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == '(' or a[i] == '{' or a[i] == '[')
        {
            s[top++] = a[i]; 
        } 
        else if (a[i] == ')') 
        {
            if (s[--top]== '(')
            {
                continue;
            } 
            else
            {
                cout << "No";
                return 0;
            }
        }
        else if (a[i] == ']') 
        {
            if (s[--top]== '[')
            {
                continue;
            } 
            else
            {
                cout << "No";
                return 0;
            }
        }
        else if (a[i] == '}') 
        {
            if (s[--top]== '{')
            {
                continue;
            } 
            else
            {
                cout << "No";
                return 0;
            }
        }
        else
        {
            continue;
        }
    }
    if (!top)
    {
        cout << "Yes";
        return 0;
    }
    cout << "No";
    return 0;
}
