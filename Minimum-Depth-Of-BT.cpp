// Program to Find Minimum Depth of a Binary Tree

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

int minDepth(node *root){

	if(root==NULL) return 0;
	if(root->left==NULL and root->right==NULL) return 1;
	if(root->left==NULL) return 1+minDepth(root->right);
	if(root->right==NULL) return 1+minDepth(root->left);
	return 1+min(minDepth(root->left), minDepth(root->right));
}

int main(){

	node *root=createNode(10);
	root->left=createNode(30);
	root->right=createNode(7);
	root->left->left=createNode(-8);
	root->left->right=createNode(-4);
	root->left->right->right=createNode(-2);

	cout<<minDepth(root);

	return 0;
}

