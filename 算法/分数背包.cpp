#include <iostream>
#include <algorithm>
using namespace std;

struct item 
{
    int price, weight;
};

bool cmp(item a, item b) 
{
    return a.price< b.price;
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n, m;
        cin >> n >> m;
        item items[m];
        for (int i = 0; i < m; i++) 
        {
            cin >> items[i].price >> items[i].weight;
        }
        sort(items, items + m, cmp); // 按单位重量价值升序排列
        int i = 0;
        double total = 0;
        while (n > 0 && i < m) 
        {
            if (n - items[i].weight *items[i].price>=0) 
            {
                total += items[i].weight;
                n -= items[i].weight *items[i].price;
                i++;
            } 
            else 
            {
                total += n * 1.00/items[i].price;
                break;
            }
        }
        printf("%.2lf\n", total);
    }
    system("pause");
    return 0;
}
