// Program to Remove All Leaf Nodes from BST

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}ndoe;

node *removeLeaf(node *root){

	if(root==NULL) return NULL;
	if(root->left==NULL and root->right==NULL){
		free(root);
		return NULL;
	}
	root->left=removeLeaf(root->left);
	root->right=removeLeaf(root->right);

	return root;
}

node *createNode(int n){

	node *root=(node *)malloc(sizeof(node));
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

void preOrder(node *root){

	if(root){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main(){

	node *root=createNode(30);
	root->left=createNode(10);
	root->right=createNode(50);

	cout<<"Orignal BST: ";
	preOrder(root);
	cout<<"\nAfter Removing Leaf Nodes: ";

	root=removeLeaf(root);
	preOrder(root);

	return 0;
}