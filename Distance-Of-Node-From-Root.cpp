// Program to Find Distance of any Node from Root in Binary Tree

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

int findDistance(node *root, int p, int dis){
	
	if(root==NULL) return 0;
	if(root->data==p) return dis;
	int left=findDistance(root->left,p,dis+1);
	int right=findDistance(root->right,p,dis+1);
	if(left>right) return left;
	else return right;
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
	cout<<"Distance: ";
	cout<<findDistance(root,p,0);

	return 0;

}