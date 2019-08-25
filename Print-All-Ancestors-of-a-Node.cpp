// Program to Print All the Ancestors of a Node in a Binary Tree
// https://www.geeksforgeeks.org/print-ancestors-of-a-given-node-in-binary-tree/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int x){

	node *temp = (node *)malloc(sizeof(node));
	temp->data = x;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

bool findAncestors(node *root, int k){

	if(root == NULL) return false;
	
	if(root->data == k) return true;
	
	if(findAncestors(root->left,k) or findAncestors(root->right,k)){
		cout<<root->data<<" ";
		return true;
	}
	else return false;
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);
	root->right->right->right = createNode(8);

	int k;
	cin>>k;

	findAncestors(root, k);

	return 0;
}
