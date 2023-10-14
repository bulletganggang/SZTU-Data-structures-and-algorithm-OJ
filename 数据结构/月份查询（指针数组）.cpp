#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    const char *op[12]={"January","February","March","April","May","June",
    "July","Aguest","September","October","November","December" };
    while (t--)
    {
        int x;
        cin>>x;
        if (x<=0 or x>=13)
        {
            cout<<"error"<<endl;
            continue;
        }
        cout<<op[x-1]<<endl;
    }
    system("pause");
}