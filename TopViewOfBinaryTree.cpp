// Program to Print Top View of a Binary Tree

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

void TopView(node *root){

	if(root==NULL) return;

	queue<pair<node*,int>>q;
	map<int,int>Map;
	q.push(make_pair(root,0));
	while(!q.empty()){
		pair<node*,int>temp=q.front();
		node *p=temp.first;
		int hd=temp.second;
		q.pop();
		if(Map.find(hd)==Map.end()){
			Map[hd]=p->data;
			cout<<p->data<<" ";
		}
		if(p->left!=NULL)
			q.push(make_pair(p->left,hd-1));
		if(p->right!=NULL)
			q.push(make_pair(p->right,hd+1));
	}
}

int main(){	
	int a[]={20,10,40,5,2,15,30,50,22,35,36,37};
	int n=sizeof(a)/sizeof(int);

	node *root=NULL;

	for(int i=0;i<n;i++)
		root=createTree(root,a[i]);

	printTree(root);
	cout<<"\n\nTop View: \n";
	TopView(root);

	return 0;
}
