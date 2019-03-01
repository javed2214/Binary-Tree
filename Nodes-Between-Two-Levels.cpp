// Program to Print All Nodes Between Two Given Levels of a Binary Tree

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

int Height(node *root){

	if(root==NULL) return 0;
	return 1+max(Height(root->left),Height(root->right));
}

void LevelOrder(node *root, int level){

	if(root==NULL) return;
	if(level==0) cout<<root->data<<" ";
	LevelOrder(root->left, level-1);
	LevelOrder(root->right, level-1);
}

void LOTUtil(node *root, int n1, int n2){

	n1-=1; n2-=1;
	for(int i=n1;i<=n2;i++)
		LevelOrder(root,i);
}

int main(){

	int a[]={30,10,50,5,15,40,60,3,6,12,17,35,43,55,65};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	int n1=2,n2=3;
	LOTUtil(root,n1,n2);

	return 0;
}