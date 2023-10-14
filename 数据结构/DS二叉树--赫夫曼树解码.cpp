#include<iostream>
#include<string>
using namespace std;
#define ok 1
#define error -1

const int MaxW = 10005;

class HuffNode 
{
	public:
		int weight;
		int parent;
		int left;
		int right;
		char cha;
};

class HuffMan 
{
	public:
		int len;
		int num;
		HuffNode *huffTree;
		string* huffCode;
        void select(int pos, int &s1, int &s2)
        {
	    int w1, w2, i;
	    w1 = w2 = MaxW;
	    s1 = 0;
	    s2 = 0;
	    for(i = 1; i <= pos; i++) 
        {
		if(huffTree[i].weight < w1 && huffTree[i].parent == 0) 
        {
			w2 = w1;
			s2 = s1;

			w1 = huffTree[i].weight;
			s1 = i;
		} 
        else if(huffTree[i].weight < w2 && huffTree[i].parent == 0) 
        {
			w2 = huffTree[i].weight;
			s2 = i;
		}
		}
}
		void create(int n, int wt[], char ct[])
        {
	int i;
	num = n;
	len = 2*n - 1;
	huffTree = new HuffNode[2*n];
	huffCode = new string[num+1];
	for(i = 1; i <= n; i++)   
    {
		huffTree[i].weight = wt[i - 1];
		huffTree[i].cha = ct[i - 1];
	}
	for(i = 1; i <= len; i++) 
    {
		if(i > n) 
        {
			huffTree[i].cha = '0';
			huffTree[i].weight = 0;
		}
		huffTree[i].parent = 0;
		huffTree[i].left = 0;
		huffTree[i].right = 0;
	}
    int s1, s2;
	for(i = num + 1; i <= len; i++) 
    {
		select(i - 1, s1, s2);
		huffTree[s1].parent = huffTree[s2].parent = i;
		huffTree[i].right = s2;
		huffTree[i].left = s1;
		huffTree[i].weight = huffTree[s1].weight + huffTree[s2].weight;
	}

}
		void code()
        {
            char *cd;
	int i, c, f, start;
	cd = new char[num];
	cd[num - 1] = '\0';
	for(i = 1; i <= num; i++) 
    {
		start = num - 1;
		for(int c = i, f = huffTree[i].parent; f != 0; c = f, f = huffTree[f].parent) 
        {
			if(huffTree[f].left == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}

		huffCode[i] = new char[num-start];
		huffCode[i].assign(&cd[start]);
	}
    }
		int  decode(const string str1, char str2[])
        {
	int i, k= 0, c= len;
	char ch;
	for(i = 0; i <str1.length(); i++)
    {
		ch = str1[i];
		if(ch == '0')
        {
			c  = huffTree[c].left;
		}
        else if(ch == '1')
        {
			c = huffTree[c].right;
		} 
        else
        {
			return error;
		}
		if(huffTree[c].left == 0 && huffTree[c].right == 0)
        {
			str2[k++] = huffTree[c].cha;
			c = len;
		}
        else
        {
			ch = '\0';
		}	
	}
	if(ch == '\0') return error;
	else str2[k] = '\0';
	return ok;
}
};

int main() 
{
	int t, n, i, j,m;
	int wt[800];
	char ct[800];
	HuffMan myHuff;
	cin>>t;
	for(i = 0; i < t; i++) 
    {
		cin>>n;
		string str1;
		char str2[800];
		for(j = 0; j < n; j++) 
        {
			cin >> wt[j];
		}
		for(j = 0; j < n; j++) 
        {
			cin >> ct[j];
		}
		myHuff.create(n,wt,ct);
		myHuff.code();
		cin>>m;
		while(m--)
        {
			cin>>str1;
			if(myHuff.decode(str1,str2) == 1)
            {
				cout<<str2<<endl;
			}
            else
            {
				cout<<"error"<<endl;
			}		
		}
	}
    system("pause");
	return 0;
}
