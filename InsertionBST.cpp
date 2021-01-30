#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	Node* lchild;
	Node* rchild;
};

struct Node*root=NULL;

void createBST(int x)
{
	
	struct Node* temp,*p;
	temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=x;
	temp->lchild=temp->rchild=NULL;
	if(root==NULL)
	{
		root=temp;
	}
	else
	{
		struct Node* curr;
		curr=root;
		while(curr)
		{
			p=curr;
			if(temp->data>curr->data) curr=curr->rchild;
			else curr=curr->lchild;
			
		}
		
		if(temp->data>p->data) p->rchild=temp;
		else p->lchild=temp;
	}
	
}
//inorder traversal
void traverseBST(struct Node* temp) {
	
	if(temp)
	{
		traverseBST(temp->lchild);
        printf(" %d ",temp->data);
        traverseBST(temp->rchild);
	}
	
}
int main()
{
	createBST(10);
	createBST(5);
	createBST(20);
	createBST(8);
	createBST(11);
	createBST(30);
	traverseBST(root);
}
