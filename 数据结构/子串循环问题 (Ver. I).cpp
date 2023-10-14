#include <iostream>
#include <string>
using namespace std;

int getnext(string a)
{
    string t1, t2;
    int len = a.length();
    int j = 0; 
    for(int i=0; i<len-1; i++)
    {
        t1 = a.substr(0, i+1);
        t2 = a.substr(len-1-i);
        if(t1==t2 && i+1>j)
            j = i+1;
    }
    return j;
}

int main(void)
{
    int i, n;
    cin>>n;
    for(i=0; i<n; i++)
    {
        string a;
        cin>>a;
        int len = a.length();
        int next_len = getnext(a);
        int L = len-next_len;
        if(!(len%L) && len!=L)
            cout<<'0'<<endl;
        else
            cout<<L-len%L<<endl;
    }
    return 0;
}
