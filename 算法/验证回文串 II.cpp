#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

bool ishuiwen(string s,int i,int j)
{
    while(i<j)
    {
        if (s[i]==s[j])
        {
            i++;
            j--;
        }
        else return 0;
    }
    return 1;
}

bool test(string s)
{
    int i=0,j=s.length()-1;
    while (i<j)
    {
        if (s[i]==s[j])
        {
            i++;
            j--;
        }
        else return ishuiwen(s,i,j-1) or ishuiwen(s,i+1,j);
    }
    return 1;
}

int main()
{
    string s;
    cin>>s;
    if (test(s))
    {
        cout<<"true";
    }
    else cout<<"false";
    system("pause");
    return 0;
}