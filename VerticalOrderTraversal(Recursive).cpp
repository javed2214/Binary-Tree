// Program to Find Vertical Order Traversal of a Binary Tree

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
		root->left=createTree(root->left, n);
	else if(n>root->data)
		root->right=createTree(root->right, n);
}

void printTree(node *root){
	if(root){
		printTree(root->left);
		cout<<root->data<<" ";
		printTree(root->right);
	}
}

void getVerticalOrder(node *root, int hd, map<int,vector<int>>&Map){

	if(root==NULL) return;
	Map[hd].push_back(root->data);
	getVerticalOrder(root->left,hd-1,Map);
	getVerticalOrder(root->right,hd+1,Map);	
}

void printverticalOrder(node *root){
	
	map<int,vector<int>>Map;
	int hd=0;

	getVerticalOrder(root,hd,Map);

	for(auto it:Map){
		for(auto ptr:it.second)
			cout<<ptr<<" ";
		cout<<"\n";
	}
}

int main(){	
	int a[]={20,10,40,5,2,7,15,12,18,30,22,35,50,45,60};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	printTree(root);
	cout<<"\n\nVertical Order: \n";
	printverticalOrder(root);

	return 0;
}
