#include <iostream>
#include <string>
#include <vector>
using namespace std;

//定义无穷大距离
#define MAX_DIS 0x7FFFFF

class Vertex {
	public:
		int indexNo;   //顶点索引号：顶点位于顶点数组的下标取值[0,n)
		string label;  //顶点的标签
		int distance;  //顶点到源点的距离
		bool isVisited; //顶点是否已经按Dijkstra算法处理过（不用再处理了）
		vector<int> path; //顶点到源点的路径

		Vertex(int indexNo, const string& label="", int distance=MAX_DIS) {
			this->label = label;
			this->distance = distance;

			this->indexNo = indexNo;
			this->isVisited = false;
		}
		void updatePath(const vector<int>& prePath) {
			this->path = prePath;   //复制源结点到前一个结点的路径
			this->path.push_back(this->indexNo);     //TODO: 增加本结点到路径数组this->path中
		}

		//打印输出本结点信息
		//输入：顶点数组（供查询用）、源结点索引号（顶点数组下标）
		void displayPath(vector<Vertex>& vertexes, int sourceNo) {

			//0-1-5----[0 1 ]
			cout << vertexes[sourceNo].label; //0
			cout << "-";
			cout << this->label; //1

			cout << "-";
			if (this->distance >= MAX_DIS) {
				cout << "-1\n";                        //TODO: 如果源结点到本结点距离无穷大，则（按题目要求）输出-1
				return;
			}
			cout << this->distance; //5
			cout << "----";

			cout << "[";
			int i=0;
			int size = this->path.size();
			for(; i<size; ++i) {
				cout << vertexes[path[i]].label <<" ";                    //TODO: 如果源结点到本结点距离<无穷大，则（按题目要求）输出标签和空格
			}
			cout << "]";
			cout << endl;
		}
};

//打印顶点信息，供调试用
ostream& operator<<(ostream& out, const Vertex& v) {
	out << v.indexNo << "_" << v.label << ": " << v.distance << " ";
	return out;
}

class Graph {
	public:
		vector<Vertex> vertexes; //顶点数组：存放顶点信息
		vector<vector<int> > adjMat;  //邻接矩阵：存放每对结点距离，若1对结点i,j之间无边相连，则adjMat[i,j]=0
	public:

		void printVertexes() {  //用于调试
			int i=0;
			int n = vertexes.size();
			for(; i<n; ++i) {
				cout << vertexes[i];
			}
			cout << endl;
		}

		int getNo(string& label) {
			//TODO： 遍历顶点数组vertexes，找到标签属性=label的顶点索引号
			//并返回。
			int i=0;
			int n = vertexes.size();
			for(; i < n; i++) {
				if(vertexes[i].label == label) {
					return vertexes[i].indexNo;
				}
			}
            return -1;
		}
		void readVertexes() {
			//读入每个顶点信息
			int n;
			cin >> n; // n个结点

			int indexNo=0;
			for(; indexNo<n; ++indexNo) {
				string label;
				cin>>label;   //TODO： 读入标签到label变量

				//Vertex(int indexNo, const string& label="", int distance=MAX_DIS)
				//TODO： 创建顶点对象v
				Vertex v(indexNo,label);
				this->vertexes.push_back(v);  //把v加入顶点数组
			}

		}
		void readAdjMat() {
			//读取距离矩阵，并存放成员变量adjMat
			int n = this->vertexes.size();

			int i=0;
			for(; i<n; ++i) {
				vector<int> row;  //创建矩阵的一行对象row
				int j=0;
				for(; j<n; ++j) {
					int dis;
					cin>>dis;//TODO: 读取输入的顶点i,j之间的距离，存入变量dis
					row.push_back(dis);//TODO: 将dis插入row
				}
				adjMat.push_back(row);//TODO: 将矩阵的一行row附加到邻接矩阵adjMat中
			}
		}

		void update(int rootNo) {
			//将顶点rootNo选入visited集合之后，
			//更新与rootNo关联的所有结点（未访问）：到源点的距离、路径信息
			int i=0;
			int n = vertexes.size();

			Vertex& root = vertexes[rootNo];   //获取rootNo对应顶点对象，便于下面代码写作
			int rootDis = root.distance;

			for(; i < n; ++i) {
				Vertex& v = vertexes[i]; //获取当前顶点对象，便于下面代码写作

				if (v.isVisited)
					continue;//TODO:  如果v已经访问过，则pass

				// TODO: 如果rootNo到i 之间没有边，则pass
				if(adjMat[rootNo][i] == 0)
					continue;

				//计算顶点i：到源点的新距离
				int newDis = rootDis + this->adjMat[rootNo][i];
				if (newDis < v.distance) {
					v.distance = newDis;  //更新顶点i的距离信息
					v.updatePath(vertexes[rootNo].path);	//TODO: 更新顶点i的路径信息， 提示：调用v对象的一个方法
				}
			}
		}

		int select() {
			//从未曾访问的顶点集合中，选择距离源点最短的顶点（其索引号为minNo）
			//返回 minNo
			int minDis = MAX_DIS;
			int minNo = -1;

			int i=0;
			int n = vertexes.size();
			for(; i<n; ++i) {
				Vertex& v = vertexes[i];

				if(v.isVisited)//TODO：如果顶点i已经访问过，则pass
					continue;
				if (v.distance < minDis) {
					//TODO：记录顶点i的距离和编号到minDis、minNo中
					minDis = v.distance;
					minNo = v.indexNo;
				}
			}

			if(minNo == -1)//TODO：检查minNo是否为-1,
				return -1;//若是，则返回-1

			//获得有效的顶点编号
			vertexes[minNo].isVisited = true;
			return minNo;
		}

		void readSourceNo() {
			//从输入读取源结点标签，执行Dijikstra算法

			
			//1）读取源点
			string slabel;
			cin >> slabel;

			int sourceNo;  //源结点索引
			sourceNo = getNo(slabel);//TODO： 调用一个Graph的成员函数返回标签=slabel的顶点索引号
			//并将编号存入sourceNo

			
			//2） 初始化源点
			Vertex& source = vertexes[sourceNo];  //获取源点对象source，便于下面代码写作
			source.isVisited = 1;//TODO：设置source的isVisited为true
			source.distance = 0;//TODO：设置source到源点的距离为0
			source.path.push_back(sourceNo);//TODO: 设置source到源点的路径为[sourceNo]

			update(sourceNo);//TODO: 以sourceNo为参数调用update成员函数

			//
			//3）Dikstra主算法
			int i=0;
			int n = vertexes.size();
			for(; i<(n-1); ++i) {

				int v;  //当前未访问过的顶点集合中，距离源点的距离最短的顶点索引号为v

				v = select();//TODO：调用select方法，并将返回值存入v

				if(v == -1)
					break;//TODO: v=-1，则退出for循环

				update(v);//TODO:将v作为参数，调用update方法
			}

			
			// 4）打印除源点外的其它顶点信息（按顶点索引号顺序打印）
			string sourceLabel = source.label;
			for(i=0; i<n; ++i) {
				if(i == sourceNo) continue;//TODO：如果i=sourceNo，则pass

				Vertex& v = vertexes[i];  //获取当前顶点对象v，便于下述代码写作
				v.displayPath(vertexes,sourceNo);//TODO：调用v的一个方法，打印输出源点到顶点v的距离、路径
			}
		}

		void main() {
			readVertexes();  //读取顶点数组
			readAdjMat();    //读取距离矩阵
			readSourceNo();  //读取源点、并执行Dijkstra算法
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
