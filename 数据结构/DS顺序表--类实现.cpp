#include<iostream>
using namespace std;

#define ok 0
#define error -1

class seqlist
{
private:
    int *list;
    int max;
    int size;
public:
    seqlist();
    ~seqlist();
    int get(int i)
    {
        if (i<1 or i > size+1 or size > max)
        {
            cout<<"error"<<endl;
            return error;
        }
        else
        {
            cout<<list[i]<<endl;
            return ok;
        }
    }
    int getsize()
    {
        size++;
        return ok;
    }
    int insert1(int i,int item)
    {
        if (i<1 or i> size+1 or size > max)
        {
            cout<<"error"<<endl;
            return error;
        }
        else
        {
           size++;
        for (int j = size; j > i; j--)
        {
            list[j]=list[j-1];
        }
        list[i]=item;
        show();
        return ok;
        }
    }
    int insert2(int i,int item)
    {
        size++;
        list[i]=item;
        return ok;
    }
    int del(int i)
    {
        if (i<1 or i> size+1 or size > max)
        {
            cout<<"error"<<endl;
            return error;
        }
        else
        {
            for (int j = i; j <= size; j++)
        {
            list[j]=list[j+1];
        }
        size--;
        show();
        return ok;
        }
        
    }
    void show()
    {
        cout<<size<<" ";
        for (int i = 1; i <= size; i++)
        {
            cout<<list[i]<<" ";
        }
        cout<<endl;
    }
};

seqlist::seqlist()
{
    max=1000;
    size=0;
    list = new int[max];
}

seqlist::~seqlist()
{
    delete []list;
}

int main()
{
    int n;
    seqlist l;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin>>x;
        l.insert2(i+1,x);
    }
    l.show();
    for (int i = 0; i < 2; i++)
    {
        int a,b;
        cin>>a>>b;
        l.insert1(a,b);
    }
    for (int i = 0; i < 2; i++)
    {
        int a;
        cin>>a;
        l.del(a);
    }
    for (int i = 0; i < 2; i++)
    {
        int a;
        cin>>a;
        l.get(a);
    }
    return 0;
}