#include<iostream>
#include<math.h>
using namespace std;
int a[1005];

int main()
{
    int n,i1=0,j1=0;
    int maxx=2333333;
    cin>>n;
    if (n==2)
    {
        cout<<"1 2\n";
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (abs(a[i]+a[j])<maxx)
            {
                maxx=abs(a[i]+a[j]);
                i1=i;
                j1=j;
            }
            if (maxx==0)
            {
                cout<<i1+1<<" "<<j1+1<<endl;
                system("pause");
                return 0;
            }
        }
    }
    cout<<i1+1<<" "<<j1+1<<endl;
    system("pause");
    return 0;
}