// Program to Find Lowest Common Ancesstor (LCA) of Binary Srarch Tree (BST)
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

	if(root==NULL)
		return NULL;
	else if(n1<root->data and n2<root->data)
		return LCA(root->left,n1,n2);
	else if(n1>root->data and n2>root->data)
		return LCA(root->right,n1,n2);
	return root;
}