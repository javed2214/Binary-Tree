// Recursive Solution for Zig-Zag Level Order Traversal of Binary Tree

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createTree(node *root, int n){

	if(root==NULL){
		root=(node *)malloc(sizeof(node));
		root->data=n;
		root->left=NULL;
		root->right=NULL;

		return root;
	}
	else if(n < root->data)
		root->left=createTree(root->left,n);
	else if(n > root->data)
		root->right=createTree(root->right,n);

	return root;
}

void inOrder(node *root){

	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

int treeHeight(node *root){

	if(root==NULL) return 0;
	return 1+max(treeHeight(root->left),treeHeight(root->right));
}

void zigZagTraversal(node *root, int h, int flag){

	if(h==0){
		cout<<root->data<<" ";
		return;
	}
	if(flag){
		zigZagTraversal(root->left,h-1,flag);
		zigZagTraversal(root->right,h-1,flag);
	}
	else{
		zigZagTraversal(root->right,h-1,flag);
		zigZagTraversal(root->left,h-1,flag);
	}
}

void zigZagUtil(node *root){

	int h=treeHeight(root);

	int flag=1;
	for(int i=0;i<h;i++){
		zigZagTraversal(root,i,flag);
		flag=!flag;
	}
}

int main(){

	int a[]={30,20,50,10,25,40,60};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;
	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	cout<<"Inorder:\n";
	inOrder(root);

	cout<<"\n\nZig-Zag Level Order:\n";

	zigZagUtil(root);

	return 0;
}