// Program to Print Path Between Two Nodes in a Binary Tree
// https://www.geeksforgeeks.org/print-path-between-any-two-nodes-in-a-binary-tree/

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

node *LCA(node *root, int p, int q){

	if(root==NULL) return NULL;
	if(root->data==p or root->data==q) return root;

	node *left=LCA(root->left,p,q);
	node *right=LCA(root->right,p,q);

	if(left!=NULL and right!=NULL) return root;

	else return (left!=NULL)?left:right;
}

bool storePath(node *root, vector<int> &v, int temp){

	if(root==NULL) return false;
	v.push_back(root->data);
	if(root->data==temp) return true;
	if(storePath(root->left,v,temp) or storePath(root->right,v,temp)) return true;
	v.pop_back();
	return false;
}

void getPath(node *root, int p, int q){

	node *temp=LCA(root,p,q);

	vector<int> v;
	storePath(temp,v,p);
	reverse(v.begin(),v.end());

	for(int i=1;i<v.size();i++) cout<<v[i]<<"->";

	v.clear();
	storePath(temp,v,q);

	for(int i=1;i<v.size();i++) cout<<v[i]<<"->";
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);	

	int p=4,q=7;

	getPath(root,p,q);

	return 0;
}