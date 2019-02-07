// Program to Find Lowest Common Ancestor (LCA) of Binary Tree
// Recursive Approach

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *, int);
void inOrder(node *);
node *LCA(node *, int, int);

int main(){

	node *root=NULL;
	int a[]={20,10,5,15,30,25,40};
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
		root=createNode(root,a[i]);
	inOrder(root);
	cout<<"\n";
	root=LCA(root,15,5);
	cout<<"LCA: "<<root->data;

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
}
void inOrder(node *root){

	if(root==NULL) return;
	else{
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}
node *LCA(node *root, int n1, int n2){

	if(root==NULL) return NULL;
	if(root->data==n1 or root->data==n2)
		return root;
	node *left=LCA(root->left,n1,n2);
	node *right=LCA(root->right,n1,n2);

	if(left!=NULL and right!=NULL)
		return root;
	else
		return (left!=NULL)?left:right;
}
