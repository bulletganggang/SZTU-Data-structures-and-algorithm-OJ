#include<iostream>
#include<string>
using namespace std;

int getnext(string a)
{
    int i=0,k=-1;
    int len=a.length(),maxn=0;
    int *nex=new int[a.length()+1];
    nex[0]=-1;
    while(i<len)
    {
        if(k==-1||a[i]==a[k])
        {
            nex[++i]=++k;
            if(k*2<=i)  maxn=max(maxn,k);
            if(i/(i-k)>=2)  maxn=max(maxn,(i-k)*(i/(i-k)/2));
        }
        else k=nex[k];
    }
    return maxn;
}

int getmaxnum(string a)
{
    int len=a.length(),maxn=0;
    for(int i=0;i<len;i++)
    {
        maxn=max(maxn,getnext(a.substr(i,len)));
    }
    return maxn;
}

int main()
{
    string a;
    int n;
    cin>>n;
    while(n--)
    {
    cin>>a;
    int num=getmaxnum(a);
    if(!num) cout<<-1<<endl;
    else cout<<num<<endl;
    }
    return 0;
}