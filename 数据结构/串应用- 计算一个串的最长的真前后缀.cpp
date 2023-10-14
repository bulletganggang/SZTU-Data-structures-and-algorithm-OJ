#include<iostream>
#include<vector>
#include<string>
using namespace std;

string match(string s)
{
    int len=s.length();
    if (len==1)
    {
        cout<<"empty"<<endl;
        return "-1";
    }

    vector<string> qian,hou;
    //qian
    for (int i = 0; i < len-1; i++)
    {
        string t;
        for (int j = 0; j < i+1; j++)
        {
            t.push_back(s[j]);
        }
        qian.push_back(t);
    }
    
    //hou
    for (int i = len-1; i > 0; i--)
    {
        string t;
        for (int j = i; j < len; j++)
        {
            t.push_back(s[j]);
        }
        hou.push_back(t);
    }

    int max=-1,index=-1;
    for (int i = 0; i < len-1; i++)
    {
        if (qian[i]==hou[i])
        {
            index=i;
            max=qian[i].length();
        }
    }
    
    if (index!=-1)
    {
        cout<<qian[index]<<endl;
    }
    else 
    {
        cout<<"empty"<<endl;
        return "-1";
    }
    return "ok";
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        string s;
        cin>>s;
        match(s);
    }
    system("pause");
}