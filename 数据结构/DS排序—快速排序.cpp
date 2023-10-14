#include<iostream>
using namespace std;

int qs(int *a,int start,int end)
{
    int i=start;
    int j=end;
    while (i<j)
    {
        while (i<j and a[i]<=a[j]) j--;
        if (i<j)
        {
            swap(a[i],a[j]);
            i++;
        }
        while (i<j and a[i]<=a[j]) i++;
        if (i<j)
        {
            swap(a[i],a[j]);
            j--;
        }
    }
    cout<<a[j]<<" "<<i+1<<endl;
    return j;
}

void quicksort(int *a,int start,int end)
{
    if (start<=end)
    {
        int pos=qs(a,start,end);
        quicksort(a,start,pos-1);
        quicksort(a,pos+1,end);
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
        quicksort(a,0,n-1);
        cout<<endl;
    }
    system("pause");
}