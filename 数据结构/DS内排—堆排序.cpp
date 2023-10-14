#include <iostream>
using namespace std;

void heapify(int *nums,int loc,int n) 
{
    int left = 2*loc+1;
    int right = 2*loc+2;
    if(left < n)
    {
        if(right <n)
        {
            if(nums[left] > nums[right])
            {
                if(nums[right] < nums[loc]) 
                {
                    swap(nums[right],nums[loc]);
                    heapify(nums,right,n);
                }
            }
            else
            {
                if(nums[left] < nums[loc])  
                {
                    swap(nums[left],nums[loc]);
                    heapify(nums,left,n);
                }
            }
        }
        else
        {
            if(nums[left] < nums[loc])  
            {
                swap(nums[left],nums[loc]);
                heapify(nums,left,n);
            }
        }
    }
}

void heapsort(int n)
{
    int *nums;
    nums = new int[n];
    for(int i = 0; i < n; i++)
        cin>>nums[i];
    for(int i = n/2; i >= 0; i--)   
    {
        heapify(nums,i,n);
    }
    cout<<n<<' ';
    for(int i = 0; i < n; i++)  
    {
        cout<<nums[i];
        if(i != n-1) cout<<' ';
    }
    cout<<endl;
    for(int t = n-1; t >= 1; t--)
    {
        swap(nums[0],nums[t]);    
        heapify(nums,0,t);        
        cout<<n<<' ';
        for(int i = 0; i < n; i++)  
        {
            cout<<nums[i];
            if(i != n-1) cout<<' ';
        }
        cout<<endl;
    }
}

int main()
{
	int t;
	cin>>t;
    heapsort(t);
}