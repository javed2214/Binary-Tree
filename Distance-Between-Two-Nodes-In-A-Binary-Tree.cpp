// Program to Find Distance between Two Nodes in a Binary Tree
// https://www.geeksforgeeks.org/find-distance-between-two-nodes-of-a-binary-tree/

// ALGORITHM:
// 1. Find LCA of Both the Nodes
// 2. Add Distances of those Nodes from their LCA

#include<bits/stdc++.h>
using namespace std;

typedef struct node{
	int data;
	struct node *left;
	struct node *right;
}node;

node *createNode(int x){

	node *root = (node *)malloc(sizeof(node));
	root->data = x;
	root->left = NULL;
	root->right = NULL;

	return root;
}

node *LCA(node *root, int x, int y){

	if(root == NULL) return NULL;
	if(root->data == x or root->data == y) return root;
	node *left = LCA(root->left, x, y);
	node *right = LCA(root->right, x, y);
	if(left != NULL and right != NULL) return root;
	else return (left != NULL) ? left : right;
}

int distance(node *root, int x, int level){

	if(root == NULL) return 0;
	if(root->data == x) return level;
	int p = distance(root->left, x, level + 1);
	if(p != 0) return p;
	p = distance(root->right, x, level + 1);
	return p;
}

int main(){

	node *root = createNode(1);
	root->left = createNode(2);
	root->right = createNode(3);
	root->left->left = createNode(4);
	root->left->right = createNode(5);
	root->right->left = createNode(6);
	root->right->right = createNode(7);

	int x,y;
	cin>>x>>y;

	node *lca = LCA(root, x, y);

	int p = distance(lca, x, 0) + distance(lca, y, 0);

	cout<<p;

	return 0;
}