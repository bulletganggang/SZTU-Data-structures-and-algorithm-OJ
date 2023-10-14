#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string a,b,c;
        cin>>a>>b>>c;
        int a1,a2,b1,b2,c1,c2;
        cin>>a1>>a2>>b1>>b2>>c1>>c2;
        int len=a2-a1+b2-b1+c2-c1+3;
        char *op=new char [len];
        int x=0;
        for (int i = a1-1; i <= a2-1; i++)
        {
            *(op+x)=a[i];
            x++;
        }
        for (int i = b1-1; i <= b2-1; i++)
        {
            *(op+x)=b[i];
            x++;
        }
        for (int i = c1-1; i <= c2-1; i++)
        {
            *(op+x)=c[i];
            x++;
        }
        for (int i = 0; i < len; i++)
        {
            cout<<*(op+i);
        }
        cout<<endl;
    }
    system("pause");
}