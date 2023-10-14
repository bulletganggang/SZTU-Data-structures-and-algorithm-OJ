#include <iostream>
#include <vector>
using namespace std;
class Graph {
public:
    vector<bool> isFinished;      //索引号所指示的顶点是否已处理过
    vector<vector<int> > adjMat;  //邻接矩阵
    int n;                        //顶点数 as 成员变量
public:
    void readAdjMatrix() {
        //从输入读入邻接矩阵，存入this->adjMat
        cin >> this->n;           //顶点数
        int i=0;
        for(; i<n; ++i) {
            isFinished.push_back(0);//TODO：设置this->isFinished数组：每个顶点未曾访问过
            //提示：调用vector::push_back方法
            vector<int> row;
            int j=0;
            for(; j<n; ++j) {
                int edge;
                cin >> edge;    //读入顶点对i,j之间是否有一条边
                row.push_back(edge);//TODO：将边信息增加入row
            }
            this->adjMat.push_back(row);//TODO：将row增加入this->adjMat
            //提示：以row为参数，调用adjMat的push_back方法
        }
    }
    bool isZeroInDegrees(int vertexNo) {
    //判定顶点vertexNo是否没有入度
        int i=0;
        //this->adjMat[i][vertexNo] == 0
        //表示顶点i与vertexNo之间没有边相连
        for(; i<n && this->adjMat[i][vertexNo] == 0; ++i);
        //TODO：返回true if 顶点vertexNo没有入度; false [otherwise]
    	if(i == n )
    		return 0;
    	else
    		return 1;
	}
    int select() {
    //从所有顶点中，选出一个顶点i，满足：
    //1) i没有处理过，即isFinished[i]=false
    //2) i的入度为0
        int i = 0;
        for (; i < n; ++i) {
            if(isFinished[i])
				continue;//TODO：若顶点i的已经处理过，则pass
            if(isZeroInDegrees(i))
				continue;//TODO：若顶点度>0，则pass
            //提示：调用isZeroInDegrees
            isFinished[i] = 1;//TODO: 设置顶点i已经处理过，即isFinished[i]为正确值
            return i;//TODO: 返回i
        }
        return -1;//TODO: 返回-1, 表示未找到满足1)+2)条件的顶点
    }
    void update(int rootNo) {
    //更新顶点rootNo的出弧，即将顶点rootNo从图中断开
        int j=0;
        for(;j<n; ++j) {
            adjMat[rootNo][j] = 0;//TODO： 设置adjMat[rootNo][j]为0
        }
    }
    // 拓扑排序主算法
    void topologySort() {
        int i=0;
        for(; i<n; ++i) {  //遍历n次：即按拓扑序，依次选择（排出）n个顶点
            int root;  // 声明顶点索引号（编号）用于存放本次选出的顶点
            root = select();//TODO： 调用select方法，并将其返回值存入root
           	if(root == -1)
			   break; //TODO： 若root=-1，则break;
            // root=-1表示没有可以排出的顶点
            update(root);//TODO: 以root为参数，调用update方法
            cout<<root<<" "; //TODO：输出当前选出的顶点root 和一个空格
        }
        cout<<"\n";//TODO：输出一行
    }
    void main() {
        readAdjMatrix();
        topologySort();
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        Graph g;
        g.main();
    }
    return 0;
}
