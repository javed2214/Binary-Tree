// Program to Find Maximum Level Sum in a Binary Tree

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
	else if(n<root->data)
		root->left=createTree(root->left,n);
	else if(n>root->data)
		root->right=createTree(root->right,n);
}

int height(node *root){

	if(root==NULL) return 0;
	return 1+max(height(root->left),height(root->right));
}

int printlevelOrder(node *root, int level){

	if(root==NULL) return 0;
	if(level==0) return root->data;
	return printlevelOrder(root->left,level-1) + printlevelOrder(root->right,level-1);
}

int levelOrder(node *root){

	int h=height(root);
	int mx=INT_MIN,p;
	for(int i=0;i<h;i++){
		p=printlevelOrder(root,i);
		mx=max(mx,p);
	}
	return mx;
}

int main(){

	node *root=NULL;
	int a[]={20,10,30,5,15,25,40,12,17};
	int n=sizeof(a)/sizeof(int);

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);
	
	cout<<levelOrder(root);

	return 0;
}


