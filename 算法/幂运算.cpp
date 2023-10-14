#include<iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, p, sum = 1;
        scanf("%lld %lld %lld", &a, &b, &p);
        while (b > 0)
        {
            if (b % 2 == 1) sum = sum * a % p;
            a = a * a % p;
            b = b >> 1;
        }
        sum %= p;
        printf("%lld\n", sum);
    }

}
