#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point {
    int x;
    int y;
    int steps;
};

int getMinSteps(int x1, int y1, int x2, int y2) {
    vector<vector<int>> moves = {{-1, -2}, {-2, -1}, {-2, 1}, {-1, 2},
                                 {1, -2}, {2, -1}, {2, 1}, {1, 2}};
    
    vector<vector<bool>> visited(8, vector<bool>(8, false));
    queue<Point> q;
    q.push({x1 - 1, y1 - 1, 0});  // 将坐标从 1-based 转换为 0-based
    
    while (!q.empty()) {
        Point current = q.front();
        q.pop();
        
        if (current.x == x2 - 1 && current.y == y2 - 1) {
            return current.steps;
        }
        
        for (vector<int> move : moves) {
            int newX = current.x + move[0];
            int newY = current.y + move[1];
            
            if (newX >= 0 && newX < 8 && newY >= 0 && newY < 8 && !visited[newX][newY]) {
                visited[newX][newY] = true;
                q.push({newX, newY, current.steps + 1});
            }
        }
    }
    
    return -1;  // 如果无法到达终点，返回-1
}

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    int minSteps = getMinSteps(x1, y1, x2, y2);
    
    cout << minSteps << endl;
    system("pause");
    return 0;
}
