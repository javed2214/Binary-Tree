// Program to Find Sum pf Nodes at Maximum Depth
// https://www.geeksforgeeks.org/sum-of-nodes-at-maximum-depth-of-a-binary-tree-set-2/

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int n){

	node *root=new node;
	root->data=n;
	root->left=NULL;
	root->right=NULL;

	return root;
}

int treeHeight(node *root){

	if(root==NULL) return 0;
	return 1+max(treeHeight(root->left), treeHeight(root->right));
}

void getNodes(node *root, int h, int &sum){

	if(root==NULL) return;
	if(h==0) cout<<root->data<<" ", sum+=root->data;
	getNodes(root->left,h-1,sum);
	getNodes(root->right,h-1,sum);
}

void maxDepth(node *root){

	int h=treeHeight(root);
	int sum=0;
	getNodes(root,h-1,sum);

	cout<<"\nSum: "<<sum;
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);	

	maxDepth(root);

	return 0;
}