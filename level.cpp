#include<bits/stdc++.h>
using namespace std;

class Btree{
	public:
	int data;
	Btree* lchild;
	Btree* rchild;
	
};

class tree{
	private:
		Btree *root;
	public:
		tree();
		void create();
		void LevelOrder(Btree *p);
		void LevelOrder(){
			LevelOrder(root);
		}
};
tree::tree()
{
	root=NULL;
}

void tree::create()
{
	
	Btree*temp,*p;
	int x;
	queue <Btree*> q;
	cout<<"Enter data of root node\n";
	cin>>x;
	root=new Btree;
	root->data=x;
	root->lchild=root->rchild=NULL;
	q.push(root);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		cout<<"Enter Data of left child of "<<p->data<<" ";
		cin>>x;
		if(x!=-1)
		{
			temp=new Btree;
			temp->data=x;
			temp->lchild=temp->rchild=NULL;
			p->lchild=temp;
			q.push(temp);
		}
		
		cout<<"Enter the data of right child of "<<p->data<<" ";
		cin>>x;
		if(x!=-1)
		{
			temp= new Btree;
			temp->data=x;
			temp->lchild=temp->rchild=NULL;
			p->rchild=temp;
			q.push(temp);
		}

	}
	
	
}

void tree::LevelOrder(struct Btree*p)
{
	queue<Btree*> q;
	cout<<p->data;
	q.push(p);
	while(!q.empty())
	{
		p=q.front();
		q.pop();
		if(p->lchild)
		{
			cout<<p->lchild->data<<" , ";
			q.push(p->lchild);
		}
		if(p->rchild)
		{
			cout<<p->rchild->data<<" , ";
			q.push(p->rchild);
		}
	}
}
int main()
{
	tree bt;
	bt.create();
	bt.LevelOrder();
}
