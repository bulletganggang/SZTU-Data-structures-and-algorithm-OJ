#include<iostream>
#include<stack>
using namespace std;

struct xy
{
    int x,y;
};

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        int **maze=new int *[n];
        for (int i = 0; i < n; i++)
        {
            maze[i]=new int[n];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
        {
            cin>>maze[i][j];
        }
        }
        if (maze[0][0]==1)
        {
            cout<<"no path"<<endl;
            continue;
        }
        stack<xy> path;
        path.push({0,0});
        maze[0][0]=1;
        int x=0,y=0;
        while (1)
        {
            if (y+1<n and maze[x][y+1]==0)  //you
            {
                maze[x][y+1]=1;
                path.push({x,++y});
            }
            else if (x+1<n and maze[x+1][y]==0)  //xia
            {
                maze[x+1][y]=1;
                path.push({++x,y});
            }
            else if (y-1>=0 and maze[x][y-1]==0)  //zuo
            {
                maze[x][y-1]=1;
                path.push({x,--y});
            }
            else if (x-1>=0 and maze[x-1][y]==0)  //shang
            {
                maze[x-1][y]=1;
                path.push({--x,y});
            }
            else
            {
                x=path.top().x;
                y=path.top().y;
                if(!((y+1<n and maze[x][y+1]==0)||(x+1<n and maze[x+1][y]==0)||(y-1>=0 and maze[x][y-1]==0)||(x-1>=0 and maze[x-1][y]==0)))
                {
                    path.pop();
                }
            }
            if (path.empty() or (x==n-1 and y==n-1))
            {
                break;
            }
        }
        if (path.empty())
        {
            cout<<"no path"<<endl;
        }
        else if (x==n-1 and y==n-1)
        {
            int k=0;
            stack<xy> path1;
            while (!path.empty())
            {
                xy m;
                m=path.top();
                path1.push(m);
                path.pop();
            }
            while (!path1.empty())
            {
                cout<<"["<<path1.top().x<<","<<path1.top().y<<"]--";
                if (++k%4==0)
                {
                    cout<<endl;
                }
                path1.pop();
            }
            cout<<"END\n";
        }
    }
    system("pause");
}