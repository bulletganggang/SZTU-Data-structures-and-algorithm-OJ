#include <iostream>
using namespace std;

class list
{
private:
    int *num1,*num2;
    int l1,l2;
public:
    list(){}
    void create()
    {
        cin>>l1;
        num1=new int[l1];
        for (int i = 0; i < l1; i++)
        {
            cin>>num1[i];
        }
        cin>>l2;
        num2=new  int[l2];
        for (int i = 0; i < l2; i++)
        {
            cin>>num2[i];
        }
    }
    void cz()
    {
        int t;
        cin>>t;
        while (t--)
        {
            int m,sum=0,a,b;
            cin>>m;
            if (m<=num2[0])
            {
                a=0;
                b=l1/l2; 
                sum++;
            }
            else if (m>num2[l2-1])
            {
                cout<<"error\n";
                return;
            }
            else
            {
                for (int i = 0; i < l2-1; i++)
                {
                    if (m>num2[i] and m<=num2[i+1])
                    {
                        a = (i+1)*(l1/l2);  //起点
                        b = (i+2)*(l1/l2);  //终点
                        sum += i+2;
                        break;
                    }
                }
            }
            int c=a;
            sum++;
            while (num1[c]!=m and c<b)
            {
                c++;
                sum++;
            }
            if (c==b) cout<<"error\n";
            else cout<<c+1<<"-"<<sum<<endl;
        }
    }
    void print()
    {
        for (int i = 0; i < l1; i++)
        {
            cout<<num1[i]<<" ";
        }
        cout<<endl;
        for (int i = 0; i < l2; i++)
        {
            cout<<num2[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    list l;
    l.create();
    l.cz();
    //l.print();
    system("pause"); 
}