#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int x;
        cin>>x;
        int *a=new int[x];
        for (int i = 0; i < x; i++)
        {
            cin>>a[i];
        }
        int *p=a+ x/2;
        cout<<*(p-1)<<" "<<*(p+1)<<endl;
        int y;
        cin>>y;
       cout<<*(p+((y-1)- x/2))<<endl;
    }
    system("pause");
}