#include<iostream>
#include<string>
using namespace std;
int nex[1000000];

void getnext(string a)
{
    int i=0,k=-1;
    int len=a.length();
    nex[0]=-1;
    while(i<len)
    {
        if(k==-1||a[i]==a[k])
        {
            nex[++i]=++k;
        }
        else k=nex[k];
    }
}

void KMP(string a,string b,int &in)
{
    int i=in,j=0;
    int l1=a.length(),l2=b.length();
    getnext(b);
    while(i<l1 && j<l2)
    {
        if(j==-1||a[i]==b[j]) 
            i++,j++;
        else j=nex[j];
    }
    if(j==l2)
        in=i-j+1;
    else in=-1;
}

int main()
{
    string a;
    while (cin>>a)
    {
        string b;
        cin>>b;
        int index=0,sum=0;
        while (index>=0)
        {
            KMP(a,b,index);
            if (index%2!=0)
            {
                sum++;
            }
        }
        cout<<sum-1<<endl;
    }
    system("pause");
}
