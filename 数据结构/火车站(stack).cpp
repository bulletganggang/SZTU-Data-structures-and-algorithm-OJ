#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
	int t;
    cin>>t;
	while (t--)
	{
		int p1, p2;
        int len;
        cin>>len;
		stack<char> s;
		string se, o1, o2;
		cin >> o1 >> o2;
		p1 = p2 = 0;
		while (p2<o2.length())
		{
			if (s.empty() || s.top()!=o2[p2])
			{
				int f = 0;
				while (p1<o1.length())
				{
					s.push(o1[p1++]);
					se.append("I");
					if (s.top()==o2[p2])
					{
						f = 1;
						break;
					}
				}
				if (f)
                {
                    se.append("O");
                    s.pop();
                } 
				else if (p1==o1.length())
                {
                    se.append("N");
                }
			}
			else 
            {
                s.pop();
                se.append("O");
            }
			p2++;
		}
		if (se.find("N")!=-1)
        {
            cout << "No" << endl;
        } 
		else
		{
			cout << "Yes" << endl;
			for (int i=0; i<se.length(); i++)
            {
                if (se[i]=='I')
                {
                    cout << "in" << endl;
                } 
				else if (se[i]=='O')
                {
                    cout << "out" << endl;
                } 
            }
		}
		cout << "FINISH" << endl;
	}
    system("pause");
	return 0;
}
