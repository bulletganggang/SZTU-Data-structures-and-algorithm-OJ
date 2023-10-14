#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
    int **a=new int*[2];
    for (int i = 0; i < 2; i++)
    {
        a[i]=new int [3];
    }
    for (int i = 0; i < 2; i++)
    {
       for (int j = 0; j < 3; j++)
       {
            cin>>a[i][j];
       }
    }
    for (int j = 2; j>=0; j--)
    {
        for (int i = 0; i<=1 ; i++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    system("pause");
}