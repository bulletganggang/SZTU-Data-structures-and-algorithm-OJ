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
    int add(seqlist &l1,seqlist &l2)
    {
        size=l1.size+l2.size;
        int i=0,j=0,k=0;
        while (i<l1.size and j<l2.size)
        {
            if (l1.list[i]<l2.list[j])
            {
                list[k]=l1.list[i];
                i++;
                k++;
            }
            else
            {
                list[k]=l2.list[j];
                j++;
                k++;
            }
        }
        while (i<l1.size)
        {
            list[k]=l1.list[i];
            k++;
            i++;
        }
        while (j<l2.size)
        {
            list[k]=l2.list[j];
            j++;
            k++;
        }
        show();
        return ok;
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
    list = new int[max];
}

seqlist::~seqlist()
{
    delete []list;
}

int main()
{
    seqlist l1,l2,l3;
    l1.insert();
    l2.insert();
    l3.add(l1,l2);
    system("pause");
}  