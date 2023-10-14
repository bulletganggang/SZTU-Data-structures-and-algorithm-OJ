#include <iostream>
#include <vector>
using namespace std;

int totalWays;

bool isValid(vector<int>& queens, int row, int col) 
{
    for (int i = 0; i < row; i++) 
    {
        if (queens[i] == col || queens[i] - col == i - row || queens[i] - col == row - i) 
        {
            return false;
        }
    }
    return true;
}

void backtrack(vector<int>& queens, int row, int n) 
{
    if (row == n) 
    {
        totalWays++;
        return;
    }

    for (int col = 0; col < n; col++) 
    {
        if (isValid(queens, row, col)) 
        {
            queens[row] = col;
            backtrack(queens, row + 1, n);
            queens[row] = -1;
        }
    }
}

int main() 
{
    int n;
    while (cin >> n) 
    {
        totalWays = 0;
        vector<int> queens(n, -1);
        backtrack(queens, 0, n);
        cout << totalWays << endl;
    }
    system("pause");
    return 0;
}