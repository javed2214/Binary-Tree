// Program to Convert BST Into Max Heap
// https://www.geeksforgeeks.org/convert-bst-to-max-heap/

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

void convertIntoMaxHeap(vector<int> &v, node *root){

	static int i=0;
	if(root){
		convertIntoMaxHeap(v,root->left);
		convertIntoMaxHeap(v,root->right);
		root->data=v[i++];
	}
}

void postOrder(node *root){

	if(root){
		postOrder(root->left);
		postOrder(root->right);
		cout<<root->data<<" ";
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
	postOrder(root);

	vector<int> v;
	buildVector(root,v);
	convertIntoMaxHeap(v,root);

	cout<<"\nMax Heap (PostOrder): ";
	postOrder(root);

	return 0;
}