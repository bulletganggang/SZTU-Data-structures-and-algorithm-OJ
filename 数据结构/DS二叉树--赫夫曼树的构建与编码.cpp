#include<iostream>
#include<string>
using namespace std;
 
const int maxW= 10005;
 
class HuffNode
{
    public:
        int weight;
        int parent;
        int leftChild;
        int rightChild;
};
 
class HuffMan
{
    public:
        int len;
        int num;
        HuffNode *huffTree;
        string *huffCode;
        void select(int pos, int &s1, int &s2)
        {
            int w1, w2, i;
            w1= w2= maxW;
            s1= s2= 0;
             
            for(i= 1; i<= pos ; i++)
            {
                if(w1> huffTree[i].weight&&!huffTree[i].parent)
                {
                    w2= w1;
                    s2= s1;   
                       
                    w1= huffTree[i].weight;
                    s1= i;         
                }
                else if(w2> huffTree[i].weight&&!huffTree[i].parent)
                {
                    w2= huffTree[i].weight;
                    s2= i;
                }
            }
        }
        void create(int n, int wt[])
        {
            int i;
            num= n;
            len= 2*n- 1;
            huffTree = new HuffNode[2*n];
                
            for(i= 1; i<= n; i++)
               huffTree[i].weight= wt[i- 1];  //初始化权重
             
            for(i= 1; i<= len; i++)
            {
                if(i> n) huffTree[i].weight= 0;  //初始化空节点
                huffTree[i].parent= 0;
                huffTree[i].leftChild= 0;
                huffTree[i].rightChild= 0;
            }
            for(int i= num+ 1; i<= len; i++)
            {
                int s1, s2;
                select(i- 1,s1,s2);  //选出最小的建立新节点
                huffTree[s1].parent= huffTree[s2].parent= i;
                huffTree[i].leftChild= s1;
                huffTree[i].rightChild= s2;
                huffTree[i].weight= huffTree[s1].weight+ huffTree[s2].weight;
            }
        }
        void code()
        {
            int c, f, start;
            char *cd= new char[num];   //字符编码
            huffCode= new string[num+ 1];  
            cd[num- 1]= '\0';
            for(int i= 1; i<= num; i++)
            {
                start= num- 1;
                 
                for(c= i, f= huffTree[i].parent; f!= 0; c= f, f= huffTree[f].parent)
                   if(huffTree[f].leftChild== c)
                   {
                    cd[--start]= '0';            //左0右1
                   } 
                   else
                   {
                    cd[--start]= '1';   
                   }
                huffCode[i].assign(&cd[start]);
            }             
        }
};
 
int main()
{
    int t, n,i,j;
    int *wt;
    HuffMan hf;
    cin>>t;
    while(t--)
    {
        cin>>n;
        wt=new int[n];
        for(j= 0; j< n; j++)
           cin>>wt[j];
        hf.create(n, wt);
        hf.code();
        for(j= 1; j<= n; j++)
        {
            cout<<hf.huffTree[j].weight<<'-'<<hf.huffCode[j]<<endl;
        }
    } 
    system("pause");
    return 0;
}