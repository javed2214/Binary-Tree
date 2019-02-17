// Two nodes of a binary tree are cousins if they have the same depth, but have different parents.
// Program to Find If the Two Nodes are Cousins or Not
// https://leetcode.com/problems/cousins-in-binary-tree/

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
}

void inOrder(node *root){

	if(root){
		inOrder(root->left);
		cout<<root->data<<" ";
		inOrder(root->right);
	}
}

int lev_x, lev_y, par_x, par_y;
void cousinNodes(node *root, int x, int y, int level, node *parent){

	if(root==NULL) return;
	if(root->data==x){
		lev_x=level;
		par_x=parent->data;
	}
	if(root->data==y){
		lev_y=level;
		par_y=parent->data;
	}
	cousinNodes(root->left,x,y,level+1,root);
	cousinNodes(root->right,x,y,level+1,root);
}

int main(){

	int a[]={20,10,30,5,15,25,35};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	inOrder(root);

	cout<<"\n";
	cousinNodes(root,5,25,0,root);

	if(lev_x==lev_y and par_x!=par_y) cout<<"Cousins";
	else cout<<"Not Cousins";

	return 0;

}
