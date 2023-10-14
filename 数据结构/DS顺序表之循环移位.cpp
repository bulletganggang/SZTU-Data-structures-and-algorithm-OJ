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
    int get()
    {
        return size;
    }
    int insert()
    {
        int i,n;
        cin>>n;
        size=n;
        for (int i = 0; i < n; i++)
        {
            cin>>list[i];
        }
        return ok;
    }
    void show()
    {
        for (int i = 0; i < size; i++)
        {
            cout<<list[i]<<" ";
        }
        cout<<endl;
    }
    int zuo(int n)
    {
        int a[n];
        for (int i = 0; i < n; i++)
        {
            a[i]=list[i];
        }
        int j=0;
        for (int i = n; i < size; i++)
        {
            list[j]=list[i];
            j++;
        }
        j=0;
        for (int i = size-n; i < size; i++)
        {
            list[i]=a[j];
            j++;
        }
        show();
        return 0;
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
    seqlist l;
    l.insert();
    int t=2;
    l.show();
    while (t--)
    {
        int a,b;
        cin>>a>>b;
        b%=l.get();
        if (a==1)
        {
            b=l.get()-b;
        }
        l.zuo(b);
    }
    system("pause");
}  