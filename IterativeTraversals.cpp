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
		void iterativePreorder(Btree* p);
   		void iterativePreorder() { iterativePreorder(root); }
   		void iterativeInorder(Btree* p);
	    void iterativeInorder() { iterativeInorder(root); }
	    void iterativePostorder(Btree* p);
	    void iterativePostorder() { iterativePostorder(root); }
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

void tree::iterativePreorder(Btree*p)
{
	stack<Btree*>st;
	while(p!=NULL || !st.empty())
	{
		if(p!=NULL)
		{
			cout<<p->data<<" ";
			st.push(p);
			p=p->lchild;
			
			
		}
		else
		{
			p=st.top();
			st.pop();
			p=p->rchild;
		}
	}
}

void tree::iterativeInorder(Btree*p)
{
	stack<Btree*> st;
	while(p!=NULL || !st.empty())
	{
		if(p!=NULL)
		{
			st.push(p);
			p=p->lchild;
		}
		else
		{
			p=st.top();
			st.pop();
			cout<<p->data<<" ";
			p=p->rchild;
		}
	}
}

void tree::iterativePostorder(Btree*p)
{
	stack<long int> st;
    long int temp;
    while (p != NULL || ! st.empty()){
        if (p != NULL){
            st.push((long int)p);
            p = p->lchild;
        } else {
            temp = st.top();
            st.pop();
            if (temp > 0){
                st.push(-temp);
                p = ((Btree*)temp)->rchild;
            } else {
                cout << ((Btree*)(-1 * temp))->data << " ";
                p = NULL;
            }
        }
}
}
int main()
{
	tree bt;
	bt.create();
	cout<<" Iterative Preorder Traversal : ";
	bt.iterativePreorder();
	cout<<endl;
	cout<<" Iterative Inorder Traversal : ";
	bt.iterativeInorder();
	cout<<endl;
	cout<<" Iterative Postorder Traversal : ";
	bt.iterativePostorder();
}
