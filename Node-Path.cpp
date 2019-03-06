// Print Path from Root to a Given Node in a Binary Tree
// https://www.geeksforgeeks.org/print-path-root-given-node-binary-tree/
// BackTracking Application

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

bool findPath(node *root, int k, std::vector<int> &v){

	if(root==NULL) return false;
	v.push_back(root->data);
	if(root->data==k) return true;
	if(findPath(root->left,k,v) or findPath(root->right,k,v)) return true;
	v.pop_back();
	return false;
}

int main(){

	node *root=createNode(1);
	root->left=createNode(2);
	root->right=createNode(3);
	root->left->left=createNode(4);
	root->left->right=createNode(5);
	root->right->left=createNode(6);
	root->right->right=createNode(7);
	root->left->left->left=createNode(8);
	root->left->left->right=createNode(9);
	root->right->left->left=createNode(10);
	root->right->left->right=createNode(11);
	root->right->right->right=createNode(12);

	int k;
	cin>>k;
	std::vector<int> v;
	if(findPath(root,k,v)){
		for(auto it: v) cout<<it<<" ";
	}
	else cout<<"Node Not Found!";

	return 0;
}