// Binary Tree Pruning
// https://leetcode.com/problems/binary-tree-pruning/

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


node *prune(node *root){

	if(!root) return NULL;
	root->left = prune(root->left);
	root->right = prune(root->right);
	if(root->data == 0 and !root->left and !root->right) return NULL;
	return root;
}

void inorder(node *root){

	if(root){
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}

int main(){

	node *root = createNode(1);
	root->right = createNode(0);
	root->right->left = createNode(0);
	root->right->right = createNode(1);

	prune(root);

	inorder(root);

	// if(check(root)) cout<<"Yes";
	// else cout<<"No";

	return 0;
}