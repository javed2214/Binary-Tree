// Program to Print Top View of a Binary Tree

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
		root->left=createTree(root->left, n);
	else if(n>root->data)
		root->right=createTree(root->right, n);
	return root;
}

void printTree(node *root){
	if(root){
		printTree(root->left);
		cout<<root->data<<" ";
		printTree(root->right);
	}
}

void topViewLeft(node *root){
	if(!root) return;
	topViewLeft(root->left);
	cout<<root->data<<" ";
}

void topViewRight(node *root){
	if(!root) return;
	cout<<root->data<<" ";
	topViewRight(root->right);
}

void topView(node *root){
	if(!root) return;
	topViewLeft(root->left);
	cout<<root->data<<" ";
	topViewRight(root->right); 
}

int main(){	
	int a[]={1,2,5,6,3,4};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	printTree(root);
	cout<<"\n\nTop View: \n";
	topView(root);

	return 0;
}
