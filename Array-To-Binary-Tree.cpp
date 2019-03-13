// Program to Convert an Array into Binary Tree
// Left Child  : arr[2i+1]
// Right Child : arr[2i+2]

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

node *arrayToBT(int *a, node *root, int i, int n){

	if(i<n){

		node *temp=createNode(a[i]);
		root=temp;

		root->left=arrayToBT(a, root->left, 2*i+1, n);
		root->right=arrayToBT(a, root->right, 2*i+2, n);
	}
	return root;
}

void inOrder(node *root){

	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

int main(){

	int a[]={1,2,3,4,5,6};
	int n=sizeof(a)/sizeof(int);

	node *root=arrayToBT(a,root,0,n);
	inOrder(root);

	return 0;
}