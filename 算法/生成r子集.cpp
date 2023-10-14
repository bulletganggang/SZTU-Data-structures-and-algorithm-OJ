#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int n, r;
    cin >> n >> r;
    int nums[11];
    bool used[11] = {0};

    for (int i = 0; i < n; i++) 
    {
        cin >> nums[i];
    }

    for (int i = 0; i < r; i++) 
    {
        used[n - 1 - i] = 1;
    }

    do 
    {
        for (int i = n - 1, flag = 1; i >= 0; i--) 
        {
            if (used[i]) 
            {
                if (flag) 
                {
                    cout << nums[n - i - 1];
                    flag = 0;
                } 
                else 
                {
                    cout << " " << nums[n - i - 1];
                }
            }
        }
        cout << endl;
    } while (next_permutation(used, used + n));
    system("pause");
    return 0;
}
