#include <iostream>
using namespace std;

void print(int *a, int n)  //打印结果
{
    for (int i = 0; i < n; i++)
    {
        cout<<a[i];
        if (i!=n-1) cout<<" ";
    }
    cout<<endl;
}

void zheban(int *a,int n)
{
    for (int i = 1; i < n; i++)
    {
        int min=0;
        int max=i-1;
        int j,temp=a[i];
        while (min<=max)
        {
            int mid=(min+max)/2;
            if (a[i]<=a[mid])
            {
                min=mid+1;
            }
            else
            {
                max=mid-1;
            }
        }
        for (j = i-1; j > max; j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
        print(a,n);
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
        int *a=new int[n];
        for (int i = 0; i < n; i++)
        {
            cin>>a[i];
        }
        zheban(a,n);
        cout<<endl;
    }
    system("pause");
}