#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 10010
#define INF 0x7f7f7f7f
using namespace std;

double matrix[N][M]; // 线性规划模型的系数矩阵
int n, m;

// 检查是否有需要进入基变量集的列
int findEnteringColumn()
{
    for (int i = 1; i <= m; i++)
        if (matrix[0][i] > 0)
            return i;
    return 0;
}

// 使用单纯形算法求解最优解
void simplex()
{
    while (int col = findEnteringColumn())
    {
        double limit = INF;
        int choseline;

        // 找到离基变量集最紧的行
        for (int i = 1; i <= n; i++)
        {
            if (matrix[i][col] <= 0)
                continue;
            if (matrix[i][0] / matrix[i][col] < limit)
            {
                limit = matrix[i][0] / matrix[i][col];
                choseline = i;
            }
        }

        // 如果 limit 为 INF，则问题无界
        if (limit == INF)
        {
            matrix[0][0] = INF;
            break;
        }

        double di = matrix[choseline][col];

        // 主元归一化，更新其他元素
        for (int i = 0; i <= m; i++)
        {
            if (i == col)
                matrix[choseline][i] /= di;
            matrix[choseline][i] /= di;
        }

        for (int i = 0; i <= n; i++)
        {
            if (i == choseline || matrix[i][col] == 0)
                continue;
            if (i == 0)
                matrix[i][0] += matrix[i][col] * matrix[choseline][0];
            else
                matrix[i][0] -= matrix[i][col] * matrix[choseline][0];

            double l = matrix[i][col];
            for (int j = 1; j <= m; j++)
            {
                if (j == col)
                    matrix[i][j] = -l * matrix[choseline][j];
                else
                    matrix[i][j] -= l * matrix[choseline][j];
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    // 输入目标函数的系数和约束条件
    for (int i = 1; i <= n; i++)
        scanf("%lf", &matrix[i][0]);

    for (int i = 1; i <= m; i++)
    {
        int l, r;
        scanf("%d%d%lf", &l, &r, &matrix[0][i]);
        for (int j = l; j <= r; j++)
            matrix[j][i] = 1;
    }

    simplex();

    printf("%.0lf\n", matrix[0][0]);
    system("pause");
    return 0;
}
