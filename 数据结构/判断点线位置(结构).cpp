#include<iostream>
#include<cmath>
using namespace std;

struct point
{
    int x,y;
};

struct line
{
    point p1,p2;
};

int dir(const line &ab, const point &c)
{
    point a,b;
    a.x=fabs(ab.p2.x-ab.p1.x);
    a.y=fabs(ab.p2.y-ab.p1.y);
    b.x=fabs(ab.p1.x-c.x);
    b.y=fabs(ab.p1.y-c.y);
    return a.x*b.y-a.y*b.x;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        line l;
        point p;
        cin>>l.p1.x>>l.p1.y>>l.p2.x>>l.p2.y;
        cin>>p.x>>p.y;
        if (dir(l,p)>0)  //顺时针
        {
            cout<<"clockwise"<<endl;
        }
        else if (dir(l,p)<0)
        {
            cout<<"anti clockwise"<<endl;
        }
        else cout<<"intersect"<<endl;
    }
    system("pause");
}