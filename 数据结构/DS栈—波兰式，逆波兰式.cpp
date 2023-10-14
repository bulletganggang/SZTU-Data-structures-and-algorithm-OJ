#include<iostream>
#include<stack>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string n;
        cin>>n;
        int len=n.length();
        map<char,int> m={{'+',2},{'-',2},{'*',3},{'/',3},{'(',4},{')',4}};
        
        //qian
        stack<char> op1,temp1;
        for (int i = n.length()-1; i >= 0; i--)
        {
            if (n[i]>='0' and n[i]<= '9')
            {
                temp1.push(n[i]);
            }
            else if (n[i]=='+' or n[i]=='-' or n[i]=='*' or n[i]=='/')
            {
                while (1)
                {
                if (op1.empty() or op1.top()==')')
                {
                    op1.push(n[i]);
                    break;
                }
                else if (m[n[i]]>=m[op1.top()])
                {
                    op1.push(n[i]);
                    break;
                }
                else
                {
                    temp1.push(op1.top());
                    op1.pop();
                } 
                }
            }
            else if (n[i]==')')
            {
                op1.push(n[i]);
            }
            else if (n[i]=='(')
            {
                while (op1.top()!=')')
                {
                    temp1.push(op1.top());
                    op1.pop();
                }
                op1.pop();
                continue;
            }
        }
        while (!op1.empty())
        {
            temp1.push(op1.top());
            op1.pop();
        }
        vector<char> v1;
        while (!temp1.empty())
        {
        v1.push_back(temp1.top());
        temp1.pop();
        }
        for (int i = 0; i < v1.size(); i++)
        {
            cout<<v1[i]<<" ";
        }
        cout<<endl;

        //hou
        stack<char> op,temp;
        for (int i = 0; i < len; i++)
        {
            if (n[i]>='0' and n[i]<= '9')
            {
                char tt;
                temp.push(n[i]);
            }
            else if (n[i]=='+' or n[i]=='-' or n[i]=='*' or n[i]=='/')
            {
                while (1)
                {
                if (op.empty() or op.top()=='(')
                {
                    op.push(n[i]);
                    break;
                }
                else if (m[n[i]]>m[op.top()])
                {
                    op.push(n[i]);
                    break;
                }
                else
                {
                    temp.push(op.top());
                    op.pop();
                } 
                }
            }
            else if (n[i]=='(')
            {
                op.push(n[i]);
            }
            else if (n[i]==')')
            {
                while (op.top()!='(')
                {
                    temp.push(op.top());
                    op.pop();
                }
                op.pop();
                continue;
            }
        }
        while (!op.empty())
        {
            temp.push(op.top());
            op.pop();
        }
        vector<char> v;
        while (!temp.empty())
        {
        v.push_back(temp.top());
        temp.pop();
        }
        reverse(v.begin(),v.end());
        for (int i = 0; i < v.size(); i++)
        {
            cout<<v[i]<<" ";
        }
        cout<<endl;
        
        cout<<endl;
    }
    system("pause");
}