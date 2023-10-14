#include<iostream>
using namespace std;

/*  test
9
6 3 2 4 1 5 77 8 10
8
34 23 677 2 1 453 3 7
*/

void print(int *a, int n)  //打印结果
{
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void insertsort(int *a,int n)  //插入排序
{
    for (int i = 1; i < n; i++)
    {
        int x=a[i];
        int j=i-1;
        while (j>=0)
        {  
            if (x<a[j])  //a[i]<a[j]
            {
                a[j+1]=a[j];  //a[i]=a[i-1];
                j--;
            }
            else break;
        }
        a[j+1]=x;
        print(a,n);
    }
}

void shellsort(int *a,int n)  //希尔排序
{
    int gap=n;
    while (gap>1)
    {
        gap/=2;
        for (int i = 0; i < n-gap; i++)
        {
            if (a[i]>a[i+gap])
            {
                swap(a[i],a[i+gap]);
            }
        }
        print(a,n);
    }
}

void bubblesort(int *a,int n)  //冒泡排序
{
    for (int i = 0; i < n-1; i++)  //进行n-1次循环
    {
        int flag=0;
        for (int j = 0; j < n-i-1; j++)  //一次循环进行交换
        {
            if (a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                flag=1;
            }
        }
        if (!flag) return;  //没有可交换的数，循环完毕
        print(a,n);
    }
}

void seletesort(int *a,int n)  //简单选择排序
{
    for (int i = 0; i < n-1; i++)
    {
        int min=i;
        for (int j = i+1; j < n; j++)  //找到最小值的下标
        {
            if (a[j]<a[min])
            {
                min=j;
            }
        }
        if (min!=i) swap(a[min],a[i]);
        print(a,n);
    }
}

void adjust(int *a,int root,int end)  //向下调整堆
{
    int i=root;
    int j=2*i+1;
    while (j<end)
    {
        if (j+1<end and a[j]<a[j+1])
        {
            j++;  //j为较大者
        } 
        if (a[i]<a[j])
        {
            swap(a[i],a[j]);
            i=j;
            j=2*i+1;
        }
        else break;
    }
}

void heapsort(int *a,int n)  //堆排序
{
    for (int i = n/2; i >= 0; i--)  //建立堆
    {
        adjust(a,i,n);
    }
    for (int i = n-1; i > 0; i--)
    {
        swap(a[0],a[i]);
        adjust(a,0,i);
        print(a,n);
    }
}

int qs(int *a,int first,int end)  //找到轴值
{
    int i=first;
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
    return i;
}

void quicksort(int *a,int first,int end)  //快速排序
{
    if (first<=end)
    {
        int pos=qs(a,first,end);
        quicksort(a,first,pos-1);
        quicksort(a,pos+1,end);
    }
}

void merge(int *a,int *b,int min,int mid,int max)  //归并
{
    int i=min;
    int j=mid+1;
    int k=min;
    while (i<=mid and j<=max)  //两个数组升序合并
    {
        if (a[i]<a[j])
        {
            b[k++]=a[i++];
        }
        else b[k++]=a[j++];
    }
    //合并剩余部分
    while (i<=mid)
    {
        b[k++]=a[i++];
    }
    while (j<=max)
    {
        b[k++]=a[j++];
    }
    //将备用数组的值复制回原来数组
    for (int i = min; i <= max; i++)
    {
        a[i]=b[i];
    }
}

void mergesort(int *a,int *b,int min,int max)  //归并排序
{
    if (min<max)
    {
        int mid=(min+max)/2; 
        mergesort(a,b,min,mid);    //递归划分左半区
        mergesort(a,b,mid+1,max);  //递归划分右半区
        merge(a,b,min,mid,max);    //合并已经排序好的部分
    }
    print(a,max+1);
}

int main()
{
    int n;
    cin>>n;
    int *a=new int[n];
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    //insertsort(a,n);
    //shellsort(a,n);
    //bubblesort(a,n);
    //seletesort(a,n);
    //heapsort(a,n);
    /*quicksort(a,0,n-1);  //注意end是n-1，因为n个数字末尾下标是n-1
    print(a,n);*/
    /*int *b=new int[n];
    mergesort(a,b,0,n-1);*/
    system("pause");
}