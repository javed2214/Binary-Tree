// Program to Find Inorder Predecessor of any Node in BST

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createTree(node *root, int n){
	if(root==NULL){
		root=(node *)malloc(sizeof(node));
		root->data=n;
		root->left=NULL;
		root->right=NULL;

		return root;
	}
	else if(n<root->data)
		root->left=createTree(root->left,n);
	else if(n>root->data)
		root->right=createTree(root->right,n);
}

void inOrder(node *root){
	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

node *searchNode(node *root, int p){

	if(root==NULL) return NULL;
	if(p==root->data)
		return root;
	if(p<root->data)
		searchNode(root->left,p);
	else if(p>root->data)
		searchNode(root->right,p);
}

node *maxNode(node *p){
	
	while(p->right!=NULL){
		p=p->right;
	}
	return p;
}

node *inOrderPredecessor(node *root, int p){

	node *x=searchNode(root,p);
	if(x->left!=NULL){
		node *t=maxNode(x->left);
		return t;
	}
	node *r=root, *store;
	while(x->data!=r->data){
		if(x->data>r->data){
			store=r;
			r=r->right;
		}
		else r=r->left;
	}
	return store;
}

int main(){

	node *root=NULL;
	int a[]={20,10,30,5,15,25,40,12,17};
	int n=sizeof(a)/sizeof(int);

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);
	int p;
	inOrder(root);
	cout<<"\nInorder Predecessor of Which Node: ";
	cin>>p;
	node *k=inOrderPredecessor(root,p);
	cout<<k->data;

	return 0;
}
