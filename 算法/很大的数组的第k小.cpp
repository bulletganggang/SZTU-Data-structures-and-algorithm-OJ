#include <stdio.h>
#include <stdlib.h>
#include<iostream>

#define MAXX 50000000
#define MOD 1000000007

int n, m, k;
int a[MAXX];

void swap(int *a, int *b) 
{
    int t = *a;
    *a = *b;
    *b = t;
}

int qsort(int arr[], int low, int high) 
{
    int maxx = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++) 
    {
        if (arr[j] < maxx) 
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return i+1;
}

int qs(int arr[], int low, int high, int k) 
{
    if(low == high) return arr[low];

    int pi = qsort(arr, low, high);
    int len = pi - low + 1;

    if (k == len) 
    {
        return arr[pi];
    } 
    else if (k < len) 
    {
        return qs(arr, low, pi-1, k);
    } 
    else 
    {
        return qs(arr, pi+1, high, k-len);
    }
}

int main() 
{
    scanf("%d %d %d", &n, &m, &k);

    a[0] = m % MOD;
    for (int i = 1; i < n; i++) 
    {
        a[i] = (long long) a[i-1] * m % MOD;
    }

    int num = qs(a, 0, n-1, k);

    printf("%d\n", num);
    system("pause");
    return 0;
}
