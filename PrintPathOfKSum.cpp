// Program to Print All the Paths from Root with a Specified Sum in Binary Tree

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

	return root;
}

void printPaths(vector<int>v){
	for(auto it:v) cout<<it<<" ";
		cout<<"\n";
}

void getPaths(node *root, vector<int>v, int target, int sum){

	if(root==NULL) return;
	
	v.push_back(root->data);
	sum+=root->data;
	if(sum==target)
		printPaths(v);

	getPaths(root->left,v,target,sum);
	getPaths(root->right,v,target,sum);
}

int main(){

	int a[]={20,10,5,15,40,25,45};
	int n=sizeof(a)/sizeof(int);
	int target=45;
	
	node *root=NULL;
	
	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);
	
	vector<int> v;
	
	getPaths(root,v,target,0);

	return 0;
}
