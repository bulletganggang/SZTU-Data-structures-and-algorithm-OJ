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
    int insert1(int i,int n,int item[])
    {
        if(i<0||i>size+1)
        {
			return error;
		}
        else
        {
        int x=0;
        for (int k = 0; k < n; k++)
        {
        size++;
        for (int j = size-1; j > i-1; j--)
        {
            list[j]=list[j-1];
        }
        }
        for (int j = 0; j < n; j++)
        {
            list[i+x-1]=item[j];
            x++;
        }
        show(); 
        return ok;
        }
    }
    int insert2()
    {
        int i,n;
        cin>>n;
        size=n;
        for (int i = 0; i < n; i++)
        {
            cin>>list[i];
        }
        show();
        return ok;
    }
    int del(int i,int n)
    {
        if(i<0||i>size)
        {
			return error;
		}
        else
        {
           for (int k = 0; k < n; k++)
        {
          for (int j = i-1; j < size-1; j++)
        {
            list[j]=list[j+1];
        }
        size--;
        }   
        show(); 
        return ok;
        }
    }
    void show()
    {
        cout<<size<<" ";
        for (int i = 0; i < size; i++)
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
    list = new int[max+5];
}

seqlist::~seqlist()
{
    delete []list;
}

int main()
{
    seqlist l;
    l.insert2();
    int a,b;
    cin>>a>>b;
    int *c=new int [b];
    for (int i = 0; i < b; i++)
    {
        cin>>c[i];
    }
    l.insert1(a,b,c);
    delete []c;
    cin>>a>>b;
    l.del(a,b);
    system("pause");
    return 0;
}