#include<iostream>
#include<string>
using namespace std;
int nex[1000000];

void getnext(string a)
{
    int i=0,j=-1;
    int len=a.length();
    nex[0]=-1;
    while(i<len)
    {
        if(j==-1||a[i]==a[j])
        {
            nex[++i]=++j;
        }
        else j=nex[j];
    }
    for(int i=0; i<len; i++) cout<<nex[i]<<" ";
    cout<<endl;

}

int KMP(string a,string b)
{
    int i=0,j=0;
    int len1=a.length(),len2=b.length();
    getnext(b);
    while(i<len1&&j<len2)
    {
        if(j==-1||a[i]==b[j]) 
            i++,j++;
        else j=nex[j];
    }
    if(j==len2)
        return i-j+1;
    else return 0;
}

int main()
{
    string a,b;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>a>>b;
        cout<<KMP(a,b)<<endl;
    }
    return 0;
}
