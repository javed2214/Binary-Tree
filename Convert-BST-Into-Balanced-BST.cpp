// Program to Convert Normal BST Into Balanced BST
// https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/

// Algorithm =>
// 1. Store Inorder Traversal of Normal BST into a Vector
// 2. Use that Sorted Vector to Build Balanced BST Recursively

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

void buildVector(node *root, vector<node *> &v){

	if(root){
		buildVector(root->left,v);
		v.push_back(root);
		buildVector(root->right,v);
	}
}

node *buildTree(vector<node *> &v, int l, int r){

	if(l>r) return NULL;

	int mid=(l+r)/2;
	node *root=v[mid];
	root->left=buildTree(v,l,mid-1);
	root->right=buildTree(v,mid+1,r);

	return root;
}

void preOrder(node *root){

	if(root){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main(){

	node *root=createNode(10);
	root->left=createNode(8);
	root->left->left=createNode(7);
	root->left->left->left=createNode(6);
	root->left->left->left->left=createNode(5);

	cout<<"Normal Tree: ";
	preOrder(root);
	vector<node *> v;
	buildVector(root,v);
	cout<<"\n";
	int siz=v.size()-1;

	cout<<"Balanced Tree: ";
	root=buildTree(v,0,siz);
	preOrder(root);

	return 0;
}


