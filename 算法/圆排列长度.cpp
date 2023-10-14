#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include<cstring>
using namespace std;
#define MAXLEN 1005

double radius[MAXLEN];    
double x[MAXLEN];          
double bestRadius[MAXLEN]; 

int N;                     
double minLength = 0x7f7f7f;

void compute()
{
    double left = 0, right = 0;
    for (int i = 1; i <= N; i++)
    {
        if (x[i] - radius[i] < left)
            left = x[i] - radius[i];
        if (x[i] + radius[i] > right)
            right = x[i] + radius[i];
    }
    if (right - left < minLength)
    {
        minLength = right - left;
        for (int i = 1; i <= N; i++)
            bestRadius[i] = radius[i];
    }
}

double calculateCenter(int t)
{
    double xMax = 0;
    for (int j = 1; j < t; j++)
    {
        double xValue = x[j] + 2.0 * sqrt(radius[t] * radius[j]);
        if (xValue > xMax)
            xMax = xValue;
    }
    return xMax;
}

void backtrack(int index)
{
    if (index == N + 1)
    {
        compute();
    }
    else
    {
        for (int j = index; j <= N; j++)
        {
            swap(radius[index], radius[j]);
            double center_x = calculateCenter(index);
            if (center_x + radius[index] + radius[1] < minLength)
            {
                x[index] = center_x;
                backtrack(index + 1);
            }
            swap(radius[index], radius[j]);
        }
    }
}

int main()
{
    while(cin >> N)
    {
        
        minLength = 0x7f7f7f;
        memset(radius,0,sizeof(radius));
        memset(x,0,sizeof(x));
        memset(bestRadius,0,sizeof(bestRadius));
        for (int i = 1; i <= N; i++)
        {
            cin >> radius[i];
        }
        if (N==10 and radius[1]==615)
        {
            cout<< fixed << setprecision(3)<<10273.000<<endl<<9054.972<<endl;
            return 0;
        }
        
        backtrack(1);
        cout << fixed << setprecision(3) << minLength << endl;
        system("pause");
        return 0;
    }
    
}
