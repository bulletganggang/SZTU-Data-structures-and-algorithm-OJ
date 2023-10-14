#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
const int mod = 1e9 + 7;

struct Node
{
    long long mat[2][2];
    Node() {}
    Node(int a_, int b_, int c_, int d_)
    {
        mat[0][0] = a_;
        mat[0][1] = b_;
        mat[1][0] = c_;
        mat[1][1] = d_;
    }
    Node operator*(const Node& y)
    {
        // TODO: 矩阵乘法，注意取模
        Node tem(0, 0, 0, 0);
        for (int k = 0; k < 2; k++)
            for (int i = 0; i < 2; i++)
                for (int j = 0; j < 2; j++)
                    tem.mat[i][j] = (tem.mat[i][j] + mat[i][k] * y.mat[k][j] % mod) % mod;
        return tem;
    }
};

Node Pow(Node a, int n)
{
    // TODO: 矩阵的快速幂
    Node b(1, 0, 0, 1);
    while (n)
    {
        if (n % 2 == 1) b = b * a;
        a = a * a;
        n /= 2;
    }
    return b;
}

int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        Node x(1, 1, 1, 0);
        // TODO: 初始化用于推导斐波那契数列的矩阵
        Node ans = Pow(x, n);
        // TODO: 输出矩阵中对应的斐波那契第n项
        printf("%d\n", ans.mat[1][0]);
    }
    return 0;
}
