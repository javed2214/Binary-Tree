// Program to Delete Whole Binary Tree

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *temp=(node *)malloc(sizeof(node));
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

void deleteTree(node *root){

	if(root==NULL) return;
	deleteTree(root->left);
	deleteTree(root->right);
	free(root);
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);

	deleteTree(root);
	cout<<"Tree Deleted!";

	return 0;
}