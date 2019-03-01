// Sum of All the Numbers Formed From Root to Leaf Paths

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

int sumOfPaths(node *root, int sum){

	if(root==NULL) return 0;

	sum=(sum*10 + root->data);
	
	if(root->left==NULL and root->right==NULL)
		return sum;

	return sumOfPaths(root->left,sum) + sumOfPaths(root->right,sum);
}

int main(){

	node *root=createNode(6);
	root->left=createNode(3);
	root->right=createNode(5);
	root->left->left=createNode(2);
	root->left->right=createNode(5);
	root->right->right=createNode(4);

	cout<<"Total Path Sum: ";
	cout<<sumOfPaths(root,0);

	return 0;
}