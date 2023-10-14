#include<iostream>
using namespace std;

struct point
{
    int x,y;
};

struct rec
{
    point p1,p2;
};


bool over(const rec &rect1, const rec &rect2)
{
	if(rect1.p1.x>rect2.p2.x||rect1.p1.y>rect2.p2.y||rect1.p2.x<rect2.p1.x||rect1.p2.y<rect2.p1.y)return 0;
	return 1;
}

void standard(rec &r)
{
	if(r.p1.x>r.p2.x)
	swap(r.p1.x,r.p2.x);
	if(r.p1.y>r.p2.y)
	swap(r.p1.y,r.p2.y);
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        rec r1,r2;
        cin>>r1.p1.x>>r1.p1.y>>r1.p2.x>>r1.p2.y;
        cin>>r2.p1.x>>r2.p1.y>>r2.p2.x>>r2.p2.y;
        standard(r1);
        standard(r2);
        if (over(r1,r2))
        {
            cout<<"overlapped"<<endl;
        }
        else cout<<"not overlapped"<<endl;
    }
    
}