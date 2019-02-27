// Iterative Inorder Traversal of a Bianary Tree Using Stack

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *newNode(int n){

	node *root=new node;
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

void iterativeInorder(node *root){

	if(root==NULL) return;

	stack<node *> S;
	node *p=root;

	while(p!=NULL or !S.empty()){

		while(p!=NULL){
			S.push(p);
			p=p->left;
		}
		p=S.top();
		cout<<p->data<<" ";
		S.pop();

		p=p->right;
	}
}

int main(){

	node *root=newNode(1); 
    root->left=newNode(2); 
    root->right=newNode(3); 
    root->left->left=newNode(4); 
    root->left->right=newNode(5); 

    iterativeInorder(root);

    return 0;
}

