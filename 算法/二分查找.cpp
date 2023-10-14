#include <stdio.h>
#include <stdlib.h>
#define MAXN 10000005
int a[MAXN];

int main() 
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < m; i++) 
    {
        int x;
        scanf("%d", &x);
        int l = 0, r = n - 1;
        while (l < r) 
        { 
            int mid = (l + r) / 2;
            if (a[mid] < x) 
            {
                l = mid + 1;
            } 
            else 
            {
                r = mid;
            }
        }
        printf("%d\n", l + 1);
    }
    return 0;
}
