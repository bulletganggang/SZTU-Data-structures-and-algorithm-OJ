#include<iostream>
using namespace std;

void search(int *num,int n,int *max,int *index)
{
    int j=*(num+0);
    for (int i = 1; i < n; i++)
    {
        if (j<num[i])
        {
            *max=*(num+i);
            *index=i;
        }
    }
}

void input(int *num,int n)
{
    for (int i = 0; i < n; i++)
    {
        cin>>num[i];
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int *num=new int [n];
        input(num,n);
        int *max=num+0,a=0;
        int *index=&a;
        search(num,n,max,index);
        cout<<*max<<" "<<*index<<endl;
    }
    system("pause");
}