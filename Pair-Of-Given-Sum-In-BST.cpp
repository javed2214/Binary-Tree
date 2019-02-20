// Program to Find a Pair of Given Sum in BST
// Time Complexity: O(n)

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
	else if(n < root->data)
		root->left=createTree(root->left,n);
	else if(n > root->data)
		root->right=createTree(root->right,n);

	return root;
}

void inOrder(node *root, vector<int> &v){

	if(root){
		inOrder(root->left,v);
		v.push_back(root->data);
		inOrder(root->right,v);
	}
}

int main(){

	int a[]={30,20,50,10,25,40,60};
	int n=sizeof(a)/sizeof(int);
	int sum=35;

	node *root=NULL;
	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	std::vector<int> v;
	inOrder(root,v);

	int l,r;
	l=0;r=v.size()-1;

	while(l<r){

		if(v[l]+v[r]==sum){
			cout<<"("<<v[l]<<","<<v[r]<<")";
			return 0;
		}
		else if(v[l]+v[r] < sum)
			l++;
		else
			r--;
	}
	cout<<"No Element Found!";

	return 0;
}