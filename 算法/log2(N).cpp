#include<iostream>
using namespace std;

int main()
{
    long long n;
    cin>>n;
    long long m=1;
    for (int i = 0; i < 105; i++)
    {
        if (n>m) m*=2;
        else 
        {
            cout<<i-1<<endl;
            system("pause");
            return 0;
        }
    }
}