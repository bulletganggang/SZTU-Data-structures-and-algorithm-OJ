#include<iostream>
#include<stack>
#include<string>
#include<cstdlib>
#include<cstring>
#include<iomanip>
using namespace std;

char prior[7][7]={
	'>','>','<','<','<','>','>',
	'>','>','<','<','<','>','>',
	'>','>','>','>','<','>','>',
	'>','>','>','>','<','>','>',
	'<','<','<','<','<','=',' ',
	'>','>','>','>',' ','>','>',
	'<','<','<','<','<',' ','='
};

float operate(float a,unsigned char theta,float b)
{
    if (theta=='+')
    {
        return a+b;
    }
    if (theta=='-')
    {
        return a-b;
    }
    if (theta=='*')
    {
        return a*b;
    }
    if (theta=='/')
    {
        return a/b;
    }
    return 0;
}

char opset[7]={'+','-','*','/','(',')','#'};

int in(char test,char *testop)  //判断是否为运算符
{
	for(int i=0;i<7;i++)
    {
        if(test==testop[i])
        {
            return 1;
        }
    }
	return 0;
}

char precede(char a,char b)
{
	int i,j;
	for(i=0;i<7;i++)
    {
        if(opset[i]==a)break;
    }
	for(j=0;j<7;j++)
    {
        if(opset[j]==b)break;
    }
	return prior[i][j];
}

float evaluate(string exp)
{
	stack<char> optr;
	stack<double> opnd;
	char tempdata[20];
	double data,a,b,r;
	char theta,dr[2];
	char c;
	int i=0;
	optr.push('#');
	c=exp[0];
	strcpy(tempdata,"\0");
	while(c!='#'||optr.top()!='#')
	{
		if(!in(c,opset))
		{
			dr[0]=c;
			dr[1]='\0';
			strcat(tempdata,dr);
			c=exp[++i];
			if(in(c,opset))
			{
				data=(float)atof(tempdata);
				opnd.push(data);
				strcpy(tempdata,"\0");
			}
		}
		else
		{
			switch(precede(optr.top(),c))
			{
				case'<':optr.push(c); 
						c=exp[++i];
						break;
				case'=':optr.pop();
						c=exp[++i];
						break;
				case'>':
						theta=optr.top();
                        optr.pop(); 
				        b=opnd.top();
                        opnd.pop();
				        a=opnd.top();
                        opnd.pop();
				        opnd.push(operate(a,theta,b));
						break;
			} 			
		}
	}
	return opnd.top();
}

int main()
{
	string exp;
	int t;
	double result;
	cin>>t;
	while(t--)
	{
		cin>>exp;
		result=evaluate(exp);
		cout<<fixed<<setprecision(4)<<result<<endl;
	}
	return 0;
}