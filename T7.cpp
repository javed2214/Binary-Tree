// Program to Find Inorder Successor of any Node in BST

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *, int);
void inOrder(node *);
node *searchNode(node *root, int);
node *inorderSuccessor(node *, int);

int main(){

	node *root=NULL;
	int a[]={20,10,5,15,30,25,40,12,13,18};
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
		root=createNode(root,a[i]);
	inOrder(root);
	cout<<"\n";
	root=inorderSuccessor(root,18);
	cout<<root->data;

	return 0;
}
node *createNode(node *root, int n){

	if(root==NULL){
		node *root=new node;
		root->data=n;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else if(n<root->data)
		root->left=createNode(root->left,n);
	else if(n>root->data)
		root->right=createNode(root->right,n);
	return root;
}
void inOrder(node *root){

	if(root==NULL) return;
	else{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}
node *searchNode(node *root, int n){

	if(root==NULL) return NULL;
	if(root){
		if(n<root->data)
			return searchNode(root->left,n);
		else if(n>root->data)
			return searchNode(root->right,n);
	}
	return root;
}
node *inorderSuccessor(node *root, int nx){

	// If Right Subtree is Not NULL
	node *n=searchNode(root,nx);
	node *p;
	if(n->right!=NULL){
		p=n->right;
		while(p->left!=NULL)
			p=p->left;
		return p;
	}
	// If Right Subtree is NULL
	node *succ=NULL;
	while(root!=NULL){
		if(n->data<root->data){
			succ=root;
			root=root->left;
		}
		else if(n->data>root->data)
			root=root->right;
		else
			break;
	}
	return succ;
}