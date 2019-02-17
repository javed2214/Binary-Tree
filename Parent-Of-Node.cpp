// Program to Find Parent of any Node in Binary Tree

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

void findParent(node *root, int x, node *p, int &parent){

	if(root==NULL) return;
	if(root->data==x)
		parent=p->data;

	findParent(root->left,x,root,parent);
	findParent(root->right,x,root,parent);
}

int main(){

	int a[]={20,10,30,5,15,25,35};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	inOrder(root);

	int p;
	cout<<"\nEnter Node: ";
	cin>>p;
	cout<<"Parent: ";
	int pp;
	findParent(root,p,root,pp);
	cout<<pp;

	return 0;

}