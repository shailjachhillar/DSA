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
		
		void insert(int key);
		void inorder(Node*p);
		Node* deleteNode(Node*p, int key);
		Node* InPre(Node* p);
		Node* InSucc(Node* p);
		int findHeight(Node* p);
};


void BST::insert(int key){
	Node* temp = root;
    Node* p,*curr;
 
    if (root == NULL){
        p = new Node;
        p->data = key;
        p->left = NULL;
        p->right = NULL;
        root = p;
        return;
    }
 
    while(temp != NULL){
        curr = temp;
        if (key < temp->data){
            temp = temp->left;
        } else if (key > temp->data){
            temp = temp->right;
        } else {
            return;
        }
    }
 
    p = new Node;
    p->data = key;
    p->left =p->right = NULL;
 
    if (key < curr->data){
        curr->left = p;
    } else {
        curr->right = p;
    }
 
}

void BST::inorder(Node*p){
	if(p){
		inorder(p->left);
		cout<<p->data<<" ";
		inorder(p->right);
	}
}

Node* BST::deleteNode(Node*p, int key){
	Node*temp;
	if(p==NULL){
		return NULL;
	}
	
	if(p->left==NULL && p->right == NULL){
		if(p==root){
			root=NULL;
		}
		delete p;
		return NULL;
	}
	
	if(key<p->data){
		p->left=deleteNode(p->left, key);
	}
	else if(key> p->data){
		p->right=deleteNode(p->right,key);
	}
	else{
		if(findHeight(p->left)>findHeight(p->right)){
			temp=InPre(p->left);
			p->data=temp->data;
			p->left=deleteNode(p->left,temp->data);
		}
		else{
			temp=InSucc(p->right);
			p->data=temp->data;
			p->right=deleteNode(p->right,temp->data);
		}
	}
	
	return p;
}


int BST::findHeight(Node* p){
	int x,y;
	if(p==NULL){
		return 0;
	}
	
	x=findHeight(p->left);
	y=findHeight(p->right);
	if(x>y) return x+1;
	else return y+1;
}

Node* BST::InPre(Node*p){
	while(p&&p->right!=NULL){
		p=p->right;
	}
	return p;
}

Node* BST::InSucc(Node* p){
	while(p && p->left != NULL){
		p=p->left;
	}
	return p;
}

int main(){
	
	BST b;
	
	b.insert(10);
	b.insert(30);
	b.insert(5);
	b.insert(40);
	b.insert(9);
	b.insert(35);
	b.insert(50);
	
	cout<<" Your Tree Contains : ";
	b.inorder(b.getroot());
	b.deleteNode(b.getroot(),40);
	cout<<" After Deletion Tree Contains : ";
	b.inorder(b.getroot());
	
	return 0;
}
