// Max Sum From Root to Leaf of a Binary Tree

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

int maxSum(node *root){

	if(root==NULL) return 0;
	return root->data + max(maxSum(root->left), maxSum(root->right));
}

int main(){

	node *root=NULL;
	int a[]={30,10,50,5,20,15,25};
	int n=sizeof(a)/sizeof(int);

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	inOrder(root);
	cout<<"\nMax Sum: ";
	cout<<maxSum(root);

	return 0;
}