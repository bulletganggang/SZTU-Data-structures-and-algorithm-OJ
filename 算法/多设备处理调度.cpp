#include <iostream>
#include<cstring>
#include<algorithm>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

struct Device 
{
    long long start, end;
    Device() { start = 0; end = 0; };
};

bool cmpByStart(Device &a, Device &b) 
{
    return a.start < b.start;
}

bool cmpByEnd(Device &a, Device &b) 
{
    return a.end > b.end;
}

Device devices[10005];
Device missions[10005];

int main() 
{
    int t;
    cin >> t;
    while(t--) 
	{
		int n;
        cin >> n;
        int numDevices = 0;
        long long totalTime = 0;

        for(int i = 0; i < n; i++) 
		{
            cin >> missions[i].start >> missions[i].end;
        }

        sort(missions, missions + n, cmpByStart);

        for(int i = 0; i < n; i++) 
		{
            for(int j = 0; j < numDevices + 1; j++) 
			{
                if(j == numDevices || devices[j].end <= missions[i].start) 
				{
                    if(j == numDevices) 
					{
                        devices[j].start = missions[i].start;
                        numDevices++;
                    }

                    devices[j].end = missions[i].end;

                    break;
                }
            }
            sort(devices, devices + numDevices, cmpByEnd);
        }

        for(int i = 0; i < numDevices; i++) 
		{
            totalTime += devices[i].end - devices[i].start;
        }

        cout << numDevices << " " << totalTime << endl;
    }
	system("pause");
    return 0;
}
