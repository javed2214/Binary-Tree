// Given a binary tree, write a function that returns true if the tree satisfies below property.
// For every node, data value must be equal to sum of data values in left and right children. Consider data value as 0 for NULL children.

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *temp=(node*)malloc(sizeof(node));
	temp->data=n;
	temp->left=NULL;
	temp->right=NULL;

	return temp;
}

bool childrenSum(node *root){

	int l=0,r=0;

	if(root==NULL or (root->left==NULL and root->right==NULL))
		return true;
	else{
			
		if(root->left!=NULL)   l=root->left->data;
		if(root->right!=NULL)  r=root->right->data;

		if((root->data==l+r) and childrenSum(root->left) and childrenSum(root->right))
			return true;
		else
			return false;
	}
}

int main(){	

	node *root=createNode(10);
	root->left=createNode(8);
	root->right=createNode(2);
	root->left->left=createNode(3);
	root->left->right=createNode(5);
	root->right->right=createNode(2);

	if(childrenSum(root)) cout<<"Yes!";
	else cout<<"No!";

	return 0;
}