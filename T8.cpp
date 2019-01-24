// Program to Invert Binary Tree

/*
   Input
	 4
   /   \
  2     7		  
 / \   / \
1   3 6   9

	

  Output
 	 4
   /   \
  7     2
 / \   / \
9   6 3   1

*/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(node *, int);
void inOrder(node *);
node *invertTree(node *);

int main(){

	node *root=NULL;
	int a[]={4,2,1,3,7,6,9};
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
		root=createNode(root,a[i]);
	inOrder(root);
	cout<<"\n";
	root=invertTree(root);
	inOrder(root);

	return 0;
}
node *createNode(node *root, int n){

	if(root==NULL){
		node *root=new node;
		root->data=n;
		root->left=NULL;
		root->right=NULL;
		return root;
	}
	else if(n<root->data)
		root->left=createNode(root->left,n);
	else if(n>root->data)
		root->right=createNode(root->right,n);
	return root;
}
void inOrder(node *root){

	if(root==NULL) return;
	else{
		cout<<root->data<<" ";
		inOrder(root->left);
		inOrder(root->right);
	}
}
node *invertTree(node *root){

	if(root==NULL) return NULL;
	else{
		node *temp;
		temp=root->left;
		root->left=root->right;
		root->right=temp;
		invertTree(root->left);
		invertTree(root->right);
	}

	return root;
}
