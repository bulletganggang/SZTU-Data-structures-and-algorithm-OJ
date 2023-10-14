#include<iostream>
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

void selectsort(int *a,int n)
{
    for (int i = 0; i < n; i++)
    {
        int min=i;
        for (int j = i+1; j < n; j++)
        {
            if (a[j]<a[min])
            {
                min=j;
            }
        }
        if (min!=i)
        {
            swap(a[i],a[min]);
        }
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
        selectsort(a,n);
        cout<<endl;
    }
    system("pause");
}