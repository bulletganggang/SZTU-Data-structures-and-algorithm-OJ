#include <iostream>
#include <algorithm>
using namespace std;

struct Task 
{
    int t, d;
};

bool cmp(Task a, Task b) 
{
    return a.d < b.d;
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        Task task[n];
        for (int i = 0; i < n; i++) 
        {
            cin >> task[i].t >> task[i].d;
        }

        sort(task, task + n, cmp);  // 按截止时间排序

        int finishTime = 0, maxDelay = 0;
        for (int i = 0; i < n; i++) 
        {
            finishTime += task[i].t;
            maxDelay = max(maxDelay, finishTime - task[i].d);
        }

        cout << maxDelay << endl;
    }
    system("pause");
    return 0;
}
