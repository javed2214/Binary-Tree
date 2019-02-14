// Program to Flatten a Binary Tree into Linked List
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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

void inOrder(node *root){
	
	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void flattenTree(node *root){

	if(root==NULL) return;
	if(root->left){
		flattenTree(root->left);
		node *temp=root->right;
		root->right=root->left;
		root->left=NULL;

		node *t=root->right;
		while(t->right!=NULL)
			t=t->right;
		t->right=temp;
	}
	if(root->right) flattenTree(root->right);
}

void printList(node *root){

	while(root!=NULL){
		cout<<root->data<<"=>";
		root=root->right;
	}
	return;
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(5);
	root->left->left=createNode(3);
	root->left->right=createNode(4);
	root->right->right=createNode(6);

	cout<<"Inorder: ";
	inOrder(root);

	cout<<"\nLinked List: ";

	flattenTree(root);
	printList(root);

	return 0;
}