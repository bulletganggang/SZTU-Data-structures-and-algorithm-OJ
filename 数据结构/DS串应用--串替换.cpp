#include<iostream>
#include<string>
using namespace std;
int nex[1000000];

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

int kmp(string a,string b)
{
    int len=a.length(),len1=b.length();  //a zhu  b model
    int i=0,j=0;
    getnext(b);
    while (i<len and j< len1)
    {
        if (j==-1 or a[i]==b[j])
        {
            i++,j++;
        }
        else j=nex[j];
    }
    if (j==len1)
    {
        return i-j+1;
    }
    else return 0;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string a,b,c;  //a zhu b model c th
        cin>>a>>b>>c;
        cout<<a<<endl;
        int index=kmp(a,b);
        if (index!=0)
        {
            cout<<a.replace(a.begin()+index-1,a.begin()+index+b.length()-1,c)<<endl;
        }
        else cout<<a<<endl;
    }
    system("pause");
}