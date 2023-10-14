#include<iostream>
#include<string>
using namespace std;
int nex[100005];

void getnext(string a)
{
    int len=a.length();
    int i=0,j=-1;
    nex[0]=-1;
    while (i<len)
    {
        if (j==-1 or a[i]==a[j])
        {
            nex[++i]=++j;
        }
        else j=nex[j];
    }
}

void kmp(string a,string b,int &in)
{
    int l1=a.length(),l2=b.length();
    getnext(b);
    int i=in,j=0;
    while (i< l1 and j<l2)
    {
        if (j==-1 or a[i]==b[j])
        {
            i++,j++;
        }
        else j=nex[j];
    }
    if (j==l2)
    {
        in=i-j+1;
    }
    else in=-1;
}

int main()
{
    string a;
    while (cin>>a)
    {
        int t;
        cin>>t;
        while (t--)
        {
            string b;
            cin>>b;
            int index=0;
            int sum=0;
            while (index>=0)
            {
                kmp(a,b,index);
                sum++;
            }
            cout<<b<<":"<<sum-1<<endl;
        }
    }
    system("pause");
}