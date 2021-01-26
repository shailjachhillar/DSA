#include<bits/stdc++.h>
using namespace std;

class BTree{
public:
	int data;
	BTree *lchild;
	BTree *rchild;
};
class tree
{
	private:
		BTree* root;
	public:
		tree();
		void create();
		void PreOrder(BTree* p);
		void PreOrder() { PreOrder(root); } 
};

tree::tree()
{
	root=NULL;
}

void tree::create() 
{
	BTree*p,*t;
	int x;
	queue <BTree*> q;
	root= new BTree;
	cout<<" Enter the root data \n";
	cin>>x;
	root->data=x;
	root->lchild=root->rchild=NULL;
	q.push(root);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		
		cout<<" Enter data of left child of "<<p->data<<" : ";
		cin>>x;
		if(x!=-1)
		{
			t=new BTree;
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->lchild=t;
			q.push(t);
		}
		
		cout<<" Enter data of right child of "<<p->data<<" : ";
		cin>>x;
		if(x!=-1)
		{
			t=new BTree;
			t->data=x;
			t->lchild=t->rchild=NULL;
			p->rchild=t;
			q.push(t);
		}
	}
}

void tree::PreOrder(BTree *p) {
    if (p){
        cout << p->data << ", " ;
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}
int main()
{
	tree b;
	b.create();
	cout<<" \n Traversal = ";
	b.PreOrder();
	return 0;
	
}
