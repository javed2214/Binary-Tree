// Program to Print all Internal Nodes of Binary Tree

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

void internalNodes(node* root){

	if(root){
		internalNodes(root->left);
		if(!(root->left==NULL and root->right==NULL))
			cout<<root->data<<" ";
		internalNodes(root->right);
	}
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);

	internalNodes(root);

	return 0;
}