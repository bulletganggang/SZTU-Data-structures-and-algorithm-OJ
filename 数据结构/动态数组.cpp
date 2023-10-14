#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        char op;
        int x;
        cin>>op>>x;
        if (op =='C')
        {
            char *a=new char[x];
            for (int i = 0; i < x; i++)
            {
                cin>>a[i];
            }
            
        char m=a[0];
        for (int i = 1; i < x; i++)
        {
           if (m<a[i])
           {
                m=a[i];
           }
        }
        cout<<m<<endl;
        }
        if (op =='I')
        {
            int *a=new int[x];
            for (int i = 0; i < x; i++)
            {
                cin>>a[i];
            }
        int m=a[0];
        for (int i = 1; i < x; i++)
        {
            m+=a[i];
        }
        m/=x;
        cout<<m<<endl;
        }
        if (op =='F')
        {
            float *a=new float[x];
            for (int i = 0; i < x; i++)
            {
                cin>>a[i];
            }
        float m=a[0];
        for (int i = 1; i < x; i++)
        {
            if (m>a[i])
            {
                m=a[i];
            }
        }
        cout<<m<<endl;
        }
    }
    system("pause");
}