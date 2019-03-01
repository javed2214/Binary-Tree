// Print All Nodes of a Binary Tree having K Leaves

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

int kLeaves(node *root, int k){

	if(root==NULL)
		return 0;

	if(root->left==NULL and root->right==NULL)
		return 1;

	int total=kLeaves(root->left,k) + kLeaves(root->right,k);

	if(k==total) cout<<root->data<<" ";

	return total;
}

int main(){

	node *root=createNode(1);
	root->left=createNode(3);
	root->right=createNode(6);
	root->left->left=createNode(5);
	root->left->right=createNode(9);
	root->right->left=createNode(8);

	kLeaves(root,2);

	return 0;
}