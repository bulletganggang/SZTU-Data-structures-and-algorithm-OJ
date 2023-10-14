#include <iostream>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;

struct customer 
{
    int come,use;
};

struct window 
{
	bool isbusy;
	int finish;
};

int main() 
{
	int n, come, use,k;
	int allwait = 0, wait = 0, finish = 0, maxwait = 0;

	queue<customer> cus;
	cin>>n; //顾客人数
	int n1 = n;
	while(n1--) 
    { 
        customer temp;
		cin>>temp.come>>temp.use;
		cus.push(temp);
	}
	cin>>k; //窗口个数
	window *win = new window[k]; 

	int clock = 0; 
	while(!cus.empty()) 
    {
		if(clock >= cus.front().come) //顾客到达窗口
        {  
			for(int i = 0; i < k; i++) 
            {
				if(win[i].finish <= clock) //重置每个窗口的空闲状态
                {  
					win[i].isbusy = 0;
				}
			}
			for(int i = 0; i < k; i++) //判断每一个窗口是否空闲
            { 	
				if(!win[i].isbusy && (!cus.empty()) && (clock >= cus.front().come)) 
                {
					win[i].isbusy = 1;
					win[i].finish = clock + cus.front().use;
					wait = clock - cus.front().come;
					allwait += wait;
					if(wait > maxwait) 
                    {
						maxwait = wait;
					}
					if(win[i].finish > finish) 
                    {
						finish = win[i].finish;
					}
					cus.pop();
				}
			}
		}
		clock++;
	}
	cout<< fixed << setprecision(1) <<(double) allwait/ n <<" "<<maxwait<<" "<<finish << endl;
	delete []win;
	return 0;
}
