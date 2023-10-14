#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define LH 1 // 左高 
#define EH 0 // 等高 
#define RH -1 // 右高 

class BiNode
{
    public:
        int key; // 关键值
        int bf; // 平衡因子 
        BiNode *lchild, *rchild;
        BiNode(int kValue, int bValue)
       {

           key = kValue;
           bf = bValue;
           lchild = NULL;
           rchild = NULL;
       }
       ~BiNode()
      {
           key = 0;
           bf = 0;
           lchild = NULL;
           rchild = NULL;
       }
};

// 二叉排序树
class BST
{
     private:
         BiNode *root; // 根结点指针 
         void rRotate(BiNode *&p);
         void lRotate(BiNode *&p);
         void leftBalance(BiNode *&t);
         void rightBalance(BiNode *&t);
         int insertAVL(BiNode *&t, int key, bool &taller); // 插入元素并做平衡处理
         void inOrder(BiNode *p);
         vector<int> v;
     public:
         int sum;
         BST();
         void insertAVL(int key); // 二叉排序树插入元素 
         ~BST();
         void inOrder(); // 中序遍历 
         void input(int n);
         void find(int n);
         
};

// 以p为根的二叉排序树作右旋处理 
void BST::rRotate(BiNode *&p)
{
    BiNode *lc;
	lc = p->lchild;
	p->lchild = lc->rchild;
	lc->rchild = p;
	p = lc;
	return;
}

// 以p为根的二叉排序树作左旋处理 
void BST::lRotate(BiNode *&p)
{
    BiNode *rc;
	rc = p->rchild;
	p->rchild = rc->lchild;
	rc->lchild = p;
	p = rc;
	return;
}

// t为根的二叉排序树作左平衡旋转处理
void BST::leftBalance(BiNode *&t)
{
	//对指针T所致节点为根的二叉树作平衡旋转处理
	BiNode *lc;
	lc = t->lchild;
	//检查T节点的左孩子，根据其平衡因子判断是右旋还是左右双旋
	switch (lc->bf)
	{
		//左孩子的平衡因子为1，平衡因子是直线，右旋
	case LH:
		t->bf = EH;
		lc->bf = EH;
		rRotate(t);
		break;
		//左孩子平衡因子为-1，平衡因子为折线，左右双旋
	case RH:
		BiNode *rd;
		rd = lc->rchild;
		//修改T节点和其左孩子的平衡因子
		switch (rd->bf)
		{
		case LH:
			t->bf = RH;
			lc->bf = EH;
			break;
		case EH:
			t->bf = lc->bf = EH;
			break;
		case RH:
			lc->bf = LH;
			t->bf = EH;
			break;
		}
		rd->bf = EH;
		lRotate(t->lchild);
		rRotate(t);
	}
}

// t为根的二叉排序树作右平衡旋转处理
void BST::rightBalance(BiNode *&t)
{
	//对指针T所致节点为根的二叉树作平衡旋转处理
	BiNode *rc;

	rc = t->rchild;
	//检查T节点的右孩子，根据其平衡因子判断是左旋还是右左双旋
	switch (rc->bf)
	{
		//右孩子的平衡因子为-1，平衡因子是直线，左旋
	case RH:
		t->bf = EH;
		rc->bf = EH;
		lRotate(t);
		break;
		//右孩子平衡因子为-1，平衡因子为折线，右左双旋
	case LH:
		BiNode *ld;
		ld = rc->lchild;
		//修改T节点和其右孩子的平衡因子
		switch (ld->bf)
		{
		case LH:
			t->bf = EH;
			rc->bf = RH;
			break;
		case EH:
			t->bf = rc->bf = EH;
			break;
		case RH:
			t->bf = LH;
			rc->bf = EH;
			break;
		}
		ld->bf = EH;
		rRotate(t->rchild);
		lRotate(t);
	}
}

int BST::insertAVL(BiNode *&t, int key, bool &taller)
{
	if (!t)
	{
		t = new BiNode(key,EH);
		taller = true;
	}
	else
	{
		//树中已存在和e相同的节点，返回0
		if (t->key == key)
		{
			taller = false;
			return 0;
		}
		//继续在左子树中搜索
		if (t->key > key)
		{
			//说明递归插入失败了
			if (!insertAVL(t->lchild, key, taller))
			{
				taller = false;
				return 0;
			}
			//到这里说明插入成功，判断平衡因子
			if (taller)
			{
				switch (t->bf)
				{
					//原本左子树比右子树高，再插入以后，平衡因子变为2，此时需要做左平衡处理
				case LH:
					leftBalance(t);
					taller = false;
					break;
					//原本左右子树,等高，现因左子树增高而使树增高
				case EH:
					taller = true;
					t->bf = LH;
					break;
					//原本右子树比左子树高，现在左右子树登高
				case RH:
					taller = false;
					t->bf = EH;
					break;
				}
			}
		}
		//继续在右子树中搜索
		else
		{
			if (!insertAVL(t->rchild, key , taller))
			{
				taller = false;
				return 0;
			}
			//到这里说明插入成功，判断平衡因子
			if (taller)
			{
				switch (t->bf)
				{
					//原本左子树比右子树高，插入以后，左右等高
				case LH:
					t->bf = EH;
					taller = false;
					break;
					//原本等高，插入以后，右子树等高
				case EH:
					t->bf = RH;
					taller = true;
					break;
					//原本右子树高，插入以后，平衡因子变为-2，需要做右平衡处理
				case RH:
					rightBalance(t);
					taller = false;
					break;
				}
			}
		}
	}
    return 1;
}

// 二叉排序树初始化
BST::BST()
{
    root = NULL;
}

BST::~BST()
{
    root = NULL;
}

// 插入元素并作平衡处理
void BST::insertAVL(int key)
{
    bool taller = false;
    insertAVL(root, key, taller);
}
void BST::input(int n)
{
    v.push_back(n);
}

void BST::find(int n)
{
    sort(v.begin(),v.end());
    if (n>=v.size() or n<0 )
    {
        cout<<"-1\n";
        return;
    }
    else
    {
        cout<<v[n-1]<<endl;
        v.erase(v.begin()+n-1);
        return;
    }
}

int main(void)
{
    int t;
    cin >> t;
    BST tree;
    while(t --)
    {
        int n,elem;
        cin >> n >> elem;
        if(n==1)
        {
           tree.insertAVL(elem);
           tree.input(elem);
        }
        else
        {
            tree.find(elem);
        }
    }
    system("pause");
    return 0;
} 