// Program to Print All the Paths from Root to Leaves

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

void preOrder(node *root){
	if(root){
		cout<<root->data<<" ";
		preOrder(root->left);
		preOrder(root->right);
	}
}

void printVector(std::vector<int> &v){
	for(auto it:v) cout<<it<<" ";
		cout<<"\n";
	return;
}

void printRootToLeaves(node *root, std::vector<int> v){
	if(root==NULL)
		return;
	v.push_back(root->data);
	if(root->left==NULL and root->right==NULL)
		printVector(v);
	else{
		printRootToLeaves(root->left,v);
		printRootToLeaves(root->right,v);
	}
}

int main(){
	node *root=NULL;
	int a[]={5,2,1,4,10,7,12};
	int n=sizeof(a)/sizeof(int);
	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);
	cout<<"PreOrder: ";
	preOrder(root);
	cout<<"\n";
	vector<int>v;
	printRootToLeaves(root,v);


	return 0;
}