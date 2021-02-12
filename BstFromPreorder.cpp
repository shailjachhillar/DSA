#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		Node* left;
		Node* right;
		int data;
};

class BST{
	private:
		Node*root;
	public:
		BST(){
			root= NULL;
		}
		
		Node* getroot(){
			return root;
		}
		void Inorder(Node* p);
		void createFromPre(int pre[], int n);
};

void BST::Inorder(Node *p){
	if(p){
		Inorder(p->left);
		cout<<p->data<<" ";
		Inorder(p->right);
	}
}


void BST::createFromPre(int *pre, int n){
	
	stack<Node*> st;
	int i=0;
	root=new Node;
	root->data=pre[i++];
	root->left=root->right=NULL;
	Node* temp;
	Node* p=root;
	
	
	while(i<n){
		//it is indeed the left child
		if(pre[i]<p->data){
			temp=new Node;
			temp->data=pre[i++];
			temp->left=temp->right=NULL;
			p->left=temp;
			st.push(p);
			p=temp;
		}
		
		else{
			//it is the right child
//			if(pre[i]>p->data && pre[i]< st.empty()?32767:st.top()->data){
//				temp=new Node;
//				temp->data=pre[i++];
//				temp->left=temp->right=NULL;
//				p->right=temp;
//				p=temp;
//			}
//			else{
//				p=st.top();
//				st.pop();
//			}
			if(st.empty()){
				if(pre[i]>p->data && pre[i]<INT_MAX){
					temp=new Node;
					temp->data=pre[i++];
					temp->left=temp->right=NULL;
					p->right=temp;
					p=temp;
				}
			}
			else{
				if(pre[i]>p->data && pre[i]<st.top()->data){
					temp=new Node;
					temp->data=pre[i++];
					temp->left=temp->right=NULL;
					p->right=temp;
					p=temp;
					
				}
				else{
					p=st.top();
					st.pop();
				}
			}
			
			
			}
		}
	}
	

int main(){
	
	int pre[]={ 30, 20, 10, 15, 25, 40, 50, 45};
	int n=sizeof(pre)/sizeof(int);
	cout<<" BST from preorder : ";
	
	BST b;
	b.createFromPre(pre, n);
	// we know that inorder traversal of a BST gives the sorted order
	// so we are gonna do inorder traversal 
	// and check whether the tree made by us is correct or not
	b.Inorder(b.getroot());
	return 0;
	
}
