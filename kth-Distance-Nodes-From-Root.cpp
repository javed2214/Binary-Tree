// Program to Find All the Nodes at kth Distance From Root of Binary Tree

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

void inOrder(node *root){
	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

void kthDistance(node *root, int k, int dis){

	if(root==NULL) return;
	if(k==dis){
		cout<<root->data<<" ";
		return;
	}
	kthDistance(root->left,k,dis+1);
	kthDistance(root->right,k,dis+1);
}

/*

void kthDistance(node *root, int k){

	if(root==NULL) return;
	if(k==0){
		cout<<root->data<<" ";
		return;
	}
	kthDistance(root->left,k-1);
	kthDistance(root->right,k-1);
}

*/

int main(){

	node *root=NULL;
	int a[]={20,10,30,5,15,25,40,12,17};
	int n=sizeof(a)/sizeof(int);

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);
	int k=3;
	
	kthDistance(root,k,0);

	return 0;
}
