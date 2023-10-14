#include<iostream>
using namespace std;

class date
{
private:
    int year,month,day;
public:
    date(){}
    date(int y,int m,int d)
    {
        year=y;
        month=m;
        day=d;
    }
    int gety()
    {
        return year;
    }
    int getm()
    {
        return month;
    }
    int getd()
    {
        return day;
    }
    void set(int y,int m,int d)
    {
        year=y;
        month=m;
        day=d;
    }
    void print()
    {
        cout<<year<<"/";
        if (month<10)
        {
            cout<<"0"<<month<<"/";
        }
        else cout<<month<<"/";
        if (day<10)
        {
            cout<<"0"<<day<<endl;
        }
        else cout<<day<<endl;
    }
    bool isLeap(int year) { return year % 100 == 0 ? year % 400 == 0 : year % 4 == 0; }
	void addOneDay()
	{
		int monthDays[] = {0, 31, isLeap(year) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		day++;
		if (day > monthDays[month])
		{
			month++;
			day = 1;
		}
		if (month > 12)
		{
			year++;
			month = 1;
		}
	}
};
int main()
{
    int t;
    cin>>t;
    int x=0;
    while (t--)
    {
        x++;
        int y,m,d;
        cin>>y>>m>>d;
        if (x%2==0)
        {
            date n;
            n.set(y,m,d);
            cout<<"Today is ";
            n.print();
            n.addOneDay();
            cout<<"Tomorrow is ";
            n.print();
        }
        else
        {
            date n(y,m,d);
            cout<<"Today is ";
            n.print();
            n.addOneDay();
            cout<<"Tomorrow is ";
            n.print();
        }
    }
    system("pause");
}