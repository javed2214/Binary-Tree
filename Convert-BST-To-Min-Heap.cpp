// Program to Convert BST Into Min Heap
// https://www.geeksforgeeks.org/convert-bst-min-heap/

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

void buildVector(node *root, vector<int> &v){

	if(root){
		buildVector(root->left,v);
		v.push_back(root->data);
		buildVector(root->right,v);
	}
}

void convertIntoMinHeap(vector<int> &v, node *root){

	static int i=0;
	if(root){
		root->data=v[i++];
		convertIntoMinHeap(v,root->left);
		convertIntoMinHeap(v,root->right);
	}
}

void preOrder(node *root){

	if(root){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main(){

	node *root=createNode(4);
	root->left=createNode(2);
	root->right=createNode(6);
	root->left->left=createNode(1);
	root->left->right=createNode(3);
	root->right->left=createNode(5);
	root->right->right=createNode(7);

	cout<<"BST: ";
	preOrder(root);

	vector<int> v;
	buildVector(root,v);
	convertIntoMinHeap(v,root);

	cout<<"\nMin Heap: ";
	preOrder(root);

	return 0;
}